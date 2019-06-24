/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 01:25
 */

#ifndef PARSERDEFAULTIMPL1_H
#define PARSERDEFAULTIMPL1_H

#include "Parser_if.h"

class Model;

class ParserDefaultImpl1 : public Parser_if {
public:
    ParserDefaultImpl1(Model* model);
    ParserDefaultImpl1(const ParserDefaultImpl1& orig);
    virtual ~ParserDefaultImpl1();
public:
    double parse(const std::string expression); // may throw exception
    double parse(const std::string expression, bool* success, std::string* errorMessage);
    std::string* getErrorMessage();
private:
    Model* _model;
};

#endif /* PARSERDEFAULTIMPL1_H */

