#pragma once
#include "creature.h"
#include <string>
#include <iostream>

class Human : public virtual Creature {
protected:
    std::string occupation;
    int bornYear;
public:
    Human(std::string name, std::string occupation, int bornYear)
        : Creature(name, 100), occupation(occupation), bornYear(bornYear) {}

    int getAge() const {
        return 2025 - bornYear;
    }

    void introduce() const override {
        Creature::introduce();
        std::cout << "I am a " << occupation << " and I am " << getAge() << " years old.\n";
    }

    void attack(Creature* opponent) override {
        opponent->decreaseHealth(10);
    }

    std::string toString() const override {
        return "Human(" + Creature::toString() +
               ", occupation: " + occupation +
               ", bornYear: " + std::to_string(bornYear) + ")";
    }
};