/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElementManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 12:48
 */

#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#include <list>
#include <map>
#include "List.h"
#include "ModelElement.h"

class Model;

/*!
 * The ElementManager is responsible for inserting and removing elements (ModelElement) used by components,
 * in a consistent way.
 * TO FIX: No direct access for insertion or deletion should be allow
 */
class ElementManager {
public:
    ElementManager(Model* model);
    ElementManager(const ElementManager& orig);
    virtual ~ElementManager();
public:
    bool insert(std::string infraTypename, ModelElement* infra);
    void remove(std::string infraTypename, ModelElement* infra);
    bool check(std::string infraTypename, ModelElement* infra, std::string expressionName, std::string* errorMessage);
    bool check(std::string infraTypename, std::string infraName, std::string expressionName, bool mandatory, std::string* errorMessage);
    void clear();
public:
    ModelElement* getElement(std::string infraTypename, Util::identitifcation id);
    ModelElement* getElement(std::string infraTypename, std::string name);
    unsigned int getNumberOfElements(std::string infraTypename);
    int getRankOf(std::string infraTypename, std::string name); ///< returns the position (1st position=0) of the element if found, or negative value if not found
    std::list<std::string>* getElementTypenames() const;

    //private:
public:
    // TODO: MUST BE PRIVATE
    List<ModelElement*>* getElements(std::string infraTypename) const;
public:
    void show();
    Model* getModel() const;
private:
    std::map<std::string, List<ModelElement*>*>* _elements;
    Model* _model;
};

#endif /* ELEMENTMANAGER_H */

