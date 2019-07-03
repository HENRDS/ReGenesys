/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 17:12
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "ModelElement.h"
#include "List.h"
#include "Entity.h"
#include "Waiting.h"
#include "ElementManager.h"
#include "StatisticsCollector.h"
#include "Plugin.h"


class Queue : public ModelElement {
public:

    enum class OrderRule : int {
	FIFO = 1, LIFO = 2, HIGHESTVALUE = 3, SMALLESTVALUE = 4
    };

public:
    Queue(ElementManager* elems);
    Queue(ElementManager* elems, std::string name);
    Queue(const Queue& orig);
    virtual ~Queue();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields);
public:
    void insertElement(Waiting* element);
    void removeElement(Waiting* element);
    unsigned int size();
    Waiting* first();
    Waiting* getAtRank(unsigned int rank);
    void setAttributeName(std::string _attributeName);
    std::string getAttributeName() const;
    void setOrderRule(OrderRule _orderRule);
    Queue::OrderRule getOrderRule() const;
    //List<Waiting*>* getList() const; // can't give direct access so Queue can collect statistics

public: 
    void initBetweenReplications();
protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    void _initCStats();
private:
    ElementManager* _elems;
private: //1::n
    List<Waiting*>* _list = new List<Waiting*>();
private: //1::1
    StatisticsCollector* _cstatNumberInQueue; // = new StatisticsCollector("Number In Queue");
    StatisticsCollector* _cstatTimeInQueue; // = new StatisticsCollector("Time In Queue ");
    OrderRule _orderRule = OrderRule::FIFO;
    std::string _attributeName = "";
};

#endif /* QUEUE_H */

