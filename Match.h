/*
Copyright (C) 2019 Henry R. Da Silva
  Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.  
*/

#ifndef MATCH_H
#define MATCH_H

#include "ModelComponent.h"
#include "Queue.h"

class Match : public ModelComponent {
public:
    enum class MatchType: int {
        Any = 1,
        Attribute,
        Type
    };

    Match(Model* model);
    Match(const Match& orig);
    virtual ~Match() noexcept;
    
    void setType(MatchType newType);
    MatchType getType() const;   
    
    void addQueue(Queue *queue);

    void setAttributeName(std::string name);
    std::string getAttributeName() const;
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected:

    virtual void _execute(Entity* entity);
    virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    void matchAny(unsigned int n, Entity* entity);
    void matchType(unsigned int n, Entity* entity);
    void matchAttribute(unsigned int n, Entity* entity);
    
    std::vector<Queue*> _queues;
    MatchType _type;
    std::string _attributeName;
};


#endif