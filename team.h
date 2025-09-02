#ifndef TEAM_H
#define TEAM_H

#include "creature.h"
#include <vector>
#include <memory>

class Team {
private:
    std::vector<std::unique_ptr<Creature>> creatures;

public:
    void add(Creature* creature) {
        creatures.emplace_back(creature);
    }

    std::vector<Creature*> getLivingCreatures() const {
        std::vector<Creature*> living;
        for (const auto& creature : creatures) {
            if (creature->isAlive()) {
                living.push_back(creature.get());
            }
        }
        return living;
    }

    Creature* getDefender() const {
        for (const auto& creature : creatures) {
            if (creature->isAlive()) {
                return creature.get();
            }
        }
        return nullptr;
    }

    void attack(Team* otherTeam) {
        Creature* defender = otherTeam->getDefender();
        if (defender) {
            for (const auto& attacker : creatures) {
                if (attacker->isAlive()) {
                    attacker->attack(defender);
                    if (!defender->isAlive()) break;
                }
            }
        }
    }

    bool isAtLeastOneAliveMember() const {
        for (const auto& creature : creatures) {
            if (creature->isAlive()) {
                return true;
            }
        }
        return false;
    }

    std::string toString() const {
        std::string result = "Team:\n";
        for (const auto& creature : creatures) {
            result += creature->toString() + "\n";
        }
        return result;
    }
};

#endif