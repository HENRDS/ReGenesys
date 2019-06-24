/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntityType.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 19:24
 */

#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <string>
#include "ModelElement.h"
#include "StatisticsCollector.h"
#include "ElementManager.h"
#include "Plugin.h"

//#include "Model.h"

class EntityType : public ModelElement {
public:
    EntityType(ElementManager* elemManager);
    EntityType(ElementManager* elemManager, std::string name);
    EntityType(const EntityType& orig);
    virtual ~EntityType();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields);
public: //get & set
    void setInitialWaitingCost(double _initialWaitingCost);
    double getInitialWaitingCost() const;
    void setInitialOtherCost(double _initialOtherCost);
    double getInitialOtherCost() const;
    void setInitialNVACost(double _initialNVACost);
    double getInitialNVACost() const;
    void setInitialVACost(double _initialVACost);
    double getInitialVACost() const;
    void setInitialPicture(std::string _initialPicture);
    std::string getInitialPicture() const;
public: //get
    StatisticsCollector* getCstatTotalTime() const;
    StatisticsCollector* getCstatNVATime() const;
    StatisticsCollector* getCstatVATime() const;
    StatisticsCollector* getCstatOtherTime() const;
    StatisticsCollector* getCstatTransferTime() const;
    StatisticsCollector* getCstatWaitingTime() const;

protected: // must be overriden by derived classes
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

private:
    void _initCostsAndStatistics();
private:
    std::string _initialPicture = "report";
    double _initialVACost = 0.0;
    double _initialNVACost = 0.0;
    double _initialOtherCost = 0.0;
    double _initialWaitingCost = 0.0;
private:
    ElementManager* _elemManager;
    StatisticsCollector* _cstatWaitingTime; //  = new StatisticsCollector("Waiting Time");
    StatisticsCollector* _cstatTransferTime; //  = new StatisticsCollector("Transfer Time");
    StatisticsCollector* _cstatOtherTime; //  = new StatisticsCollector("Other Time");
    StatisticsCollector* _cstatVATime; //  = new StatisticsCollector("Value Added Time");
    StatisticsCollector* _cstatNVATime; //  = new StatisticsCollector("Non Value Added Time");
    StatisticsCollector* _cstatTotalTime; //  = new StatisticsCollector("Time In System");
};

#endif /* ENTITYTYPE_H */

