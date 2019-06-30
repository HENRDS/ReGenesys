/*
 * File:   Batch.h
 * Author: bruno.hass.gabriel.muller.joao.meyer
 *
 * Created on 16 de Junho de 2019
 */

#include "Model.h"
#include "Batch.h"
#include "Group.h"
#include "Attribute.h"

Batch::Batch(Model* model) : ModelComponent(model, Util::TypeOf<Batch>())
{
    // Nothing
}

Batch::Batch(const Batch& orig) : ModelComponent(orig)
{
    // Nothing
}

Batch::~Batch()
{
    // Nothing
}

std::string Batch::show()
{
    return ModelComponent::show() + "This is a batch";
}

void Batch::setBatchSize(unsigned int batchSize)
{
    this->_batchSize = batchSize;
    this->_remaining = batchSize;
}

void Batch::setGroupName(std::string groupName)
{
    this->_groupName = groupName;
}

PluginInformation* Batch::GetPluginInformation()
{
    return new PluginInformation(
        Util::TypeOf<Batch>(),
        &Batch::LoadInstance);
}

ModelComponent* Batch::LoadInstance(Model* model, std::map<std::string, std::string>* fields)
{
    Batch* newComponent = new Batch(model);
    try
    {
        newComponent->_loadInstance(fields);
    }
    catch (const std::exception& e)
    {
        // Nothing
    }
    return newComponent;
}

void Batch::_execute(Entity* entity)
{
    TraceManager* traceManager = this->_model->getTraceManager();
    traceManager->trace(Util::TraceLevel::simulation, "Insert entity!");

    ElementManager* elementManager = this->_model->getElementManager();
    Group* group = (Group*) elementManager->getElement(Util::TypeOf<Group>(), this->_groupName);

    // Insert entities into group
    group->insertElement(entity);
    this->_remaining--;

    if (this->_remaining == 0)
    {
        traceManager->trace(Util::TraceLevel::simulation, "Release batch!");
        ModelComponent* nextComponent = this->getNextComponents()->front();
        this->_model->sendEntityToComponent(entity, nextComponent, 0.0);
        this->_remaining = this->_batchSize;
    }
}

void Batch::_initBetweenReplications()
{
    this->_remaining = this->_batchSize;
}

bool Batch::_loadInstance(std::map<std::string, std::string>* fields)
{
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
    }
    return res;
}

std::map<std::string, std::string>* Batch::_saveInstance()
{
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    return fields;
}

bool Batch::_check(std::string* errorMessage)
{
    return true;
}

