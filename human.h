#pragma once
#include "creature.h"
#include <string>
#include <iostream>
#include <sstream>

class Human : public virtual Creature {
    std::string occupation;
    int bornYear;
public:
    Human(const std::string& name, const std::string& occupation, int bornYear)
        : Creature(name, 100), occupation(occupation), bornYear(bornYear) {}

    int getAge() const {
        return 2025 - bornYear;
    }

    void introduce() const override {
        Creature::introduce();
        std::cout << "I am a " << occupation << " and I am " << getAge() << " years old.\n";
    }

    void attack(Creature* target) override {
        target->decreaseHealth(static_cast<int>(getMaxHealth() * 0.1));
    }

    std::string toString() const override {
        std::ostringstream oss;
        oss << "Human(" << Creature::toString()
            << ", occupation: " << occupation
            << ", bornYear: " << bornYear << ")";
        return oss.str();
    }
};