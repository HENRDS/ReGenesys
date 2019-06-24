/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Record.h
 * Author: rafael.luiz.cancian
 *
 * Created on 9 de Agosto de 2018, 13:52
 */

#ifndef RECORD_H
#define RECORD_H

#include "ModelComponent.h"
#include <string>

class Record : public ModelComponent {
public:
    Record(Model* model);
    Record(const Record& orig);
    virtual ~Record();
public:
    void setFilename(std::string filename);
    std::string getFilename() const;
    void setExpression(std::string expression);
    std::string getExpression() const;
    void setExpressionName(std::string expressionName);
    std::string getExpressionName() const;
    StatisticsCollector* getCstatExpression() const;
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
    std::string _expression = "";
    std::string _expressionName = "";
    std::string _filename = "";
private:
    StatisticsCollector* _cstatExpression; /* TODO: Cretae an internal class to agregate ExpressionStatisticsColelctor, and change Record to got a list of it, so Record cn record a set of expressions into a set of files */
};

#endif /* RECORD_H */

