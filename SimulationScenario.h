/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationScenario.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Outubro de 2018, 18:21
 */

#ifndef SIMULATIONSCENARIO_H
#define SIMULATIONSCENARIO_H

#include <string>
#include <list>
#include "SimulationResponse.h"
#include "SimulationControl.h"

/*!
 * Represents a scenario where a specific model (defined my ModelFilename) will be simulated. To each scenario will be associated a set of SimulationControl and SimulationResponse, and their values are set to the scenario by the ProcessAnalyser.
 */
class SimulationScenario {
public:
    SimulationScenario();
    SimulationScenario(const SimulationScenario& orig);
    virtual ~SimulationScenario();
public:
    void setName(std::string _name);
    std::string getName() const;
    std::list<double>* getResponseValues() const;
    std::list<double>* getControlValues() const;
    void setModelFilename(std::string _modelFilename);
    std::string getModelFilename() const;
public:
    double getResponseValue(SimulationResponse* value);
    double getControlValue(SimulationControl* control);
    void setControlValue(SimulationControl* control, double value);
private:
    std::string _name;
    std::string _modelFilename;
    std::list<double>* _controlValues;
    std::list<double>* _responseValues;
};

#endif /* SIMULATIONSCENARIO_H */

