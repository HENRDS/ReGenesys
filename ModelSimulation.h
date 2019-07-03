/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelSimulation.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 18:04
 */

#ifndef MODELSIMULATION_H
#define MODELSIMULATION_H

#include "Event.h"
#include "Entity.h"
#include "ModelInfo.h"
#include "SimulationReporter_if.h"
#include "Counter.h"

class Model;

/*!
 * The ModelSimulation controls the simulation of a model, alowing to start, pause, resume e stop a simulation, composed by 
 * a set of replications.
 */
class ModelSimulation {
public:
    ModelSimulation(Model* model);
    ModelSimulation(const ModelSimulation& orig);
    virtual ~ModelSimulation();
public: // simulation control
    void startSimulation(); ///< Starts a sequential execution of a simulation, ie, a set of replications of this model.
    void pauseSimulation();
    void stepSimulation(); ///< Executes the processing of a single event, the next one in the future events list.
    void stopSimulation();
    void restartSimulation();
public:
    void setPauseOnEvent(bool _pauseOnEvent);
    bool isPauseOnEvent() const;
    void setStepByStep(bool _stepByStep);
    bool isStepByStep() const;
    void setInitializeStatistics(bool _initializeStatistics);
    bool isInitializeStatistics() const;
    void setInitializeSystem(bool _initializeSystem);
    bool isInitializeSystem() const;
    void setPauseOnReplication(bool _pauseBetweenReplications);
    bool isPauseOnReplication() const;
public: // only gets
    double getSimulatedTime() const; /*! The current time in the model being simulated, i.e., the instant when the current event was triggered */
    bool isRunning() const;
    unsigned int getCurrentReplicationNumber() const;
    ModelComponent* getCurrentComponent() const;
    Entity* getCurrentEntity() const;
    unsigned int getCurrentInputNumber() const;
    SimulationReporter_if* getSimulationReporter() const;
    /*
     * PRIVATE
     */
private: // simulation control
    void _initSimulation();
    void _initReplication(); ///< Clear the event list, restarts simulated time, initialize event list and statistics, request components to reinitialize
    void _initStatistics();
    void _stepSimulation();
    void _processEvent(Event* event);
private:
    bool _isReplicationEndCondition();
    void _actualizeSimulationStatistics();
    void _showSimulationHeader();
private:
    double _simulatedTime = 0.0;
    // list of double double _breakOnTimes;
    // list of modules _breakOnModules;
    bool _stepByStep = false;
    bool _pauseOnReplication = false;
    bool _pauseOnEvent = false;
    bool _initializeStatisticsBetweenReplications = true;
    bool _initializeSystem = true;
    bool _running = false;
    bool _pauseRequested = false;
    bool _stopRequested = false;
    bool _simulationIsInitiated = false;
    bool _replicationIsInitiaded = false;
private:
    Entity* _currentEntity;
    ModelComponent* _currentComponent;
    unsigned int _currentInputNumber;
    SimulationReporter_if* _simulationReporter;
    unsigned int _currentReplicationNumber;
    List<ModelElement*>* _statsCountersSimulation = new List<ModelElement*>();
    //std::list<ModelElement*>* _countersSimulation = new std::list<ModelElement*>();
private:
    Model* _model;
    ModelInfo* _info;
private:
    const std::string _cte_stCountSimulNamePrefix = ""; //Simul.";
};

#endif /* MODELSIMULATION_H */

