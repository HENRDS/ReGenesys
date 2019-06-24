/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitterDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 20 de Maio de 2019, 20:48
 */

#ifndef FITTERDEFAULTIMPL1_H
#define FITTERDEFAULTIMPL1_H

#include "Fitter_if.h"

class FitterDefaultImpl1 : public Fitter_if {
public:
    FitterDefaultImpl1();
    FitterDefaultImpl1(const FitterDefaultImpl1& orig);
    virtual ~FitterDefaultImpl1();
public:
    bool isNormalDistributed(double confidencelevel);
    void fitUniform(double *sqrerror, double *min, double *max);
    void fitTriangular(double *sqrerror, double *min, double *mo, double *max);
    void fitNormal(double *sqrerror, double *avg, double *stddev);
    void fitExpo(double *sqrerror, double *avg1);
    void fitErlang(double *sqrerror, double *avg, double *m);
    void fitBeta(double *sqrerror, double *alpha, double *beta, double *infLimit, double *supLimit);
    void fitWeibull(double *sqrerror, double *alpha, double *scale);
    void fitAll(double *sqrerror, std::string *name);
public:
    void setDataFilename(std::string dataFilename);
    std::string getDataFilename();
private:
    std::string _dataFilename = "";
};

#endif /* FITTERDEFAULTIMPL1_H */

