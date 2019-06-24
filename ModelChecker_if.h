/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelChecker_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 15:48
 */

#ifndef MODELCHECKER_IF_H
#define MODELCHECKER_IF_H

#include <typeinfo>
#include <string>

//#include "Model.h"
//class Model;

/*!
 * The ModelChecker is responsable for verifying the model consistency, fixing inconsistencies wheneaver possible
 */
class ModelChecker_if {
public:
    virtual bool checkAll() = 0; /*! Invoques all other checks and returns true only if all of them returned true */
    virtual bool checkConnected() = 0; /*! Checks if components are consistently connected to other to form a valid process-oriented model, describing how entities proceed to the flow*/
    virtual bool checkSymbols() = 0; /*! Checks if user-defined strings for symbols required by components, usually expressions or functions, are valid or references existing and valid elements. */
    virtual bool checkActivationCode() = 0; /*! Checks if the installed version has acquired a valid activation code for commercial use */

    //virtual bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) = 0;
};

#endif /* MODELCHECKER_IF_H */

