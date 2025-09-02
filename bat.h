#pragma once
#include "creature.h"
#include <string>
#include <sstream>
#include <iostream>

class Bat : public virtual Creature {
    int wingspan;
    int flightSpeed;
public:
    Bat(const std::string& name, int wingspan, int flightSpeed)
        : Creature(name, 40), wingspan(wingspan), flightSpeed(flightSpeed) {}

    void introduce() const override {
        Creature::introduce();
        std::cout << "I am a bat with wingspan " << wingspan << " and flight speed " << flightSpeed << ".\n";
    }

    void attack(Creature* target) override {
        target->decreaseHealth(static_cast<int>(getMaxHealth() * 0.13));
    }

    std::string toString() const override {
        std::ostringstream oss;
        oss << "Bat(" << Creature::toString()
            << ", wingspan: " << wingspan
            << ", flightSpeed: " << flightSpeed << ")";
        return oss.str();
    }

    void changeFlightSpeed(int newSpeed) {
        flightSpeed = newSpeed;
    }
};