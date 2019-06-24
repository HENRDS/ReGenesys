/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 16:52
 */

#ifndef STATISTICSDUMMYIMPL_H
#define STATISTICSDUMMYIMPL_H

#include "Statistics_if.h"
#include "Collector_if.h"

class StatisticsDummyImpl : public Statistics_if {
public:
    StatisticsDummyImpl();
    StatisticsDummyImpl(const StatisticsDummyImpl& orig);
    virtual ~StatisticsDummyImpl();
public:
    virtual Collector_if* getCollector();
    void setCollector(Collector_if* collector);
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
private:
    Collector_if* _collector;
    double _average = 0.0;
};

#endif /* STATISTICSDUMMYIMPL_H */

