/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.h
 * Author: rafael.luiz.cancian
 *
 * Created on 4 de Setembro de 2018, 18:28
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"


class Variable : public ModelElement {
public:
    Variable();
    Variable(std::string name);
    Variable(const Variable& orig);
    virtual ~Variable();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields);
public:
    double getValue();
    double getValue(std::string index);
    void setValue(double value);
    void setValue(std::string index, double value);

protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

private:
    unsigned int _numRows = 1;
    unsigned int _numCols = 1;
    std::map<std::string, double>* _values = new std::map<std::string, double>();
};

#endif /* VARIABLE_H */

