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
