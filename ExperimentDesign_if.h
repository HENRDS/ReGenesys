/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentDesign.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Outubro de 2018, 22:47
 */

#ifndef EXPERIMENTDESIGN_IF_H
#define EXPERIMENTDESIGN_IF_H

#include "FactorOrInteractionContribution.h"
#include "ProcessAnalyser_if.h"

/*!
 * It designs a set of experiments (SimulationScenario) where que level of factors (SimulationControl) are set automatically to create a 2^k.r experiment design, and where the contributions of the factors and their interactions (just a set of SimulationControl) can be obtained.
 */
class ExperimentDesign_if {
public:
    virtual ProcessAnalyser_if* getProcessAnalyser() const = 0;
    virtual bool generate2krScenarioExperiments() = 0;
    virtual bool calculateContributionAndCoefficients() = 0;
    virtual std::list<FactorOrInteractionContribution*>* getContributions() const = 0;
};

#endif /* EXPERIMENTDESIGN_IF_H */

