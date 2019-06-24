/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seize.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Seize.h"
#include "WaitingResource.h"
#include "Resource.h"
#include "Attribute.h"

Seize::Seize(Model* model) : ModelComponent(model, Util::TypeOf<Seize>()) {
}

Seize::Seize(const Seize& orig) : ModelComponent(orig) {
}

std::string Seize::show() {
    return ModelComponent::show() +
	    ",resourceType=" + std::to_string(static_cast<int> (this->_resourceType)) +
	    ",resource=\"" + this->_resource->getName() + "\"" +
	    ",quantity=" + this->_quantity;
}

void Seize::setLastMemberSeized(unsigned int _lastMemberSeized) {
    this->_lastMemberSeized = _lastMemberSeized;
}

unsigned int Seize::getLastMemberSeized() const {
    return _lastMemberSeized;
}

void Seize::setSaveAttribute(std::string _saveAttribute) {
    this->_saveAttribute = _saveAttribute;
}

std::string Seize::getSaveAttribute() const {
    return _saveAttribute;
}

void Seize::setRule(Resource::ResourceRule _rule) {
    this->_rule = _rule;
}

Resource::ResourceRule Seize::getRule() const {
    return _rule;
}

void Seize::setQuantity(std::string _quantity) {
    this->_quantity = _quantity;
}

std::string Seize::getQuantity() const {
    return _quantity;
}

void Seize::setResourceType(Resource::ResourceType _resourceType) {
    this->_resourceType = _resourceType;
}

Resource::ResourceType Seize::getResourceType() const {
    return _resourceType;
}

void Seize::setPriority(unsigned short _priority) {
    this->_priority = _priority;
}

unsigned short Seize::getPriority() const {
    return _priority;
}

void Seize::setAllocationType(unsigned int _allocationType) {
    this->_allocationType = _allocationType;
}

unsigned int Seize::getAllocationType() const {
    return _allocationType;
}

void Seize::setQueueName(std::string queueName) throw () {
    Queue* queue = dynamic_cast<Queue*> (_model->getElementManager()->getElement(Util::TypeOf<Queue>(), queueName));
    if (queue != nullptr) {
	_queue = queue;
    } else {
	throw std::invalid_argument("Queue does not exist");
    }
}

void Seize::_handlerForResourceEvent(Resource* resource) {
    Waiting* first = _queue->first();
    if (first != nullptr) { // there are entities waiting in the queue
	unsigned int quantity = _model->parseExpression(this->_quantity);
	if ((resource->getCapacity() - resource->getNumberBusy()) >= quantity) { //enought quantity to seize
	    double tnow = _model->getSimulation()->getSimulatedTime();
	    resource->seize(quantity, tnow);
	    _model->getEvents()->insert(new Event(tnow, first->getEntity(), this->getNextComponents()->front()));
	    _queue->removeElement(first, tnow);
	    _model->getTraceManager()->traceSimulation(Util::TraceLevel::blockInternal, tnow, first->getEntity(), this, "Waiting entity " + std::to_string(first->getEntity()->getId()) + " now seizes " + std::to_string(quantity) + " elements of resource \"" + resource->getName() + "\"");

	}
    }
}

void Seize::setResourceName(std::string resourceName) throw () {
    Resource* resource = dynamic_cast<Resource*> (_model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceName));
    if (resource != nullptr) {
	_resource = resource;
    } else {
	throw std::invalid_argument("Resource does not exist");
    }
}

std::string Seize::getResourceName() const {
    return _resource->getName();
}

std::string Seize::getQueueName() const {
    return _queue->getName();
}

void Seize::setResource(Resource* resource) {
    this->_resource = resource;
    _resource->addResourceEventHandler(Resource::SetResourceEventHandler<Seize>(&Seize::_handlerForResourceEvent, this));
}

Resource* Seize::getResource() const {
    return _resource;
}

void Seize::setQueue(Queue* queue) {
    this->_queue = queue;
}

Queue* Seize::getQueue() const {
    return _queue;
}

Seize::~Seize() {
}

