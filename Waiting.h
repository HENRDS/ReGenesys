/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Waiting.h
 * Author: rafael.luiz.cancian
 *
 * Created on 29 de Agosto de 2018, 17:09
 */

#ifndef WAITING_H
#define WAITING_H

#include "Entity.h"
#include "ModelComponent.h"

class Waiting {
public:
    Waiting(Entity* entity, ModelComponent* component, double timeStartedWaiting);
    Waiting(const Waiting& orig);
    virtual ~Waiting();
public:
    virtual std::string show();
public:
    double getTimeStartedWaiting() const;
    ModelComponent* getComponent() const;
    Entity* getEntity() const;
private:
    Entity* _entity;
    ModelComponent* _component;
    double _timeStartedWaiting;
};

#endif /* WAITING_H */

