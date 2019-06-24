/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 1 de Agosto de 2018, 21:03
 */

#ifndef STATISTICSDEFAULTIMPL1_H
#define STATISTICSDEFAULTIMPL1_H

#include "Statistics_if.h"
#include "Collector_if.h"

class StatisticsDefaultImpl1 : public Statistics_if {
public:
    StatisticsDefaultImpl1(); ///< When constructor is invoked without a Collector, it is taken from Traits<Statistics_if>::CollectorImplementation configuration
    StatisticsDefaultImpl1(Collector_if* collector);
    StatisticsDefaultImpl1(const StatisticsDefaultImpl1& orig);
    virtual ~StatisticsDefaultImpl1();
public:
    virtual Collector_if* getCollector();
    virtual void setCollector(Collector_if* collector);
public:
    virtual unsigned int numElements();
    virtual double min();
    virtual double max();
    virtual double average();
    virtual double variance();
    virtual double stddeviation();
    virtual double variationCoef();
    virtual double halfWidthConfidenceInterval();
    virtual unsigned int newSampleSize(double halfWidth);
    virtual double getConfidenceLevel();
    virtual void setConfidenceLevel(double confidencelevel);
private:
    void collectorAddHandler(double newValue);
    void collectorClearHandler();
    void initStatistics();
private:
    Collector_if* _collector;
    unsigned long _elems;
    double _sum;
    double _sumSquare;
    double _min;
    double _max;
    double _average;
    double _variance;
    double _stddeviation;
    double _variationCoef;
    double _confidenceLevel = 0.95;
    double _criticalTn_1 = 1.96;
    double _halfWidth;
};

#endif /* STATISTICSDEFAULTIMPL1_H */

