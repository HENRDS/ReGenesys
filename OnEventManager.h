/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 12:28
 */

#ifndef ONEVENTMANAGER_H
#define ONEVENTMANAGER_H

#include <list>
#include "Event.h"

/* TODO: To implement as item (1) for DS3
 * used to get and set values no matter the class (for process analyser)
 * should be a wait to invoke a getter or setter no matter the class (a pointer to a member function without specifying the class 
 */
//typedef double (*memberFunctionGetDoubleVarHandler)(); //template<> ... typedef double (T::*getDoubleVarHandler)() or something like that
//typedef void (*memberFunctionSetDoubleVarHandler)(double);

class SimulationEvent {
public:

    SimulationEvent(unsigned int replicationNumber, Event* event) {
	_replicationNumber = replicationNumber;
	_event = event;
    }
public:

    unsigned int getReplicationNumber() const {
	return _replicationNumber;
    }

    Event* getEventProcessed() const {
	return _event;
    }
private:
    unsigned int _replicationNumber;
    Event* _event;
};

typedef void (*simulationEventHandler)(SimulationEvent*);

/*!
 * OnEventManager allows external methods to hook interval simulation events as listeners (or observers) of pecific events.
 * All methods added as listeners of an event will be invovked when that event is triggered.
 */
class OnEventManager {
public:
    OnEventManager();
    OnEventManager(const OnEventManager& orig);
    virtual ~OnEventManager();
public: // event listeners (handlers)
    void addOnReplicationStartHandler(simulationEventHandler EventHandler);
    void addOnReplicationStepHandler(simulationEventHandler EventHandler);
    void addOnReplicationEndHandler(simulationEventHandler EventHandler);
    void addOnProcessEventHandler(simulationEventHandler EventHandler);
    void addOnSimulationStartHandler(simulationEventHandler EventHandler);
    void addOnSimulationEndHandler(simulationEventHandler EventHandler);
    void addOnEntityRemoveHandler(simulationEventHandler EventHandler);
public:
    void NotifyReplicationStartHandlers(SimulationEvent* se);
    void NotifyReplicationStepHandlers(SimulationEvent* se);
    void NotifyReplicationEndHandlers(SimulationEvent* se);
    void NotifyProcessEventHandlers(SimulationEvent* se);
    void NotifySimulationStartHandlers(SimulationEvent* se);
    void NotifySimulationEndHandlers(SimulationEvent* se);
private:
    void _NotifyHandlers(std::list<simulationEventHandler>* list, SimulationEvent* se);
private: // events listener
    std::list<simulationEventHandler>* _onReplicationStartHandlers = new std::list<simulationEventHandler>();
    std::list<simulationEventHandler>* _onReplicationStepHandlers = new std::list<simulationEventHandler>();
    std::list<simulationEventHandler>* _onReplicationEndHandlers = new std::list<simulationEventHandler>();
    std::list<simulationEventHandler>* _onProcessEventHandlers = new std::list<simulationEventHandler>();
    std::list<simulationEventHandler>* _onSimulationStartHandlers = new std::list<simulationEventHandler>();
    std::list<simulationEventHandler>* _onSimulationEndHandlers = new std::list<simulationEventHandler>();
private:
};

#endif /* ONEVENTMANAGER_H */

