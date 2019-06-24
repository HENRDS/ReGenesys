/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserDummyImpl.h
 * Author: rafael.luiz.cancian
 *
 * Created on 22 de Agosto de 2018, 08:45
 */

#ifndef PARSERDUMMYIMPL_H
#define PARSERDUMMYIMPL_H

#include <string>
#include "Parser_if.h"

class Model;

class ParserDummyImpl : public Parser_if {
public:
    ParserDummyImpl(Model* model);
    ParserDummyImpl(const ParserDummyImpl& orig);
    virtual ~ParserDummyImpl();
public:
    double parse(const std::string expression); // may throw exception
    double parse(const std::string expression, bool* success, std::string* errorMessage);
    std::string* getErrorMessage();
private:
    Model* _model;
};

#endif /* PARSERDUMMYIMPL_H */

