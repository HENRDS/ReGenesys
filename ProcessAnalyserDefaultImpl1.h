/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessAnalyserDefaultImpl1.h
 * Author: rlcancian
 *
 * Created on 20 de Maio de 2019, 20:45
 */

#ifndef PROCESSANALYSERDEFAULTIMPL1_H
#define PROCESSANALYSERDEFAULTIMPL1_H

#include "ProcessAnalyser_if.h"
#include "SimulationScenario.h"
#include "SimulationResponse.h"
#include "SimulationControl.h"

class ProcessAnalyserDefaultImpl1 : public ProcessAnalyser_if {
public:
    ProcessAnalyserDefaultImpl1();
    ProcessAnalyserDefaultImpl1(const ProcessAnalyserDefaultImpl1& orig);
    virtual ~ProcessAnalyserDefaultImpl1();
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

#endif /* PROCESSANALYSERDEFAULTIMPL1_H */

