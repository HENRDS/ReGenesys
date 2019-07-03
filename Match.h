#ifndef MATCH_H
#define MATCH_H

#include "ModelComponent.h"
#include "Queue.h"

class Match : public ModelComponent {
public:
    enum class MatchType {
        Attribute,
        Any
    };
    Match(Model* model);
    Match(const Match& orig);
    virtual ~Match() noexcept;
    
    void setType(MatchType newType);
    MatchType getType() const;  
    void setQueueCount(unsigned int count);
    unsigned int getQueueCount() const;
    

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
    std::vector<Queue*> _queues;
    unsigned int _queueCount;
    MatchType _type;
};


#endif