/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dispose.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 20:13
 */

#include "Dispose.h"
#include "Model.h"

Dispose::Dispose(Model* model) : SinkModelComponent(model, Util::TypeOf<Dispose>()) {
    _numberOut = new Counter("Count number out", this);
    _model->getElementManager()->insert(Util::TypeOf<Counter>(), _numberOut);
    //model->getResponses()->insert(new SimulationResponse(Util::TypeOf<Dispose>(), "Number Out",
    //        DefineGetterMember<Dispose>(this, &Dispose::getNumberOut))
    //        );
}

Dispose::Dispose(const Dispose& orig) : SinkModelComponent(orig) {
}

Dispose::~Dispose() {
}

std::string Dispose::show() {
    return SinkModelComponent::show() +
	    ",collectStatistics=" + std::to_string(this->_collectStatistics);
}

void Dispose::_execute(Entity* entity) {
    _numberOut->incCountValue();
    _model->removeEntity(entity, this->isCollectStatistics());
}

bool Dispose::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelComponent::_loadInstance(fields);
}

void Dispose::_initBetweenReplications() {
    SinkModelComponent::_initBetweenReplications();
}

std::map<std::string, std::string>* Dispose::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Dispose>());
    return fields;

}

bool Dispose::_check(std::string* errorMessage) {
    return true;
}

PluginInformation* Dispose::GetPluginInformation(){
    return new PluginInformation(Util::TypeOf<Dispose>(), &Dispose::LoadInstance);
}

ModelComponent* Dispose::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Dispose* newComponent = new Dispose(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {
	
    }
    return newComponent;

}
