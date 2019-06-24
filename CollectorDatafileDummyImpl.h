/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 30 de Agosto de 2018, 16:53
 */

#ifndef COLLECTORDATAFILEDUMMYIMPL_H
#define COLLECTORDATAFILEDUMMYIMPL_H

#include "CollectorDatafile_if.h"

class CollectorDatafileDummyImpl : public CollectorDatafile_if {
public:
    CollectorDatafileDummyImpl();
    CollectorDatafileDummyImpl(const CollectorDatafileDummyImpl& orig);
    ~CollectorDatafileDummyImpl();
public: // inherited from Collector_if
    void clear();
    void addValue(double value);
    double getLastValue();
    unsigned long numElements();
public:
    double getValue(unsigned int num);
    double getNextValue();
    void seekFirstValue();
    std::string getDataFilename();
    void setDataFilename(std::string filename);
public:
    void setAddValueHandler(CollectorAddValueHandler addValueHandler);
    void setClearHandler(CollectorClearHandler clearHandler);
private:
    std::string _filename;
};

#endif /* COLLECTORDATAFILEDUMMYIMPL_H */

