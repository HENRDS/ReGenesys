/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Release.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:17
 */

#ifndef RELEASE_H
#define RELEASE_H

#include <string>

#include "ModelComponent.h"
#include "Resource.h"
#include "Plugin.h"


class Release : public ModelComponent {
public:
    Release(Model* model);
    Release(const Release& orig);
    virtual ~Release();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public: // get & set
    void setPriority(unsigned short _priority);
    unsigned short getPriority() const;
    void setResourceType(Resource::ResourceType _resourceType);
    Resource::ResourceType getResourceType() const;
    void setQuantity(std::string _quantity);
    std::string getQuantity() const;
    void setRule(Resource::ResourceRule _rule);
    Resource::ResourceRule getRule() const;
    void setSaveAttribute(std::string _saveAttribute);
    std::string getSaveAttribute() const;
    void setResource(Resource* _resource);
    Resource* getResource() const;
    // indirect access to and Resource*
    void setResourceName(std::string resourceName) throw();
    std::string getResourceName() const;

protected:
    virtual void _execute(Entity* entity);
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    //	unsigned int _allocationType = 0; // uint ? enum?
    unsigned short _priority = 0;
    Resource::ResourceType _resourceType = Resource::ResourceType::RESOURCE;
    std::string _quantity = "1";
    Resource::ResourceRule _rule = Resource::ResourceRule::SMALLESTBUSY;
    std::string _saveAttribute = "";

private: // no g&s
    Resource* _resource;
};

#endif /* RELEASE_H */

