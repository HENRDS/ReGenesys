#include <exception>
#include "Match.h"
#include "Model.h"
#include "Attribute.h"




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
    bool isOk = true;
    if (this->_type == MatchType::Attribute) {
        isOk = isOk || (!this->_attributeName.empty() && 
            this->_model->getElementManager()->getElement(Util::TypeOf<Attribute>(), this->_attributeName) != nullptr);
    }
    // TODO: Check if we have the same number of inputs and outputs, this is not possible currently because we don't have a way to get the input count 
    return true;
}

PluginInformation* Match::GetPluginInformation(){
    return new PluginInformation(Util::TypeOf<Match>(), &Match::LoadInstance);
}
void Match::matchAny(unsigned int n, Entity* entity) {
    for (int i = 0; i < this->_queues.size(); ++i) {
        if (i == n) continue;
        if (this->_queues[i]->size() == 0)
            return;
    }

    for (int i = 0; i < this->_queues.size(); ++i) {
        Connection *connection = this->getNextComponents()->getConnectionAtRank(i);
        if (i == n) { 
            this->_model->sendEntityToComponent(entity, connection, 0);
        } else {
            Waiting *waiting = this->_queues[i]->first();
            this->_queues[i]->removeElement(waiting);
            this->_model->sendEntityToComponent(waiting->getEntity(), connection, 0);
        }
    }
}

void Match::matchType(unsigned int n, Entity* entity) {
    std::vector<Waiting*> items(this->_queues.size());
    for (int i = 0; i < this->_queues.size(); ++i) {
        if (i == n) {
            items.push_back(nullptr);
            continue;
        } 

        Waiting* selected = nullptr;
        for (int j = 0; j < this->_queues[i]->size(); ++j) {
            Waiting* current = this->_queues[i]->getAtRank(j); 
            if (current->getEntity()->getEntityType()->getId() == entity->getEntityType()->getId()) {
                selected = current;
                break;
            }
        }
        if (selected == nullptr) 
            break;
        else 
            items.push_back(selected);
    }

    if (items.size() < this->_queues.size()) {
        this->_queues[n]->insertElement(new Waiting(entity, this, this->_model->getSimulation()->getSimulatedTime()));
        return;
    }

    for (int i = 0; i < this->_queues.size(); ++i) {
        if (items[i] == nullptr) {
            this->_model->sendEntityToComponent(entity, this->getNextComponents()->getConnectionAtRank(i), 0);
        } else {
            this->_queues[i]->removeElement(items[i]);
            this->_model->sendEntityToComponent(items[i]->getEntity(), this->getNextComponents()->getConnectionAtRank(i), 0);
        }
    }

}

void Match::matchAttribute(unsigned int n, Entity* entity) {
    std::vector<Waiting*> items(this->_queues.size());
    for (int i = 0; i < this->_queues.size(); ++i) {
        if (i == n) {
            items.push_back(nullptr);
            continue;
        } 

        Waiting* selected = nullptr;
        for (int j = 0; j < this->_queues[i]->size(); ++j) {
            Waiting* current = this->_queues[i]->getAtRank(j); 
            if (current->getEntity()->getAttributeValue(this->_attributeName) == entity->getAttributeValue(this->_attributeName)) {
                selected = current;
                break;
            }
        }
        if (selected == nullptr) 
            break;
        else 
            items.push_back(selected);
    }

    if (items.size() < this->_queues.size()) {
        this->_queues[n]->insertElement(new Waiting(entity, this, this->_model->getSimulation()->getSimulatedTime()));
        return;
    }

    for (int i = 0; i < this->_queues.size(); ++i) {
        if (items[i] == nullptr) {
            this->_model->sendEntityToComponent(entity, this->getNextComponents()->getConnectionAtRank(i), 0);
        } else {
            this->_queues[i]->removeElement(items[i]);
            this->_model->sendEntityToComponent(items[i]->getEntity(), this->getNextComponents()->getConnectionAtRank(i), 0);
        }
    }
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