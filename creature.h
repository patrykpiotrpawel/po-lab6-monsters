#pragma once
#include <string>
#include <iostream>

class Creature {
protected:
    std::string name;
    int health;
    int maxHealth;
public:
    Creature(std::string name, int maxHealth)
        : name(name), health(maxHealth), maxHealth(maxHealth) {}

    virtual ~Creature() = default;

    void decreaseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getHealthPercentage() const {
        return (maxHealth == 0) ? 0 : (health * 100) / maxHealth;
    }

    int getMaxHealth() const {
        return maxHealth;
    }

    virtual void introduce() const {
        std::cout << "I am Creature named " << name << " and I have " << getHealthPercentage() << "% of health.\n";
    }

    virtual std::string toString() const {
        return "Creature(name: " + name + ", health: " + std::to_string(health) +
               ", maxHealth: " + std::to_string(maxHealth) + ")";
    }

    virtual void attack(Creature* opponent) = 0;
};