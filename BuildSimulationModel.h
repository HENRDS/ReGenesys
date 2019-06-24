/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buildSimpleModel1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Outubro de 2018, 19:18
 */

#ifndef BUILDSIMPLEMODEL1_H
#define BUILDSIMPLEMODEL1_H

#include "GenesysApplication_if.h"
#include "Model.h"

class BuildSimulationModel : public GenesysApplication_if {
public:
    BuildSimulationModel();
public:
    virtual int main(int argc, char** argv);
private:
    void buildModel(Model* model);
};

#endif /* BUILDSIMPLEMODEL1_H */

