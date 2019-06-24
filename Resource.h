/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:52
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ModelElement.h"
#include "StatisticsCollector.h"
#include "ElementManager.h"
#include "Counter.h"
#include "Plugin.h"


/*!
 * Resource represents a facility that...
 */
class Resource : public ModelElement {
public:
    typedef std::function<void(Resource*) > ResourceEventHandler;

    template<typename Class>
    static ResourceEventHandler SetResourceEventHandler(void (Class::*function)(Resource*), Class * object) {
	return std::bind(function, object, std::placeholders::_1);
    }

    enum class ResourceType : int {
	SET = 1, RESOURCE = 2
    };

    enum class ResourceRule : int {
	RANDOM = 1, CICLICAL = 2, ESPECIFIC = 3, SMALLESTBUSY = 4, LARGESTREMAININGCAPACITY = 5
    };

    enum class ResourceState : int {
	IDLE = 1, BUSY = 2, FAILED = 3, INACTIVE = 4, OTHER = 5
    };

public:
    Resource(ElementManager* elems);
    Resource(ElementManager* elems, std::string name);
    Resource(const Resource& orig);
    virtual ~Resource();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields);
public:
    void seize(unsigned int quantity, double tnow);
    void release(unsigned int quantity, double tnow);
    void initBetweenReplications();
public: // g&s
    void setResourceState(ResourceState _resourceState);
    Resource::ResourceState getResourceState() const;
    void setCapacity(unsigned int _capacity);
    unsigned int getCapacity() const;
    void setCostBusyHour(double _costBusyHour);
    double getCostBusyHour() const;
    void setCostIdleHour(double _costIdleHour);
    double getCostIdleHour() const;
    void setCostPerUse(double _costPerUse);
    double getCostPerUse() const;
public: // gets
    unsigned int getNumberBusy() const;
public:
    void addResourceEventHandler(ResourceEventHandler eventHandler);
    double getLastTimeSeized() const;
protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

private:
    void _initCStats();
    void _notifyEventHandlers();
private:
    ElementManager* _elems;
private:
    unsigned int _capacity = 1;
    double _costBusyHour = 1.0;
    double _costIdleHour = 1.0;
    double _costPerUse = 1.0;
    ResourceState _resourceState = ResourceState::IDLE;
    //Queue* _queue;
private: // only gets
    unsigned int _numberBusy = 0;
    //unsigned int _numberOut = 0;
    double _lastTimeSeized = 0.0; // TODO: It won't work for resources with capacity>1, when not all capacity is seized and them some more are seized. Seized time of first units will be lost. I don't have a solution so far
private: // not gets nor sets
    //unsigned int _seizes = 0;
    //double _whenSeized; // same as last? check
private: //1:1
    StatisticsCollector* _cstatTimeSeized; // = new StatisticsCollector("Time Seized");
    Counter* _numSeizes;
    Counter* _numReleases;
private: //1::n
    List<ResourceEventHandler>* _resourceEventHandlers = new List<ResourceEventHandler>();
    //aFailures:	TStringList;
    //std::list<Failure*>* _failures;
};

#endif /* RESOURCE_H */

