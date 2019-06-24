/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Agosto de 2018, 15:57
 */

#ifndef PARSER_IF_H
#define PARSER_IF_H

#include <string>

class Parser_if {
public:
    virtual double parse(const std::string expression) = 0; // may throw exception
    virtual double parse(const std::string expression, bool* success, std::string* errorMessage) = 0; // does not throw exceptions
    virtual std::string* getErrorMessage() = 0; // to get error message in the case of thrown exception
    // ...?
};

#endif /* PARSER_IF_H */

