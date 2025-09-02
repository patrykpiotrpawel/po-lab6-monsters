#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Creature {
    std::string name;
    int health;
    int maxHealth;
public:
    Creature(const std::string& name, int maxHealth = 100)
        : name(name), health(maxHealth), maxHealth(maxHealth) {}

    virtual ~Creature() = default;

    virtual void introduce() const {
        std::cout << "I am Creature named " << name << " and I have " << getHealthPercentage() << "% of health.\n";
    }

    virtual void attack(Creature* /*opponent*/) {}

    virtual std::string toString() const {
        std::ostringstream oss;
        oss << "Creature(name: " << name << ", health: " << health << ", maxHealth: " << maxHealth << ")";
        return oss.str();
    }

    void decreaseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    int getHealthPercentage() const {
        if (maxHealth == 0) return 0;
        return (health * 100) / maxHealth;
    }

    int getMaxHealth() const {
        return maxHealth;
    }

    int getHealth() const {
        return health;
    }

    bool isAlive() const {
        return health > 0;
    }

    std::string getName() const {
        return name;
    }
};