/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CounterDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 29 de Maio de 2019, 11:24
 */

#ifndef COUNTERDEFAULTIMPL1_H
#define COUNTERDEFAULTIMPL1_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"


class Counter : public ModelElement {
public:
    Counter();
    Counter(std::string name);
    Counter(std::string name, ModelElement* parent);
    Counter(const Counter& orig);
    virtual ~Counter();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields);
public:
    void clear();
    void incCountValue(int value = 1);
    unsigned long getCountValue();
    ModelElement* getParent() const;
protected: // from ModelElement
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    //virtual std::list<std::map<std::string,std::string>*>* _saveInstance(std::string type);
    virtual bool _check(std::string* errorMessage);
private:
    ModelElement* _parent;
    unsigned long _count = 0;
};

#endif /* COUNTERDEFAULTIMPL1_H */

