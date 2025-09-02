#pragma once

#include "human.h"
#include "bat.h"
#include <string>
#include <iostream>
#include <cmath>

class Vampire : public Human, public Bat { // klasa Vampire dziedziczy po Human i Bat
public:
    Vampire(const std::string& name, const std::string& occupation, int wingspan, int flightSpeed)
        : Creature(name, 1000), Human(name, occupation, 1897), Bat(name, wingspan, flightSpeed) {} // konstruktor

    void introduce() const override { // wypisuje informacje o wampirze
        Human::introduce();
        Bat::introduce();
        std::cout << "I am a vampire." << std::endl;
    }

    void attack(Creature* target) override { // atakuje inne stworzenia
        Human* humanTarget = dynamic_cast<Human*>(target);
        if (humanTarget) {
            if (humanTarget->getHealthPercentage() > 50) {
                humanTarget->decreaseHealth(static_cast<int>(humanTarget->getMaxHealth() * 0.1));
            } else {
                humanTarget->decreaseHealth(humanTarget->getMaxHealth());
            }
        } else {
            if (target->getHealthPercentage() > 50) {
                target->decreaseHealth(static_cast<int>(target->getMaxHealth() * 0.25));
            } else {
                int expectedHP = static_cast<int>(std::round(target->getMaxHealth() * 0.22));
                int toDecrease = target->getHealth() - expectedHP;
                target->decreaseHealth(toDecrease);
            }
        }
    }

    std::string toString() const override { // zwraca opis wampira jako string
        std::ostringstream oss;
        oss << "Vampire(" << Creature::toString()
            << ", " << Human::toString()
            << ", " << Bat::toString() << ")";
        return oss.str();
    }
};