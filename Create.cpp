/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Create.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 20:12
 */

#include "Create.h"
#include "Model.h"
#include "EntityType.h"
#include "ElementManager.h"
#include "Attribute.h"
#include "Assign.h"

Create::Create(Model* model) : SourceModelComponent(model, Util::TypeOf<Create>()) {
    _numberOut = new Counter("Count number Out", this);
    _model->getElementManager()->insert(Util::TypeOf<Counter>(), _numberOut);
    model->getControls()->insert(new SimulationControl(Util::TypeOf<Create>(), "Entities Per Creation",
	    DefineGetterMember<SourceModelComponent>(this, &Create::getEntitiesPerCreation),
	    DefineSetterMember<SourceModelComponent>(this, &Create::setEntitiesPerCreation))
	    );
    /*
    model->getControls()->insert(new SimulationControl(Util::TypeOf<Create>(), "Time Between Creations",
	    DefineGetterMember<SourceModelComponent>(this, &Create::getTimeBetweenCreationsExpression),
	    DefineSetterMember<SourceModelComponent>(this, &Create::setTimeBetweenCreationsExpression))
	    );
     */
}

Create::Create(const Create& orig) : SourceModelComponent(orig) {
}

Create::~Create() {
}

std::string Create::show() {
    return SourceModelComponent::show();
}

void Create::_execute(Entity* entity) {
    double tnow = _model->getSimulation()->getSimulatedTime();
    entity->setAttributeValue("Entity.ArrivalTime", tnow); // ->find("Entity.ArrivalTime")->second->setValue(tnow);
    //entity->setAttributeValue("Entity.Picture", 1); // ->find("Entity.ArrivalTime")->second->setValue(tnow);
    double timeBetweenCreations, timeScale, newArrivalTime;
    unsigned int _maxCreations = _model->parseExpression(this->_maxCreationsExpression);
    for (unsigned int i = 0; i<this->_entitiesPerCreation; i++) {
	if (_entitiesCreatedSoFar < _maxCreations) {
	    _entitiesCreatedSoFar++;
	    Entity* newEntity = new Entity(this->_model->getElementManager());
	    newEntity->setEntityType(entity->getEntityType());
	    _model->getElementManager()->insert(Util::TypeOf<Entity>(), newEntity); // ->getEntities()->insert(newEntity);
	    timeBetweenCreations = _model->parseExpression(this->_timeBetweenCreationsExpression);
	    timeScale = Util::TimeUnitConvert(this->_timeBetweenCreationsTimeUnit, _model->getInfos()->getReplicationLengthTimeUnit());
	    newArrivalTime = tnow + timeBetweenCreations*timeScale;
	    Event* newEvent = new Event(newArrivalTime, newEntity, this);
	    _model->getEvents()->insert(newEvent);
	    _model->getTraceManager()->traceSimulation(Util::TraceLevel::blockInternal, tnow, entity, this, "Arrival of entity " + std::to_string(newEntity->getId()) + " schedule for time " + std::to_string(newArrivalTime));
	    //_model->getTrace()->trace(Util::TraceLevel::blockInternal, "Arrival of entity "+std::to_string(entity->getId()) + " schedule for time " +std::to_string(newArrivalTime));
	}
    }
    _numberOut->incCountValue();
    _model->sendEntityToComponent(entity, this->getNextComponents()->front(), 0.0);
}

PluginInformation* Create::GetPluginInformation(){
    return new PluginInformation(Util::TypeOf<Create>(), &Create::LoadInstance);
}

ModelComponent* Create::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Create* newComponent = new Create(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {
	
    }
    return newComponent;
}

bool Create::_loadInstance(std::map<std::string, std::string>* fields) {
    return SourceModelComponent::_loadInstance(fields);
}

void Create::_initBetweenReplications() {
    SourceModelComponent::_initBetweenReplications();
}

std::map<std::string, std::string>* Create::_saveInstance() {
    std::map<std::string, std::string>* fields = SourceModelComponent::_saveInstance(); //Util::TypeOf<Create>());
    return fields;
}

bool Create::_check(std::string* errorMessage) {
    bool resultAll = SourceModelComponent::_check(errorMessage);
    return resultAll;
}
