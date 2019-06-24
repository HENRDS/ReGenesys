/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDataFileDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Novembro de 2018, 01:24
 */

#ifndef STATISTICSDATAFILEDUMMYIMPL_H
#define STATISTICSDATAFILEDUMMYIMPL_H

#include "StatisticsDataFile_if.h"

class StatisticsDataFileDummyImpl : public StatisticsDatafile_if {
public:
    StatisticsDataFileDummyImpl();
    StatisticsDataFileDummyImpl(const StatisticsDataFileDummyImpl& orig);
    virtual ~StatisticsDataFileDummyImpl();
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
    virtual double halfWidthConfidenceInterval(double confidencelevel);
    virtual unsigned int newSampleSize(double confidencelevel, double halfWidth);

    virtual double mode();
    virtual double mediane();
    virtual double quartil(unsigned short num);
    virtual double decil(unsigned short num);
    virtual double centil(unsigned short num);
    virtual void setHistogramNumClasses(unsigned short num);
    virtual unsigned short histogramNumClasses();
    virtual double histogramClassLowerLimit(unsigned short classNum);
    virtual unsigned int histogramClassFrequency(unsigned short classNum);
private:
    Collector_if* _collector;
};

#endif /* STATISTICSDATAFILEDUMMYIMPL_H */

