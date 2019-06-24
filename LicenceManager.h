/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LicenceManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 29 de Maio de 2019, 11:45
 */

#ifndef LICENCEMANAGER_H
#define LICENCEMANAGER_H

#include <string>

class Simulator;

class LicenceManager {
public:
    LicenceManager(Simulator* simulator);
    LicenceManager(const LicenceManager& orig);
    virtual ~LicenceManager();
    const std::string showLicence() const;
    const std::string showLimits() const;
    const std::string showActivationCode() const;
    bool lookforActivationCode();
    bool insertActivationCode();
    void removeActivationCode();
    unsigned int getModelComponentsLimit();
    unsigned int getModelElementsLimit();
    unsigned int getEntityLimit();
    unsigned int getHostsLimit();
    unsigned int getThreadsLimit();
private:
    Simulator* _simulator;
    std::string _licence;
    std::string _activationCode;
    unsigned int _components, _elements, _entities,_hosts, _threads;
};

#endif /* LICENCEMANAGER_H */

