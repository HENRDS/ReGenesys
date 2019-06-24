/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seize.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:17
 */

#ifndef SEIZE_H
#define SEIZE_H

#include <string>
#include "ModelComponent.h"
#include "Model.h"
#include "Resource.h"
#include "Queue.h"
#include "Plugin.h"


/*!
 * Seize tries to allocate a certain amount of a resource
 */
class Seize : public ModelComponent {
public:
    Seize(Model* model);
    Seize(const Seize& orig);
    virtual ~Seize();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public: // get & set
    void setLastMemberSeized(unsigned int _lastMemberSeized);
    unsigned int getLastMemberSeized() const;
    void setSaveAttribute(std::string _saveAttribute);
    std::string getSaveAttribute() const;
    void setRule(Resource::ResourceRule _rule);
    Resource::ResourceRule getRule() const;
    void setQuantity(std::string _quantity);
    std::string getQuantity() const;
    void setResourceType(Resource::ResourceType _resourceType);
    Resource::ResourceType getResourceType() const;
    void setPriority(unsigned short _priority);
    unsigned short getPriority() const;
    void setAllocationType(unsigned int _allocationType);
    unsigned int getAllocationType() const;
    // indirect access to Queue* and Resource*
    void setResourceName(std::string _resourceName) throw();
    std::string getResourceName() const;
    void setQueueName(std::string queueName) throw();
    std::string getQueueName() const;
    void setResource(Resource* resource);
    Resource* getResource() const;
    void setQueue(Queue* queue);
    Queue* getQueue() const;
protected:
    virtual void _execute(Entity* entity);
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    void _handlerForResourceEvent(Resource* resource);
private:
    unsigned int _allocationType = 0; // uint ? enum?
    unsigned short _priority = 0;
    Resource::ResourceType _resourceType = Resource::ResourceType::RESOURCE;
    std::string _quantity = "1";
    Resource::ResourceRule _rule = Resource::ResourceRule::SMALLESTBUSY;
    std::string _saveAttribute = "";
    //std::string _resourceName = "Resource 1";  // trying to access resource and queue indirectly
    //std::string _queueName;
private: // not gets or sets
    Queue* _queue; // usually has a queue, but not always (it could be a hold) /* Todo: Evaluate if is better to associate queue to seize or to the resource */
    Resource* _resource; // usually has a resource, but not always (it could be a set)
    //Set* _set;
    unsigned int _lastMemberSeized = 0;
};

#endif /* SEIZE_H */

