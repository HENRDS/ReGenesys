/*
 * File:   Batch.h
 * Author: bruno.hass.gabriel.muller.joao.meyer
 *
 * Created on 16 de Junho de 2019
 */

#ifndef BATCH_H
#define BATCH_H

#include "ModelComponent.h"

class Batch : public ModelComponent {
public:
    Batch(Model* model);
    Batch(const Batch& orig);
    virtual ~Batch();
    virtual std::string show();
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);

    void setBatchSize(unsigned int);
    void setGroupName(std::string groupName);
protected:
    virtual void _execute(Entity* entity);
    virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

    unsigned int _batchSize;
    std::string _groupName;

private:
    unsigned int _remaining;
};

#endif /* BATCH_H */

