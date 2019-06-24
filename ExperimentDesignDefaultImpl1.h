/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentDesignDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Agosto de 2018, 10:19
 */

#ifndef EXPERIMENTDESIGNDEFAULTIMPL1_H
#define EXPERIMENTDESIGNDEFAULTIMPL1_H

#include "ExperimentDesign_if.h"

class ExperimentDesignDefaultImpl1 : public ExperimentDesign_if {
public:
    ExperimentDesignDefaultImpl1();
    ExperimentDesignDefaultImpl1(const ExperimentDesignDefaultImpl1& orig);
    virtual ~ExperimentDesignDefaultImpl1();
public:
    virtual ProcessAnalyser_if* getProcessAnalyser() const;
public:
    virtual bool generate2krScenarioExperiments();
    virtual bool calculateContributionAndCoefficients();
    virtual std::list<FactorOrInteractionContribution*>* getContributions() const;
private:
    ProcessAnalyser_if* _processAnalyser; //= new Traits<ExperimentDesign_if>::ProcessAnalyserImplementation();
    std::list<FactorOrInteractionContribution*>* _contributions = new std::list<FactorOrInteractionContribution*>();
};


#endif /* EXPERIMENTDESIGNDEFAULTIMPL1_H */

