/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestParser.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 20:17
 */

#ifndef TESTPARSER_H
#define TESTPARSER_H

#include "GenesysApplication_if.h"

class TestParser : public GenesysApplication_if {
public:
    TestParser();
    TestParser(const TestParser& orig);
    virtual ~TestParser();
public:
    virtual int main(int argc, char** argv);
private:

};

#endif /* TESTPARSER_H */

