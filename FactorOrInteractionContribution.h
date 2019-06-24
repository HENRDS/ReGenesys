/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactorOrInteractionContribution.h
 * Author: rafael.luiz.cancian
 *
 * Created on 10 de Outubro de 2018, 20:08
 */

#ifndef FACTORORINTERACTIONCONTRIBUTION_H
#define FACTORORINTERACTIONCONTRIBUTION_H

#include <list>
#include "SimulationControl.h"

/*!
 * This simple class corresponds to a factor when it refers to just one SimulationControl, or to the interaction between two or more factors when it refers to more SimulationControl. It also encapsulates the contribution of the factor or interaction and its coefficient in the full model that estimates one specific SimulationResponse. 
 */
class FactorOrInteractionContribution {
public:
    FactorOrInteractionContribution(double contribution, double modelCoefficient, std::list<SimulationControl*>* controls);
    FactorOrInteractionContribution(const FactorOrInteractionContribution& orig);
    ~FactorOrInteractionContribution();
public:
    double getModelCoefficient() const;
    std::list<SimulationControl*>* getControls() const;
    double getContribution() const;
private:
    double _contribution;
    double _modelCoefficient;
    std::list<SimulationControl*>* _controls;
};

#endif /* FACTORORINTERACTIONCONTRIBUTION_H */

