/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfo.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 18:13
 */

#ifndef MODELINFO_H
#define MODELINFO_H

#include <string>
#include "Util.h"

/*!
 * ModelInfo stores basic model project information.
 */
class ModelInfo {
public:
    ModelInfo();
    ModelInfo(const ModelInfo& orig);
    virtual ~ModelInfo();
public:
    std::string show();
public: // gets and sets
    void setName(std::string _name);
    std::string getName() const;
    void setAnalystName(std::string _analystName);
    std::string getAnalystName() const;
    void setDescription(std::string _description);
    std::string getDescription() const;
    void setProjectTitle(std::string _projectTitle);
    std::string getProjectTitle() const;
    void setVersion(std::string _version);
    std::string getVersion() const;
    void setNumberOfReplications(unsigned int _numberOfReplications);
    unsigned int getNumberOfReplications() const;
    void setReplicationLength(double _replicationLength);
    double getReplicationLength() const;
    void setReplicationLengthTimeUnit(Util::TimeUnit _replicationLengthTimeUnit);
    Util::TimeUnit getReplicationLengthTimeUnit() const;
    void setWarmUpPeriod(double _warmUpPeriod);
    double getWarmUpPeriod() const;
    void setWarmUpPeriodTimeUnit(Util::TimeUnit _warmUpPeriodTimeUnit);
    Util::TimeUnit getWarmUpPeriodTimeUnit() const;
    void setTerminatingCondition(std::string _terminatingCondition);
    std::string getTerminatingCondition() const;
public:
    void loadInstance(std::map<std::string, std::string>* fields);
    std::map<std::string, std::string>* saveInstance();
private: // with public access (get & set)
    // model general information
    std::string _name;
    std::string _analystName = "";
    std::string _description = "";
    std::string _projectTitle = "";
    std::string _version = "1.0";

    // replication and warmup duration
    unsigned int _numberOfReplications = 1;
    double _replicationLength = 60.0; // by default, 60 s
    Util::TimeUnit _replicationLengthTimeUnit = Util::TimeUnit::second;
    double _warmUpPeriod = 0.0;
    Util::TimeUnit _warmUpPeriodTimeUnit = Util::TimeUnit::second;
    std::string _terminatingCondition = "";
};

#endif /* MODELINFO_H */

