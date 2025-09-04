#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "creature.h"

class Team {
protected:
    std::vector<Creature*> creatures;
public:
    void add(Creature* creature) {
        creatures.push_back(creature);
    }

    std::vector<Creature*> getLivingCreatures() const {
        std::vector<Creature*> living;
        for (auto c : creatures)
            if (c->isAlive()) living.push_back(c);
        return living;
    }

    Creature* getDefender() const {
        for (auto c : creatures)
            if (c->isAlive()) return c;
        return nullptr;
    }

    void attack(Team* otherTeam) {
        // Każdy żyjący członek tej drużyny atakuje pierwszego żyjącego obrońcę drużyny przeciwnej.
        auto attackers = getLivingCreatures();
        for (auto attacker : attackers) {
            Creature* defender = otherTeam->getDefender();
            if (!defender) break;
            attacker->attack(defender);
        }
    }

    bool isAtLeastOneAlivedMember() const {
        for (auto c : creatures)
            if (c->isAlive()) return true;
        return false;
    }

    bool isAlive() const { // alias używany w testach
        return isAtLeastOneAlivedMember();
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "Team(";
        for (size_t i = 0; i < creatures.size(); ++i) {
            oss << creatures[i]->toString();
            // dopisujemy ", " także po ostatnim elemencie (tak oczekuje test)
            oss << ", ";
        }
        oss << ")";
        return oss.str();
    }
};