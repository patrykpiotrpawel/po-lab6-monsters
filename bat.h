#ifndef BAT_H
#define BAT_H

#include "creature.h"

class Bat : public Creature {  // bat dziedziczy po klasie Creature
private:               //pola przechowujace
    int wingSpan;
    int flightSpeed;

public:
    Bat(const std::string& name, int wingSpan, int flightSpeed)
        : Creature(name, 40), wingSpan(wingSpan), flightSpeed(flightSpeed) {} //inicjalizacja pol, maxHealth = 40

    void introduce() const override {
        std::cout << "I am a bat with wingspan " << wingSpan << " and flight speed " << flightSpeed << "." << std::endl; //wyswietlenie infor
    }

    std::string toString() const override {
        return "Bat: " + name; //zwrocenie opisu
    }

    void changeFlightSpeed(int speed) {  //metoda zmieniajaca predkosc lotu
        flightSpeed = speed; // nowa wartosc predkosci lotu
    }

    void attack(Creature* opponent) override {  //metoda attack z klasy creature
        opponent->decreaseHealth(5);   // zmiejszenie zdrowia po ataku nietoperza -5
    }
};

#endif