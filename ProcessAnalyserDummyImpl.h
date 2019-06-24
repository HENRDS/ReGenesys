/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessAnalyserDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Outubro de 2018, 18:27
 */

#ifndef PROCESSANALYSERDUMMYIMPL_H
#define PROCESSANALYSERDUMMYIMPL_H

#include "ProcessAnalyser_if.h"
#include "SimulationScenario.h"
#include "SimulationResponse.h"
#include "SimulationControl.h"

class ProcessAnalyserDummyImpl : public ProcessAnalyser_if {
public:
    ProcessAnalyserDummyImpl();
    ProcessAnalyserDummyImpl(const ProcessAnalyserDummyImpl& orig);
    ~ProcessAnalyserDummyImpl();
public:
    virtual List<SimulationScenario*>* getScenarios() const;
    virtual List<SimulationControl*>* getControls() const;
    virtual List<SimulationResponse*>* getResponses() const;
    virtual List<SimulationControl*>* extractControlsFromModel(std::string modelFilename) const;
    virtual List<SimulationResponse*>* extractResponsesFromModel(std::string modelFilename) const;
    virtual void startSimulationOfScenario(SimulationScenario* scenario);
    virtual void startSimulation();
    virtual void stopSimulation();
    virtual void addTraceSimulationHandler(traceSimulationProcessListener traceSimulationProcessListener);
private:
    List<SimulationControl*>* _controls = new List<SimulationControl*>();
};

#endif /* PROCESSANALYSERDUMMYIMPL_H */

