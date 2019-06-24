/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyReGenESYsApplication.h
 * Author: rafael.luiz.cancian
 *
 * Created on 20 de Maio de 2019, 21:01
 */

#ifndef MYREGENESYSAPPLICATION_H
#define MYREGENESYSAPPLICATION_H

#include "GenesysApplication_if.h"

#include "Simulator.h"

class MyApp : public GenesysApplication_if {
public:
    MyApp();
    MyApp(const MyApp& orig);
    virtual ~MyApp();
public:
    virtual int main(int argc, char** argv);
private:
    void insertFakePluginsByHand(Simulator* simulator);
    void builAndRunSimulationdModel();
};

#endif /* MYREGENESYSAPPLICATION_H */

