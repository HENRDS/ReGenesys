/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 00:44
 */

#ifndef INTEGRATORDEFAULTIMPL1_H
#define INTEGRATORDEFAULTIMPL1_H

#include "Integrator_if.h"

class IntegratorDefaultImpl1 : public Integrator_if {
public:
    IntegratorDefaultImpl1();
    IntegratorDefaultImpl1(const IntegratorDefaultImpl1& orig);
    virtual ~IntegratorDefaultImpl1();
public:
    virtual void setPrecision(double e);
    virtual double getPrecision();
    virtual double integrate(double min, double max, double (*f)(double, double), double p2);
    virtual double integrate(double min, double max, double (*f)(double, double, double), double p2, double p3);
    virtual double integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4);
    virtual double integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5);
private:
    double _precision;
};

#endif /* INTEGRATORDEFAULTIMPL1_H */

