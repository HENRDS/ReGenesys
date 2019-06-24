/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysGUI.h
 * Author: rafael.luiz.cancian
 *
 * Created on 23 de Maio de 2019, 13:03
 */

#ifndef GENESYSGUI_H
#define GENESYSGUI_H

#include "GenesysApplication_if.h"

class GenesysGUI : public GenesysApplication_if {
public:
    GenesysGUI();
    GenesysGUI(const GenesysGUI& orig);
    virtual ~GenesysGUI();
public:
    virtual int main(int argc, char** argv);
};

#endif /* GENESYSGUI_H */

