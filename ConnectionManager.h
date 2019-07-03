/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectionManager.h
 * Author: rlcancian
 *
 * Created on 1 de Julho de 2019, 18:39
 */

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <utility>
#include "List.h"

class ModelComponent;

typedef std::pair<ModelComponent*, unsigned int> Connection;

class ConnectionManager {
public:
    ConnectionManager();
    ConnectionManager(const ConnectionManager& orig);
    virtual ~ConnectionManager();
public:
    unsigned int size();
    ModelComponent* front();
    ModelComponent* getAtRank(unsigned int rank);
    Connection* frontConnection();
    Connection* getConnectionAtRank(unsigned int rank);
    void insert(ModelComponent* component, unsigned int inputNumber = 0);
    std::list<Connection*>* getList() const;
private:
    List<Connection*>* _nextConnections = new List<Connection*>();
};

#endif /* CONNECTIONMANAGER_H */