void Seize::_execute(Entity* entity) {
    /* TODO +: not implemented yet */
    Resource* resource = nullptr;
    if (this->_resourceType == Resource::ResourceType::SET) {
	/* TODO +: not implemented yet */
    } else {
	resource = this->_resource;
    }
    unsigned int quantity = _model->parseExpression(this->_quantity);
    if (resource->getCapacity() - resource->getNumberBusy() < quantity) { // not enought free quantity to allocate. Entity goes to the queue
	WaitingResource* waitingRec = new WaitingResource(entity, this, _model->getSimulation()->getSimulatedTime(), quantity);
	this->_queue->insertElement(waitingRec); // ->getList()->insert(waitingRec);
	_model->getTraceManager()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Entity starts to wait for resource in queue \"" + _queue->getName() + "\" with " + std::to_string(_queue->size()) + " elements");

    } else { // alocate the resource
	_model->getTraceManager()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Entity seizes " + std::to_string(quantity) + " elements of resource \"" + resource->getName() + "\"");
	resource->seize(quantity, _model->getSimulation()->getSimulatedTime());
	_model->sendEntityToComponent(entity, this->getNextComponents()->front(), 0.0);
    }
}

void Seize::_initBetweenReplications() {
    this->_lastMemberSeized = 0;
    this->_queue->initBetweenReplication();
    this->_resource->initBetweenReplications();
}

bool Seize::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	this->_allocationType = std::stoi((*(fields->find("allocationType"))).second);
	this->_priority = std::stoi((*(fields->find("priority"))).second);
	this->_quantity = ((*(fields->find("quantity"))).second);
	this->_resourceType = static_cast<Resource::ResourceType> (std::stoi((*(fields->find("resourceType"))).second));
	this->_rule = static_cast<Resource::ResourceRule> (std::stoi((*(fields->find("rule"))).second));
	this->_saveAttribute = ((*(fields->find("saveAttribute"))).second);
	//Util::identitifcation queueId = std::stoi((*(fields->find("queueId"))).second);
	//Queue* queue = dynamic_cast<Queue*> (_model->getElementManager()->getElement(Util::TypeOf<Queue>(), queueId));
	std::string queueName = ((*(fields->find("queueName"))).second);
	Queue* queue = dynamic_cast<Queue*> (_model->getElementManager()->getElement(Util::TypeOf<Queue>(), queueName));
	this->_queue = queue;
	//Util::identitifcation resourceId = std::stoi((*(fields->find("resourceId"))).second);
	//Resource* resource = dynamic_cast<Resource*> (_model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceId));
	std::string resourceName = ((*(fields->find("resourceName"))).second);
	Resource* resource = dynamic_cast<Resource*> (_model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceName));
	this->_resource = resource;
	_resource->addResourceEventHandler(Resource::SetResourceEventHandler<Seize>(&Seize::_handlerForResourceEvent, this));

    }
    return res;
}

std::map<std::string, std::string>* Seize::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Seize>());
    fields->emplace("allocationType", std::to_string(this->_allocationType));
    fields->emplace("priority=", std::to_string(this->_priority));
    fields->emplace("quantity", this->_quantity);
    fields->emplace("queueId", std::to_string(this->_queue->getId()));
    fields->emplace("queueName", (this->_queue->getName()));
    fields->emplace("resourceType", std::to_string(static_cast<int> (this->_resourceType)));
    fields->emplace("resourceId", std::to_string(this->_resource->getId()));
    fields->emplace("resourceName", (this->_resource->getName()));
    fields->emplace("rule", std::to_string(static_cast<int> (this->_rule)));
    fields->emplace("saveAttribute", this->_saveAttribute);
    return fields;
}

bool Seize::_check(std::string* errorMessage) {
    bool resultAll = true;
    resultAll &= _model->checkExpression(_quantity, "quantity", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<Resource>(), _resource, "Resource", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<Queue>(), _queue, "Queue", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<Attribute>(), _saveAttribute, "SaveAttribute", false, errorMessage);
    return resultAll;
}

PluginInformation* Seize::GetPluginInformation() {
    return new PluginInformation(Util::TypeOf<Seize>(), &Seize::LoadInstance);
}

ModelComponent* Seize::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Seize* newComponent = new Seize(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;

}

