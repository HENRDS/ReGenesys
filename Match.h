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
    /// @brief Gets the match type
    /// @returns The match type
    MatchType getType() const;   

    /// @brief Add a queue to the component
    /// @param queue a pointer to the queue to be added
    void addQueue(Queue *queue);

    /// @brief Sets the name of the attribute to be matched. Only applies if type is MatchType::Attribute
    /// param name the name of the attribute
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
    /// @brief Method for matching the incoming entities. One entity must reside in each queue for a match to be made. 
    /// @param n connection by which the entity arrived
    /// @param entity current entity
    void matchAny(unsigned int n, Entity* entity);

    /// @brief Method for matching the incoming entities. One entity from the same type must reside in each queue for a match to be made. 
    /// @param n connection by which the entity arrived
    /// @param entity current entity
    void matchType(unsigned int n, Entity* entity);

    /// @brief Method for matching the incoming entities. One entity must reside in each queue with the same attribute value for a match to be made.
    /// @param n connection by which the entity arrived
    /// @param entity current entity
    void matchAttribute(unsigned int n, Entity* entity);
    
    std::vector<Queue*> _queues;
    MatchType _type;
    std::string _attributeName;
};


#endif