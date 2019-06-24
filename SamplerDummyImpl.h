/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 13:08
 */

#ifndef SAMPLERDUMMYIMPL_H
#define SAMPLERDUMMYIMPL_H

#include "Sampler_if.h"

class SamplerDummyImpl : public Sampler_if {
public:

    struct MyRNG_Parameters : public RNG_Parameters {
	unsigned int seed;
	unsigned int module;
	unsigned int multiplier;
	~MyRNG_Parameters() = default;
    };
public:
    SamplerDummyImpl();
    SamplerDummyImpl(const SamplerDummyImpl& orig);
    ~SamplerDummyImpl();
public: // probability distributions
    double random();
    double sampleUniform(double min, double max);
    double sampleExponential(double mean);
    double sampleErlang(double mean, int M);
    double sampleNormal(double mean, double stddev);
    double sampleGamma(double mean, double alpha);
    double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
    double sampleWeibull(double alpha, double scale);
    double sampleLogNormal(double mean, double stddev);
    double sampleTriangular(double min, double mode, double max);
    double sampleDiscrete(double value, double acumProb, ...);
public:
    void setRNGparameters(RNG_Parameters* param);
    RNG_Parameters* getRNGparameters() const;
private:
    MyRNG_Parameters* _param = new MyRNG_Parameters();

};

#endif /* SAMPLERDUMMYIMPL_H */

