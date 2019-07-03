#include <exception>
#include "Match.h"
#include "Model.h"





Match::Match(Model* model) : ModelComponent(model, Util::TypeOf<Match>()) {

}

Match::Match(const Match& orig) : ModelComponent(orig) {
}

Match::~Match() {
}


void Match::setType(Match::MatchType newType) {
    this->_type = newType;
}

Match::MatchType Match::getType() const {
    return this->_type;
}

std::string Match::show() {
    return ModelComponent::show() + "";
}

ModelComponent* Match::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Match* newComponent = new Match(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void Match::_execute(Entity* entity) {
    unsigned int n = this->_model->getSimulation()->getCurrentInputNumber();
    switch (this->_type)
    {
    case MatchType::Any:
        this->matchAny(n, entity);
        break;
    case MatchType::Attribute:
        this->matchAttribute(n, entity);
        break;
    case MatchType::Type:
        this->matchType(n, entity);
        break;
    }
}

bool Match::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {

    }
    return res;
}

void Match::_initBetweenReplications() {
}

std::map<std::string, std::string>* Match::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); 
    return fields;
}

bool Match::_check(std::string* errorMessage) {
    return true;
}

PluginInformation* Match::GetPluginInformation(){
    return new PluginInformation(Util::TypeOf<Match>(), &Match::LoadInstance);
}
void Match::matchAny(unsigned int n, Entity* entity) {

    std::vector<Waiting*> entities(this->_queues.size());
    for (int i = 0; i < this->_queues.size(); ++i) {
        if (i == n) continue;
        if (this->_queues[i]->size() == 0)
            return;
        entities[i] = this->_queues[i]->first();
    }

    for (int i = 0; i < this->_queues.size(); ++i) {
        if (i == n) continue;
    }

}

void Match::matchType(unsigned int n, Entity* entity) {

}

void Match::matchAttribute(unsigned int n, Entity* entity) {

}

void Match::setQueueCount(unsigned int count) {
    this->_queueCount = count;
}
unsigned int Match::getQueueCount() const {
    return this->_queueCount;
};
void Match::setAttributeName(std::string name) {
    this->_attributeName = std::move(name);
}
std::string Match::getAttributeName() const {
    return this->_attributeName;
}