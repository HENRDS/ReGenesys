/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Genesys.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 12:48
 */

#ifndef GENESYS_H
#define GENESYS_H

#include <string>
#include <iostream>
//#include "Traits.h"
#include "Model.h"
#include "Plugin.h"
#include "List.h"
#include "LicenceManager.h"
#include "PluginManager.h"
#include "ModelManager.h"
#include "ToolManager.h"

/*!
 * The main class of the ReGenesys KERNEL simulation. It gives access to simulation models and tools.
 */
class Simulator {
    typedef void (*eventHandler)();
public:
    Simulator();
    Simulator(const Simulator& orig);
    virtual ~Simulator();
public: // only get
    std::string getVersion() const;
    std::string getName() const;
    LicenceManager* getLicenceManager() const;
    PluginManager* getPluginManager() const;
    ModelManager* getModelManager() const;
    ToolManager* getToolManager() const;
    TraceManager* getTraceManager() const;
private: 
private: // attributes 1:1 objects
    LicenceManager* _licenceManager;
    PluginManager* _pluginManager;
    ModelManager* _modelManager;
    ToolManager* _toolManager;
    TraceManager* _traceManager;
    //TraceManager* _tracer;
private: // attributes 1:1 native
    const std::string _name = "ReGenESyS - Reborn Generic and Expansible System Simulator";
    const std::string _version = "2019.0601";
};

#endif /* GENESYS_H */

