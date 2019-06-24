/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.h
 * Author: rafael.luiz.cancian
 *
 * Created on 31 de Agosto de 2018, 10:10
 */

#ifndef ASSIGN_H
#define ASSIGN_H

#include "ModelComponent.h"
#include "Model.h"
#include "Plugin.h"


class Assign : public ModelComponent {
public:

    /* TODO: +- an enun is not a good idea. Should be a list of possible classes, so TypeOf could be set */
    enum class DestinationType : int {
	Attribute=0, Variable=1
    };

    /*!
     * While the assign class allows you to perform multiple assignments, the assignment class defines an assignment itself.
     */
    class Assignment {
    public:

	Assignment(DestinationType destinationType, std::string destination, std::string expression) {
	    this->_destinationType = destinationType;
	    this->_destination = destination;
	    this->_expression = expression;
	    // an assignment is always in the form:
	    // (destinationType) destination = expression
	};
    public:

	void setDestination(std::string _destination) {
	    this->_destination = _destination;
	}

	std::string getDestination() const {
	    return _destination;
	}

	void setDestinationType(DestinationType _destinationType) {
	    this->_destinationType = _destinationType;
	}

	DestinationType getDestinationType() const {
	    return _destinationType;
	}

	void setExpression(std::string _expression) {
	    this->_expression = _expression;
	}

	std::string getExpression() const {
	    return _expression;
	}
    private:
	DestinationType _destinationType = DestinationType::Attribute;
	std::string _destination = "";
	std::string _expression = "";

    };
public:
    Assign(Model* model);
    Assign(const Assign& orig);
    virtual ~Assign();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
    List<Assignment*>* getAssignments() const;
protected:
    virtual void _execute(Entity* entity);
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
private:
    List<Assignment*>* _assignments = new List<Assignment*>();
};

#endif /* ASSIGN_H */

