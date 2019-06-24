/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SourceModelCOmponent.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:50
 */

#ifndef SOURCEMODELCOMPONENT_H
#define SOURCEMODELCOMPONENT_H

#include "ModelComponent.h"
#include <string>
#include <limits>
//#include <numeric_limits>

/*!
 * A source component implements the base for inserting entities into the model when its simulation is initialized. 
 * During the initialization, the new and empty future events list is populated by events of creating entities and 
 * sending them to the source components existing in the model
 */
class SourceModelComponent : public ModelComponent {
public:
    SourceModelComponent(Model* model, std::string componentTypename);
    SourceModelComponent(const SourceModelComponent& orig);
    virtual ~SourceModelComponent();
public: // get & set
    void setFirstCreation(double _firstCreation);
    double getFirstCreation() const;
    void setCollectStatistics(bool _collectStatistics);
    bool isCollectStatistics() const;
    void setEntityType(EntityType* _entityType);
    EntityType* getEntityType() const;
    void setTimeUnit(Util::TimeUnit _timeUnit);
    Util::TimeUnit getTimeUnit() const;
    void setTimeBetweenCreationsExpression(std::string _timeBetweenCreations);
    std::string getTimeBetweenCreationsExpression() const;
    void setMaxCreations(std::string _maxCreationsExpression);
    std::string getMaxCreations() const;
    unsigned int getEntitiesCreated() const;
    void setEntitiesCreated(unsigned int _entitiesCreated);
    void setEntitiesPerCreation(unsigned int _entitiesPerCreation);
    unsigned int getEntitiesPerCreation() const;
public:
    virtual std::string show();
protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
protected: // get & set
    EntityType* _entityType;
    double _firstCreation = 0.0;
    unsigned int _entitiesPerCreation = 1;
    std::string _maxCreationsExpression = std::to_string(std::numeric_limits<unsigned int>::max()); // std::numeric_limits<unsigned int>::max();
    std::string _timeBetweenCreationsExpression = "EXPO(1)"; ////
    Util::TimeUnit _timeBetweenCreationsTimeUnit = Util::TimeUnit::second;
    //bool _collectStatistics = true;
    unsigned int _entitiesCreatedSoFar = 0;
};

#endif /* SOURCEMODELCOMPONENT_H */

