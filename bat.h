#pragma once
#include "creature.h"
#include <string>
#include <sstream>
#include <iostream>

// Klasa Bat dziedziczy wirtualnie po Creature, dodaje skrzydła i prędkość lotu
class Bat : public virtual Creature {
    int wingspan;      // rozpiętość skrzydeł
    int flightSpeed;   // prędkość lotu
public:
    Bat(const std::string& name, int wingspan, int flightSpeed)
        : Creature(name, 40), wingspan(wingspan), flightSpeed(flightSpeed) {}

    void introduce() const override { // wypisuje informacje o nietoperzu
        Creature::introduce();
        std::cout << "I am a bat with wingspan " << wingspan << " and flight speed " << flightSpeed << ".\n";
    }

    void attack(Creature* target) override { // atakuje, odbierając 13% max HP
        target->decreaseHealth(static_cast<int>(getMaxHealth() * 0.13));
    }

    std::string toString() const override { // zwraca opis nietoperza jako string
        std::ostringstream oss;
        oss << "Bat(" << Creature::toString()
            << ", wingspan: " << wingspan
            << ", flightSpeed: " << flightSpeed << ")";
        return oss.str();
    }

    void changeFlightSpeed(int newSpeed) { // zmienia prędkość lotu
        flightSpeed = newSpeed;
    }