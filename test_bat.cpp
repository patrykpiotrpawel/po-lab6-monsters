// test_bat.cpp
#include "catch_amalgamated.hpp"
#include "bat.h"
#include <sstream>

TEST_CASE("Bat introduce method", "[Bat]") {
    Bat bat("Vampire Bat", 10, 20);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    bat.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named Vampire Bat and I have 100% of health.\n"
                            "I am a bat with wingspan 10 and flight speed 20.\n");
}

TEST_CASE("Bat attack method", "[Bat]") {
    Bat bat("Vampire Bat", 10, 20);
    Bat opponent("Fruit Bat", 10, 20);
    bat.attack(&opponent);
    REQUIRE(opponent.getHealthPercentage() == 87);
}

TEST_CASE("Bat toString method", "[Bat]") {
    Bat bat("Vampire Bat", 10, 20);
    REQUIRE(bat.toString() == "Bat(Creature(name: Vampire Bat, health: 40, maxHealth: 40), wingspan: 10, flightSpeed: 20)");
}

TEST_CASE("Bat changeFlightSpeed method", "[Bat]") {
    Bat bat("Vampire Bat", 10, 30);
    bat.changeFlightSpeed(20);
    REQUIRE(bat.toString() == "Bat(Creature(name: Vampire Bat, health: 40, maxHealth: 40), wingspan: 10, flightSpeed: 20)");
}