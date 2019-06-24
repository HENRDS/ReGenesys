/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:49
 */

#include "Delay.h"
#include "Model.h"
#include "Attribute.h"

Delay::Delay(Model* model) : ModelComponent(model, Util::TypeOf<Delay>()) {
    //_name = "Delay " + std::to_string(Util::GenerateNewIdOfType<Delay>());
}

Delay::Delay(const Delay& orig) : ModelComponent(orig) {
}

Delay::~Delay() {
}

std::string Delay::show() {
    return ModelComponent::show() +
	    ",delayExpression=" + this->_delayExpression +
	    ",timeUnit=" + std::to_string(static_cast<int> (this->_delayTimeUnit));
}

ModelComponent* Delay::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Delay* newComponent = new Delay(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void Delay::setDelayExpression(std::string _delayExpression) {
    this->_delayExpression = _delayExpression;
}

std::string Delay::getDelayExpression() const {
    return _delayExpression;
}

void Delay::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
    this->_delayTimeUnit = _delayTimeUnit;
}

Util::TimeUnit Delay::getDelayTimeUnit() const {
    return _delayTimeUnit;
}

void Delay::_execute(Entity* entity) {
    double waitTime = _model->parseExpression(_delayExpression) * Util::TimeUnitConvert(_delayTimeUnit, _model->getInfos()->getReplicationLengthTimeUnit());
    entity->getEntityType()->getCstatWaitingTime()->getStatistics()->getCollector()->addValue(waitTime);
    entity->setAttributeValue("Entity.WaitTime", entity->getAttributeValue("Entity.WaitTime") + waitTime);
    double delayEndTime = _model->getSimulation()->getSimulatedTime() + waitTime;
    Event* newEvent = new Event(delayEndTime, entity, this->getNextComponents()->front());
    _model->getEvents()->insert(newEvent);
    _model->getTraceManager()->trace(Util::TraceLevel::blockInternal, "End of delay of entity " + std::to_string(entity->getId()) + " scheduled to time " + std::to_string(delayEndTime));
}

bool Delay::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	this->_delayExpression = (*fields->find("delayExpression")).second;
	this->_delayTimeUnit = static_cast<Util::TimeUnit> (std::stoi((*fields->find("delayExpressionTimeUnit")).second));
    }
    return res;
}

void Delay::_initBetweenReplications() {
}

std::map<std::string, std::string>* Delay::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Delay>());
    fields->emplace("delayExpression", this->_delayExpression);
    fields->emplace("delayExpressionTimeUnit", std::to_string(static_cast<int> (this->_delayTimeUnit)));
    return fields;
}

bool Delay::_check(std::string* errorMessage) {
    //include attributes needed
    ElementManager* elements = _model->getElementManager();
    std::vector<std::string> neededNames = {"Entity.WaitTime"};
    std::string neededName;
    for (unsigned int i = 0; i < neededNames.size(); i++) {
	neededName = neededNames[i];
	if (elements->getElement(Util::TypeOf<Attribute>(), neededName) == nullptr) {
	    Attribute* attr1 = new Attribute(neededName);
	    elements->insert(Util::TypeOf<Attribute>(), attr1);
	}
    }
    return _model->checkExpression(_delayExpression, "Delay expression", errorMessage);
}

PluginInformation* Delay::GetPluginInformation(){
    return new PluginInformation(Util::TypeOf<Delay>(), &Delay::LoadInstance);
}
