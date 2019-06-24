/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plugin.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 12:58
 */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "Util.h"
#include <string>
#include <functional>
#include <list>

class ModelElement;
class ModelComponent;
class Model;
class ElementManager;

typedef ModelComponent* (*StaticLoaderComponentInstance)(Model*, std::map<std::string, std::string>*);
typedef ModelElement* (*StaticLoaderElementInstance)(ElementManager*, std::map<std::string, std::string>*);
class PluginInformation;
typedef PluginInformation* (*StaticGetPluginInformation)();

class PluginInformation {
public:

    PluginInformation(std::string pluginTypename, StaticLoaderComponentInstance componentloader) {
	this->componentloader = componentloader;
	this->elementloader = nullptr;
	this->isComponent = true;
	this->pluginTypename = pluginTypename;
	//this->source = source;
    }

    PluginInformation(std::string pluginTypename, StaticLoaderElementInstance elementloader) {
	this->componentloader = nullptr;
	this->elementloader = elementloader;
	this->isComponent = false;
	this->pluginTypename = pluginTypename;
	//this->source = source;
    }
    std::string pluginTypename;
    std::string author = "";
    std::string date = "";
    std::string observation = "";
    bool isSource;
    bool isSink;
    bool isComponent;
    bool generateReport = false;
    StaticLoaderComponentInstance componentloader;
    StaticLoaderElementInstance elementloader;
    std::list<PluginInformation> dependencies;
};

/*!
 * A Plugin represents a dynamically linked component class (ModelComponent) or element class (ModelElement); It gives access to a ModelComponent so it can be used by the model. Classes like Create, Delay, and Dispose are examples of PlugIns.  It corresponds directly to the  "Expansible" part (the capitalized 'E') of the GenESyS acronymous
PlugIns are NOT implemented yet
 */
class Plugin {
public:
    Plugin(StaticGetPluginInformation getInformation); //std::string pluginTypename, bool source, bool drain);
    Plugin(const Plugin& orig);
    virtual ~Plugin();
public:
    bool isIsValidPlugin() const;
    PluginInformation* getPluginInfo() const;
public:
    ModelElement* loadNew(Model* model, std::map<std::string, std::string>* fields);
    bool loadAndInsertNew(Model* model, std::map<std::string, std::string>* fields);
private:
    ModelComponent* _loadNewComponent(Model* model, std::map<std::string, std::string>* fields);
    ModelElement* _loadNewElement(ElementManager* model, std::map<std::string, std::string>* fields);
private: // read only
    bool _isValidPlugin;
    PluginInformation* _pluginInfo;
private:
    StaticGetPluginInformation _StatMethodGetInformation;
};

#endif /* PLUGIN_H */

