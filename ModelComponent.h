/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Element.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 15:56
 */

#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

#include <string>
#include <list>

#include "Plugin.h"
#include "List.h"
#include "Entity.h"
#include "ModelElement.h"

class Model;

/**
 * A component of the model is a block that represents a specific behavior to be simulated. The behavior is triggered when an entity arrives at the component, which corresponds to the occurrence of an event. A simulation model corresponds to a set of interconnected components to form the process by which the entity is submitted.
 * @param model The model this component belongs to
 */
class ModelComponent : public ModelElement {
public:
    ModelComponent(Model* model, std::string componentTypename);
    ModelComponent(const ModelComponent& orig);
    virtual ~ModelComponent();
public:
    virtual std::string show();
public:
    List<ModelComponent*>* getNextComponents() const; ///< Returns a list of components directly connected to the output. Usually the components have a single output, but they may have none (such as Dispose) or more than one (as Decide).
public:
    static void Execute(Entity* entity, ModelComponent* component); ///< This method triggers the simulation of the behavior of the component. It is invoked when an event (corresponding to this component) is taken from the list of future events or when an entity arrives at this component by connection.
    static void InitBetweenReplications(ModelComponent* component);
    static bool Check(ModelComponent* component);
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
    static std::map<std::string, std::string>* SaveInstance(ModelComponent* component);
private:
    List<ModelComponent*>* _nextComponents = new List<ModelComponent*>();
    List<Util::identitifcation>* _tempLoadNextComponentsIDs; // initialize only when loading 
protected:
    virtual void _execute(Entity* entity) = 0;
    virtual void _initBetweenReplications() = 0;

protected:
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    //virtual std::list<std::map<std::string,std::string>*>* _saveInstance(std::string type);

protected:
    Model* _model;
};

#endif /* MODELCOMPONENT_H */

