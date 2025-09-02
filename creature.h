#ifndef CREATURE_H
#define CREATURE_H 
#include <iostream>
#include <string>

class Creature {
    protected:                  //pola przechowujące
        std::string name;  // nazwa stworzenia
        int health;        // aktualne zdrowie
        int maxHealth;     // maksymalne zdrowie

public:
    Creature(const std::string& name, int maxHealth)
        : name(name), health(maxHealth), maxHealth(maxHealth) {} //inicjalizacja name, health i maxHealth

void decreaseHealth(int amount) { 
    health -= amount;  // zmniejszenie zdrowia
    if (health < 0) health = 0; //zdrowie nie spadnie ponizej 0
}

bool isAlive() const { 
    return health > 0; //true jesli zdrowie > 0
}

int getHealthPercentage() const {       //zwracanie procent zdrowia
    return (health * 100) / maxHealth;  //procent zdrowia z aktualnego i maksymalnego
}

int getMaxHealth() const {
    return maxHealth;
}

//DEKLARACJE

virtual void introduce() const = 0;            // wprowadzenie stworzenia
virtual std::string toString() const = 0;      // zwracanie opisu stworzenia
virtual void attack(Creature* opponent) = 0;   // atak na przeciwnika
virtual ~Creature() = default;                 // usuwanie obiektow pochodnych

};

#endif 