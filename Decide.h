/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decide.h
 * Author: rafael.luiz.cancian
 *
 * Created on 9 de Agosto de 2018, 20:39
 */

#ifndef DECIDE_H
#define DECIDE_H

#include "ModelComponent.h"

class Decide : public ModelComponent {
public:
    Decide(Model* model);
    Decide(const Decide& orig);
    virtual ~Decide();
public:
    List<std::string>* getConditions() const;

public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected:
    virtual void _execute(Entity* entity);
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    List<std::string>* _conditions = new List<std::string>();
private:

};

#endif /* DECIDE_H */

