/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComponentManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 28 de Maio de 2019, 10:41
 */

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "ModelComponent.h"

//class Model;

class ComponentManager {
public:
    ComponentManager(Model* model);
    ComponentManager(const ComponentManager& orig);
    virtual ~ComponentManager();
public:
    bool insert(ModelComponent* comp);
    void remove(ModelComponent* comp);
    void clear();
    //bool check(ModelComponent* comp, std::string expressionName, std::string* errorMessage);
    //bool check(std::string compName, std::string expressionName, bool mandatory, std::string* errorMessage);    
public:
    ModelComponent* getComponent(Util::identitifcation id);
    ModelComponent* getComponent(std::string name);
    unsigned int getNumberOfComponents();
    std::list<ModelComponent*>::iterator begin();
    std::list<ModelComponent*>::iterator end();
    //int getRankOf(std::string name);
public:
private:
    List<ModelComponent*>* _components;
    Model* _model;
};

#endif /* COMPONENTMANAGER_H */

