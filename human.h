#ifndef HUMAN_H
#define HUMAN_H

#include "creature.h"

class Human : public Creature {
private:
    std::string occupation;
    int bornYear;

public:
    Human(const std::string& name, const std::string& occupation, int bornYear)
        : Creature(name, 100), occupation(occupation), bornYear(bornYear) {}

    void introduce() const override {
        std::cout << "I am a human, my occupation is " << occupation << "." << std::endl;
    }

    int getAge() const {
        return 2025 - bornYear;
    }

    std::string toString() const override {
        return "Human: " + name;
    }

    void attack(Creature* opponent) override {  //metoda attack z klasy creature
        opponent->decreaseHealth(10); // zmiejszenie zdrowia po ataku czlowieka -10
    }
};

#endif