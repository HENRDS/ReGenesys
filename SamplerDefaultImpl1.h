/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 01:10
 */

#ifndef SAMPLERDEFAULTIMPL1_H
#define SAMPLERDEFAULTIMPL1_H

#include "Sampler_if.h"

class SamplerDefaultImpl1 : public Sampler_if {
public:

    struct DefaultImpl1RNG_Parameters : public RNG_Parameters {
	unsigned int seed = 666;
	unsigned int module = 2147483647;
	unsigned int multiplier = 950706376;
	~DefaultImpl1RNG_Parameters() = default;
    };
public:
    SamplerDefaultImpl1();
    SamplerDefaultImpl1(const SamplerDefaultImpl1& orig);
    virtual ~SamplerDefaultImpl1();
public: // probability distributions
    virtual double random();
    virtual double sampleUniform(double min, double max);
    virtual double sampleExponential(double mean);
    virtual double sampleErlang(double mean, int M);
    virtual double sampleNormal(double mean, double stddev);
    virtual double sampleGamma(double mean, double alpha);
    virtual double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
    virtual double sampleWeibull(double alpha, double scale);
    virtual double sampleLogNormal(double mean, double stddev);
    virtual double sampleTriangular(double min, double mode, double max);
    virtual double sampleDiscrete(double value, double acumProb, ...);
public:
    void reset(); ///< reinitialize seed and other parameters so (pseudo) random number sequence will be generated again.
public:
    virtual void setRNGparameters(RNG_Parameters* param);
    virtual RNG_Parameters* getRNGparameters() const;
private:
    RNG_Parameters* _param = new DefaultImpl1RNG_Parameters();
    unsigned int _seed;
    //bool _normalflag;
};

#endif /* SAMPLERDEFAULTIMPL1_H */

