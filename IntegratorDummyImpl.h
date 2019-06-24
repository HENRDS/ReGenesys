/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 17:28
 */

#ifndef INTEGRATORDUMMYIMPL_H
#define INTEGRATORDUMMYIMPL_H

#include "Integrator_if.h"

class IntegratorDummyImpl : public Integrator_if {
public:
    IntegratorDummyImpl();
    IntegratorDummyImpl(const IntegratorDummyImpl& orig);
    ~IntegratorDummyImpl();
public:
    void setPrecision(double e);
    double getPrecision();
    double integrate(double min, double max, double (*f)(double, double), double p2);
    double integrate(double min, double max, double (*f)(double, double, double), double p2, double p3);
    double integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4);
    double integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5);
private:
    double _precision = 1e-9;
};

#endif /* INTEGRATORDUMMYIMPL_H */

