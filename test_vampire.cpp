// test_vampire.cpp
#include "catch_amalgamated.hpp"
#include "vampire.h"
#include <sstream>

TEST_CASE("Vampire introduce method", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    std::ostringstream output;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    vampire.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named Dracula and I have 100% of health.\n"
                            "I am a Count and I am 128 years old.\n"
                            "I am Creature named Dracula and I have 100% of health.\n"
                            "I am a bat with wingspan 15 and flight speed 25.\n"
                            "I am a vampire.\n");
}

TEST_CASE("Vampire attack method", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Human human("John Doe", "Engineer", 1990);
    vampire.attack(&human);
    REQUIRE(human.getHealthPercentage() == 90);

    human.decreaseHealth(60); // Reduce health to below 50%
    vampire.attack(&human);
    REQUIRE(human.getHealthPercentage() == 0);
}

TEST_CASE("Vampire toString method", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    REQUIRE(vampire.toString() ==
            "Vampire(Creature(name: Dracula, health: 1000, maxHealth: 1000), Human(Creature(name: Dracula, health: 1000, maxHealth: 1000), occupation: Count, bornYear: 1897), Bat(Creature(name: Dracula, health: 1000, maxHealth: 1000), wingspan: 15, flightSpeed: 25))");
}

TEST_CASE("Vampire attack method on Human with health above 50%", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Human human("John Doe", "Engineer", 1990);
    vampire.attack(&human);
    REQUIRE(human.getHealthPercentage() == 90);
}

TEST_CASE("Vampire attack method on Human with health below 50%", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Human human("John Doe", "Engineer", 1990);
    human.decreaseHealth(60); // Reduce health to below 50%
    vampire.attack(&human);
    REQUIRE(human.getHealthPercentage() == 0);
}

TEST_CASE("Vampire attack method on non-Human creature", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Bat bat("Batty", 10, 20);
    vampire.attack(&bat);
    REQUIRE(bat.getHealthPercentage() == 75);
}

TEST_CASE("Vampire attack method on non-Human creature with health below 50%", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Bat bat("Batty", 10, 20);
    bat.decreaseHealth(21); // Reduce health to below 50%
    vampire.attack(&bat);
    REQUIRE(bat.getHealthPercentage() == 22);
}

TEST_CASE("Vampire introduce after health decrease", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    vampire.decreaseHealth(500);
    std::ostringstream output;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    vampire.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str().find("I am Creature named Dracula and I have 50% of health.") != std::string::npos);
}

TEST_CASE("Vampire toString after health decrease", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    vampire.decreaseHealth(400);
    REQUIRE(vampire.toString().find("health: 600") != std::string::npos);
}

TEST_CASE("Vampire cannot decrease health below zero", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    vampire.decreaseHealth(2000);
    REQUIRE(vampire.getHealthPercentage() == 0);
}

TEST_CASE("Vampire attack does not affect dead creature", "[Vampire]") {
    Vampire vampire("Dracula", "Count", 15, 25);
    Human human("John Doe", "Engineer", 1990);
    human.decreaseHealth(100);
    vampire.attack(&human);
    REQUIRE(human.getHealthPercentage() == 0);
}

TEST_CASE("Vampire getAge returns correct value", "[Vampire]") {
    Vampire vampire("Lestat", "Prince", 14, 24);
    REQUIRE(vampire.getAge() == 128);
}
