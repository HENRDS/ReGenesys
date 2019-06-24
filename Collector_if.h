/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collector_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 14:16
 */

#ifndef COLLECTOR_IF_H
#define COLLECTOR_IF_H

#include <string>
#include <functional>

/*!
 */
typedef std::function<void(double) > CollectorAddValueHandler;

template<typename Class>
CollectorAddValueHandler SetCollectorAddValueHandler(void (Class::*function)(double), Class * object) {
    return std::bind(function, object, std::placeholders::_1);
}

typedef std::function<void() > CollectorClearHandler;

template<typename Class>
CollectorClearHandler SetCollectorClearHandler(void (Class::*function)(), Class * object) {
    return std::bind(function, object);
}

/**
 * Interface for collecting values of a single stochastic variable.  Values collected can be used as base for statistical analysis. 
 */
class Collector_if {
public:
    virtual void clear() = 0;
    virtual void addValue(double value) = 0;
    virtual double getLastValue() = 0;
    virtual unsigned long numElements() = 0;
public:
    virtual void setAddValueHandler(CollectorAddValueHandler addValueHandler) = 0;
    virtual void setClearHandler(CollectorClearHandler clearHandler) = 0;
};

#endif /* COLLECTOR_IF_H */

