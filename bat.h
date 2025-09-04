#pragma once
#include "creature.h"
#include <string>
#include <iostream>

// Klasa Bat dziedziczy wirtualnie po Creature, dodaje skrzydła i prędkość lotu

class Bat : public virtual Creature {
protected:
    int wingSpan;      // rozpiętość skrzydeł
    int flightSpeed;   // prędkość lotu
public:
    Bat(std::string name, int wingSpan, int flightSpeed)
        : Creature(name, 40), wingSpan(wingSpan), flightSpeed(flightSpeed) {}

    void introduce() const override { // wypisuje informacje o nietoperzu
        Creature::introduce();
        std::cout << "I am a bat with wingspan " << wingSpan
                  << " and flight speed " << flightSpeed << ".\n";
    }

    void changeFlightSpeed(int speed) {
        flightSpeed = speed;
    }

    void attack(Creature* opponent) override { // atakuje, odbierając 5 HP
        opponent->decreaseHealth(5);
    }

    std::string toString() const override { // zwraca opis nietoperza jako string
        return "Bat(" + Creature::toString() +
               ", wingspan: " + std::to_string(wingSpan) +
               ", flightSpeed: " + std::to_string(flightSpeed) + ")";
    }
};