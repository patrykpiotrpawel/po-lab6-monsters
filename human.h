#pragma once
#include "creature.h"
#include <string>
#include <iostream>
#include <sstream>

class Human : public virtual Creature { // klasa Human dziedziczy wirtualnie po Creature
    std::string occupation; // zawód
    int bornYear;           // rok urodzenia
public:
    Human(const std::string& name, const std::string& occupation, int bornYear)
        : Creature(name, 100), occupation(occupation), bornYear(bornYear) {}

    int getAge() const { // zwraca wiek
        return 2025 - bornYear;
    }

    void introduce() const override { // wypisuje informacje o człowieku
        Creature::introduce();
        std::cout << "I am a " << occupation << " and I am " << getAge() << " years old.\n";
    }

    void attack(Creature* target) override { // atakuje, odbierając 10% max HP
        target->decreaseHealth(static_cast<int>(getMaxHealth() * 0.1));
    }

    std::string toString() const override { // zwraca opis człowieka jako string
        std::ostringstream oss;
        oss << "Human(" << Creature::toString()
            << ", occupation: " << occupation
            << ", bornYear: " << bornYear << ")";
        return