#pragma once

#include "human.h"
#include "bat.h"
#include <string>
#include <iostream>

class Vampire : public Human, public Bat {
public:
    Vampire(std::string name, std::string occupation, int wingSpan, int flightSpeed)
        : Creature(name, 1000), Human(name, occupation, 1897), Bat(name, wingSpan, flightSpeed) {}

    void introduce() const override {
        Human::introduce();
        Bat::introduce();
        std::cout << "I am a vampire.\n";
    }

    void suckBlood() const {
        std::cout << "Sucking blood...\n";
    }

    void attack(Creature* opponent) override {
        Human* humanOpponent = dynamic_cast<Human*>(opponent);
        if (humanOpponent) {
            if (humanOpponent->getHealthPercentage() < 50)
                opponent->decreaseHealth(opponent->getHealthPercentage());
            else
                opponent->decreaseHealth(10);
        } else {
            opponent->decreaseHealth(10);
        }
    }

    std::string toString() const override {
        // format oczekiwany przez testy:
        // Vampire(Creature(name: NAME, health: H, maxHealth: M), Human(Creature(...), occupation: OCC, bornYear: Y), Bat(Creature(...), wingspan: W, flightSpeed: S))
        std::string c = Creature::toString();
        std::string h = std::string("Human(") + c + ", occupation: " + occupation + ", bornYear: " + std::to_string(bornYear) + ")";
        std::string b = std::string("Bat(") + c + ", wingspan: " + std::to_string(wingSpan) + ", flightSpeed: " + std::to_string(flightSpeed) + ")";
        return std::string("Vampire(") + c + ", " + h + ", " + b + ")";
    }
};