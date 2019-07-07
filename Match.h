
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