/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Agosto de 2018, 19:03
 */

#ifndef HYPOTHESISTESTERDUMMYIMPL_H
#define HYPOTHESISTESTERDUMMYIMPL_H

#include "HypothesisTester_if.h"

class HypothesisTesterDummyImpl : public HypothesisTester_if {
public:
    HypothesisTesterDummyImpl();
    HypothesisTesterDummyImpl(const HypothesisTesterDummyImpl& orig);
    ~HypothesisTesterDummyImpl();
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
};

#endif /* HYPOTHESISTESTERDUMMYIMPL_H */

