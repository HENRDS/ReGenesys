/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessAnalyser_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Outubro de 2018, 14:26
 */

#ifndef PROCESSANALYSER_IF_H
#define PROCESSANALYSER_IF_H

#include "List.h"
#include "SimulationScenario.h"
#include "SimulationControl.h"
#include "SimulationResponse.h"
#include "TraceManager.h"

/*!
 * The process analyser allows to extract controls and responses from a model, incluse some of then as controls and responses for a set of scenarios to be simulated
 */
class ProcessAnalyser_if {
public:
    virtual List<SimulationScenario*>* getScenarios() const = 0;
    virtual List<SimulationControl*>* getControls() const = 0;
    virtual List<SimulationResponse*>* getResponses() const = 0;
    virtual List<SimulationControl*>* extractControlsFromModel(std::string modelFilename) const = 0;
    virtual List<SimulationResponse*>* extractResponsesFromModel(std::string modelFilename) const = 0;
    virtual void startSimulationOfScenario(SimulationScenario* scenario) = 0;
    virtual void startSimulation() = 0;
    virtual void stopSimulation() = 0;
    virtual void addTraceSimulationHandler(traceSimulationProcessListener traceSimulationProcessListener) = 0;
};

#endif /* PROCESSANALYSER_IF_H */

