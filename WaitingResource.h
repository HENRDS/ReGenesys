/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WaitingResource.h
 * Author: rafael.luiz.cancian
 *
 * Created on 29 de Agosto de 2018, 17:10
 */

#ifndef WAITINGRESOURCE_H
#define WAITINGRESOURCE_H

#include "Waiting.h"

class WaitingResource : public Waiting {
public:
    WaitingResource(Entity* entity, ModelComponent* component, double timeStartedWaiting, unsigned int quantity);
    WaitingResource(const WaitingResource& orig);
    virtual ~WaitingResource();
public:
    virtual std::string show();
public:
    unsigned int getQuantity() const;
private:
    unsigned int _quantity;
};

#endif /* WAITINGRESOURCE_H */

