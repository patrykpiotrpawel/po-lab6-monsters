#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Creature {
    std::string name;      // nazwa stworzenia
    int health;            // aktualne zdrowie
    int maxHealth;         // maksymalne zdrowie
public:
    Creature(const std::string& name, int maxHealth = 100)
        : name(name), health(maxHealth), maxHealth(maxHealth) {}

    virtual ~Creature() = default;

    virtual void introduce() const { // wypisuje info o stworzeniu
        std::cout << "I am Creature named " << name << " and I have " << getHealthPercentage() << "% of health.\n";
    }

    virtual void attack(Creature* /*opponent*/) {} // domyślny atak nic nie robi

    virtual std::string toString() const { // zwraca opis stworzenia jako string
        std::ostringstream oss;
        oss << "Creature(name: " << name << ", health: " << health << ", maxHealth: " << maxHealth << ")";
        return oss.str();
    }

    void decreaseHealth(int amount) { // zmniejsza zdrowie o amount
        health -= amount;
        if (health < 0) health = 0;
    }

    int getHealthPercentage() const { // zwraca procent zdrowia
        if (maxHealth == 0) return 0;
        return (health * 100) / maxHealth;
    }

    int getMaxHealth() const { // zwraca max zdrowie
        return maxHealth;
    }

    int getHealth() const { // zwraca aktualne zdrowie
        return health;
    }

    bool isAlive() const { // czy żyje
        return health > 0;
    }

    std::string getName() const { // zwraca nazwę
        return name;
    }
};