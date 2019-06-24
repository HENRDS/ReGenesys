/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Release.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Release.h"
#include "Model.h"
#include "WaitingResource.h"
#include "Resource.h"
#include "Attribute.h"
#include <assert.h>

Release::Release(Model* model) : ModelComponent(model, Util::TypeOf<Release>()) {
}

Release::Release(const Release& orig) : ModelComponent(orig) {
}

Release::~Release() {
}

std::string Release::show() {
    return ModelComponent::show() +
	    ",resourceType=" + std::to_string(static_cast<int> (this->_resourceType)) +
	    ",resource=\"" + this->_resource->getName() + "\"" +
	    ",quantity=" + this->_quantity;
}

void Release::setPriority(unsigned short _priority) {
    this->_priority = _priority;
}

unsigned short Release::getPriority() const {
    return _priority;
}

void Release::setResourceType(Resource::ResourceType _resourceType) {
    this->_resourceType = _resourceType;
}

Resource::ResourceType Release::getResourceType() const {
    return _resourceType;
}

void Release::setQuantity(std::string _quantity) {
    this->_quantity = _quantity;
}

std::string Release::getQuantity() const {
    return _quantity;
}

void Release::setRule(Resource::ResourceRule _rule) {
    this->_rule = _rule;
}

Resource::ResourceRule Release::getRule() const {
    return _rule;
}

void Release::setSaveAttribute(std::string _saveAttribute) {
    this->_saveAttribute = _saveAttribute;
}

std::string Release::getSaveAttribute() const {
    return _saveAttribute;
}

void Release::setResource(Resource* _resource) {
    this->_resource = _resource;
}

Resource* Release::getResource() const {
    return _resource;
}

void Release::_execute(Entity* entity) {
    Resource* resource = nullptr;
    if (this->_resourceType == Resource::ResourceType::SET) {
	/* TODO +: not implemented yet */
    } else {
	resource = this->_resource;
    }
    unsigned int quantity = _model->parseExpression(this->_quantity);
    assert(_resource->getNumberBusy() >= quantity);
    _model->getTraceManager()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Entity frees " + std::to_string(quantity) + " units of resource \"" + resource->getName() + "\" seized on time " + std::to_string(_resource->getLastTimeSeized()));
    _resource->release(quantity, _model->getSimulation()->getSimulatedTime()); //{releases and sets the 'LastTimeSeized'property}
    _model->sendEntityToComponent(entity, this->getNextComponents()->front(), 0.0);
}

void Release::_initBetweenReplications() {
    this->_resource->initBetweenReplications();
}

bool Release::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	this->_priority = std::stoi((*(fields->find("priority"))).second);
	this->_quantity = ((*(fields->find("quantity"))).second);
	this->_resourceType = static_cast<Resource::ResourceType> (std::stoi((*(fields->find("resourceType"))).second));
	this->_rule = static_cast<Resource::ResourceRule> (std::stoi((*(fields->find("rule"))).second));
	this->_saveAttribute = ((*(fields->find("saveAttribute"))).second);
	//Util::identitifcation resourceId = std::stoi((*(fields->find("resourceId"))).second);
	//Resource* res = dynamic_cast<Resource*> (_model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceId));
	std::string resourceName = ((*(fields->find("resourceName"))).second);
	Resource* res = dynamic_cast<Resource*> (_model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceName));
	this->_resource = res;
    }
    return res;
}

std::map<std::string, std::string>* Release::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Release>());
    fields->emplace("priority", std::to_string(this->_priority));
    fields->emplace("quantity", this->_quantity);
    fields->emplace("resourceType", std::to_string(static_cast<int> (this->_resourceType)));
    fields->emplace("resourceId", std::to_string(this->_resource->getId()));
    fields->emplace("resourceName", (this->_resource->getName()));
    fields->emplace("rule", std::to_string(static_cast<int> (this->_rule)));
    fields->emplace("saveAttribute", this->_saveAttribute);
    return fields;

}

bool Release::_check(std::string* errorMessage) {
    bool resultAll = true;
    resultAll &= _model->checkExpression(_quantity, "quantity", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<Resource>(), _resource, "resource", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<Attribute>(), _saveAttribute, "SaveAttribute", false, errorMessage);
    return resultAll;
}

void Release::setResourceName(std::string resourceName) throw () {
    ModelElement* resource = _model->getElementManager()->getElement(Util::TypeOf<Resource>(), resourceName);
    if (resource != nullptr) {
	this->_resource = dynamic_cast<Resource*> (resource);
    } else {
	throw std::invalid_argument("Resource does not exist");
    }
}

std::string Release::getResourceName() const {
    return _resource->getName();
}

PluginInformation* Release::GetPluginInformation() {
    return new PluginInformation(Util::TypeOf<Release>(), &Release::LoadInstance);
}

ModelComponent* Release::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Release* newComponent = new Release(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;

}
