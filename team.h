#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "creature.h"

class Team {
    std::vector<Creature*> creatures; // lista wskaźników na stworzenia
public:
    void add(Creature* c) { // dodaje stworzenie do drużyny
        creatures.push_back(c);
    }

    std::vector<Creature*> getLivingCreatures() const { // zwraca żywe stworzenia
        std::vector<Creature*> living;
        for (auto c : creatures) {
            if (c->isAlive()) living.push_back(c);
        }
        return living;
    }

    Creature* getDefender() const { // zwraca pierwszego żywego obrońcę
        for (auto c : creatures) {
            if (c->isAlive()) return c;
        }
        return nullptr;
    }

    void attack(Team* other) { // atakuje drużynę przeciwną (tylko ten sam typ)
        auto attackers = getLivingCreatures();
        auto defenders = other->getLivingCreatures();
        size_t n = std::min(attackers.size(), defenders.size());
        for (size_t i = 0; i < n; ++i) {
            if (typeid(*attackers[i]) == typeid(*defenders[i])) {
                attackers[i]->attack(defenders[i]);
            }
        }
    }

    bool isAlive() const { // czy drużyna żyje
        for (auto c : creatures) {
            if (c->isAlive()) return true;
        }
        return false;
    }

    std::string toString() const { // opis drużyny jako string
        std::ostringstream oss;
        oss << "Team(";
        for (size_t i = 0; i < creatures.size(); ++i) {
            oss << creatures[i]->toString();
            if (i + 1 < creatures.size())
                oss << ", ";
        }
        oss << ")";
        return oss.str();
    }
};