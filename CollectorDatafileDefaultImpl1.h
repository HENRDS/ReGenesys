/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 1 de Agosto de 2018, 20:58
 */

#ifndef COLLECTORDATAFILEDEFAULTIMPL1_H
#define COLLECTORDATAFILEDEFAULTIMPL1_H

#include <string>

#include "CollectorDatafile_if.h"

class CollectorDatafileDefaultImpl1 : public CollectorDatafile_if {
public:
    CollectorDatafileDefaultImpl1();
    CollectorDatafileDefaultImpl1(const CollectorDatafileDefaultImpl1& orig);
    virtual ~CollectorDatafileDefaultImpl1();
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

#endif /* COLLECTORDATAFILEDEFAULTIMPL1_H */

