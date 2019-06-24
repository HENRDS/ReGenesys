/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProbDistrib_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 00:32
 */

#ifndef PROBDISTRIB_IF_H
#define PROBDISTRIB_IF_H

class ProbDistrib {
public:
    static double uniform(double x, double min, double max);
    static double exponential(double x, double mean);
    static double erlang(double x, double mean, double M); // int M
    static double normal(double x, double mean, double stddev);
    static double gamma(double x, unsigned int alpha, double beta);
    //static double gamma(double x, double k, double theta);
    static double beta(double x, double alpha, double beta);
    static double weibull(double x, double alpha, double scale);
    static double logNormal(double x, double mean, double stddev);
    static double triangular(double x, double min, double mode, double max);
    static double tStudent(double x, double mean, double stddev, unsigned int degreeFreedom);
    static double fFisher(double x, double k, double m);
    static double chi2(double x, double m);
    // inverse
    static double inverseNormal(double cumulativeProbability, double mean, double stddev);
    static double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);
    static double inverseFSnedecor(double cumulativeProbability, double u, double v);
    static double inverseChi2(double cumulativeProbability, double m);
public:
    //static double _gammaFunction(unsigned int x);
    static long double _gammaFunction(double z); //TODO: HOW???

};

#endif /* PROBDISTRIB_IF_H */

