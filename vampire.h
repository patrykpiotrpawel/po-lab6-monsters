#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "bat.h"

class Vampire : public Bat {
private:
    std::string occupation;

public:
    Vampire(const std::string& name, const std::string& occupation, int wingSpan, int flightSpeed)
        : Bat(name, wingSpan, flightSpeed), occupation(occupation) {}

    void introduce() const override {
        std::cout << "I am a vampire, my occupation is " << occupation << "." << std::endl;
    }

    void suckBlood() {
        health += 10;
        if (health > maxHealth) health = maxHealth;
    }

    std::string toString() const override {
        return "Vampire: " + name;
    }

    void attack(Creature* opponent) override {
        opponent->decreaseHealth(10);
    }
};

#endif