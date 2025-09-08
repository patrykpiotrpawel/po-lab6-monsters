// test_monster.cpp
#include "catch_amalgamated.hpp"
#include "creature.h"


class Monster : public Creature {
public:
    Monster(std::string name, int maxHealth) : Creature(name, maxHealth) {}

    void introduce() const override {
        Creature::introduce();
    }

    void attack(Creature *opponent) override {
        opponent->decreaseHealth(10); 
    }

    std::string toString() const override {
        return Creature::toString();
    }
};


TEST_CASE("Monster decreaseHealth and isAlive methods", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(30);
    REQUIRE(monster.isAlive() == true);
    monster.decreaseHealth(70);
    REQUIRE(monster.isAlive() == false);
}

TEST_CASE("Monster getHealthPercentage method", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(50);
    REQUIRE(monster.getHealthPercentage() == 50);
}

TEST_CASE("Monster getMaxHealth method", "[Monster]") {
    Monster monster("Goblin", 100);
    REQUIRE(monster.getMaxHealth() == 100);
}

TEST_CASE("Monster introduce method", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(50);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    monster.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named Goblin and I have 50% of health.\n");
}

TEST_CASE("Monster attack method", "[Monster]") {
    Monster monster("Goblin", 100);
    Monster opponent("Orc", 100);
    monster.attack(&opponent);
    REQUIRE(opponent.getHealthPercentage() == 90);
}

TEST_CASE("Monster toString method", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(50);
    REQUIRE(monster.toString() == "Creature(name: Goblin, health: 50, maxHealth: 100)");
}

TEST_CASE("Monster decreaseHealth does not go below zero", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(150);
    REQUIRE(monster.getHealthPercentage() == 0);
    REQUIRE(monster.isAlive() == false);
}

TEST_CASE("Monster decreaseHealth with zero", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(0);
    REQUIRE(monster.getHealthPercentage() == 100);
    REQUIRE(monster.isAlive() == true);
}

TEST_CASE("Monster multiple attacks", "[Monster]") {
    Monster monster("Goblin", 100);
    Monster opponent("Orc", 100);
    for (int i = 0; i < 5; ++i) {
        monster.attack(&opponent);
    }
    REQUIRE(opponent.getHealthPercentage() == 50);
}

TEST_CASE("Monster introduce after death", "[Monster]") {
    Monster monster("Goblin", 100);
    monster.decreaseHealth(100);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    monster.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named Goblin and I have 0% of health.\n");
}

TEST_CASE("Monster toString at full health", "[Monster]") {
    Monster monster("Goblin", 100);
    REQUIRE(monster.toString() == "Creature(name: Goblin, health: 100, maxHealth: 100)");
}