/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TraceManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 11:59
 */

#ifndef TRACEMANAGER_H
#define TRACEMANAGER_H

#include "List.h"

class Model;
class Entity;
class ModelComponent;

class TraceEvent {
public:

    TraceEvent(Util::TraceLevel tracelevel, std::string text) {
	_tracelevel = tracelevel;
	_text = text;
    }

    Util::TraceLevel getTracelevel() const {
	return _tracelevel;
    }

    std::string getText() const {
	return _text;
    }
private:
    Util::TraceLevel _tracelevel;
    std::string _text;
};

class TraceErrorEvent : public TraceEvent {
public:

    TraceErrorEvent(std::string text, std::exception e) : TraceEvent(Util::TraceLevel::errors, text) {
	_e = e;
    }

    std::exception getException() const {
	return _e;
    }
private:
    std::exception _e;
};

class TraceSimulationEvent : public TraceEvent {
public:

    ModelComponent* getComponent() const {
	return _component;
    }

    Entity* getEntity() const {
	return _entity;
    }

    double getTime() const {
	return _time;
    }

    TraceSimulationEvent(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text) : TraceEvent(tracelevel, text) {
	_time = time;
	_entity = entity;
	_component = component;
    }
private:
    double _time;
    Entity* _entity;
    ModelComponent* _component;
};

/*!
 * Events related to simulation "process" (usually process analyser), associated to entire replication or simulation events (begin/end/pause of replication/simulation) 
 * TODO: CLASS NOT COMPLETE
 */
class TraceSimulationProcess : public TraceEvent {
public:

    TraceSimulationProcess(Util::TraceLevel tracelevel, std::string text) : TraceEvent(tracelevel, text) {
    }
};

typedef void (*traceListener)(TraceEvent);
typedef void (*traceErrorListener)(TraceErrorEvent);
typedef void (*traceSimulationListener)(TraceSimulationEvent);
typedef void (*traceSimulationProcessListener)(TraceSimulationProcess);

/*!
 * The TraceManager is used to trace back model simulation information and track/debug the simulation. 
 * It works as the model simulation output (cout) and allows external methods to hook up such output as listeners.
 */
class TraceManager {
public:
    TraceManager(Simulator* simulator);//(Model* model);
    TraceManager(const TraceManager& orig);
    virtual ~TraceManager();
public: // traces
    void addTraceHandler(traceListener traceListener);
    void addTraceErrorHandler(traceErrorListener traceErrorListener);
    void addTraceReportHandler(traceListener traceReportListener);
    //void addTraceSimulationHandler(traceListener traceListener);
    void addTraceSimulationHandler(traceSimulationListener traceSimulationListener);
    void trace(Util::TraceLevel tracelevel, std::string text);
    void traceError(std::exception e, std::string text);
    //void traceSimulation(Util::TraceLevel tracelevel, std::string text);
    void traceSimulation(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text);
    void traceReport(Util::TraceLevel tracelevel, std::string text);
    List<std::string>* getErrorMessages() const;
public:
    void setTraceLevel(Util::TraceLevel _traceLevel);
    Util::TraceLevel getTraceLevel() const;
    Simulator* getSimulator() const;
private:
    bool _traceConditionPassed(Util::TraceLevel level);
private: // trace listener
    std::list<traceListener>* _traceHandlers = new std::list<traceListener>();
    std::list<traceErrorListener>* _traceErrorHandlers = new std::list<traceErrorListener>();
    std::list<traceListener>* _traceReportHandlers = new std::list<traceListener>();
    std::list<traceSimulationListener>* _traceSimulationHandlers = new std::list<traceSimulationListener>();
private:
    //Model* _model;
    Simulator* _simulator;
private:
    Util::TraceLevel _traceLevel; // = Util::TraceLevel::mostDetailed;
    bool _debugged;
    double _lastTimeTraceSimulation = -1.0;
    Util::identitifcation _lastEntityTraceSimulation = 0;
    Util::identitifcation _lastModuleTraceSimulation = 0;
    List<std::string>* _errorMessages; /* todo: 18/08/24 this is a new one. several methods should use it */

};

#endif /* TRACEMANAGER_H */

