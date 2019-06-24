/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Agosto de 2018, 10:27
 */

#ifndef HYPOTHESISTESTERDEFAULTIMPL1_H
#define HYPOTHESISTESTERDEFAULTIMPL1_H

#include "HypothesisTester_if.h"
#include "Integrator_if.h"

class HypothesisTesterDefaultImpl1 : public HypothesisTester_if {
public:
    HypothesisTesterDefaultImpl1();
    HypothesisTesterDefaultImpl1(const HypothesisTesterDefaultImpl1& orig);
    virtual ~HypothesisTesterDefaultImpl1();
public:
    virtual double testAverage(double confidencelevel, double avg, H1Comparition comp);
    virtual double testProportion(double confidencelevel, double prop, H1Comparition comp);
    virtual double testVariance(double confidencelevel, double var, H1Comparition comp);
    virtual double testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual double testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual double testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual void setDataFilename(std::string dataFilename);
    virtual std::string getDataFilename();
private:
    Integrator_if* _integrator;
};

#endif /* HYPOTHESISTESTERDEFAULTIMPL1_H */

