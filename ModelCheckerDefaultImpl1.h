/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 8 de Agosto de 2018, 18:44
 */

#ifndef MODELCHECKERDEFAULTIMPL1_H
#define MODELCHECKERDEFAULTIMPL1_H

#include "ModelChecker_if.h"
#include "Model.h"

class ModelCheckerDefaultImpl1 : public ModelChecker_if {
public:
    ModelCheckerDefaultImpl1(Model* model);
    ModelCheckerDefaultImpl1(const ModelCheckerDefaultImpl1& orig);
    virtual ~ModelCheckerDefaultImpl1();
public:
    virtual bool checkAll();
    virtual bool checkConnected();
    virtual bool checkSymbols();
    virtual bool checkActivationCode();
    //virtual bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory);
private:
    bool _recursiveConnectedTo(ModelComponent* comp, List<ModelComponent*>* visited, List<ModelComponent*>* unconnected, bool* drenoFound);
private:
    Model* _model;
};

#endif /* MODELCHECKERDEFAULTIMPL1_H */

