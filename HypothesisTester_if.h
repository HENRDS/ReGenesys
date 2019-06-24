/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 19:04
 */

#ifndef HYPOTHESISTESTER_IF_H
#define HYPOTHESISTESTER_IF_H

#include <string>

/**
 * Interface for parametric hypothesis tests based on a datafile. 
 */
class HypothesisTester_if {
public:

    enum H1Comparition {
	DIFFERENT = 1,
	LESS_THAN = 2,
	GREATER_THAN = 3
    };
public:
    /* TODO: all "test" methods should return double p-value, not bool */
    virtual double testAverage(double confidencelevel, double avg, H1Comparition comp) = 0;
    virtual double testProportion(double confidencelevel, double prop, H1Comparition comp) = 0;
    virtual double testVariance(double confidencelevel, double var, H1Comparition comp) = 0;
    virtual double testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
    virtual double testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
    virtual double testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) = 0;
    virtual void setDataFilename(std::string dataFilename) = 0;
    virtual std::string getDataFilename() = 0;
};

#endif /* HYPOTHESISTESTER_IF_H */

