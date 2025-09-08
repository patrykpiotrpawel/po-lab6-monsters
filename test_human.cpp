// test_human.cpp
#include "catch_amalgamated.hpp"
#include "human.h"
#include <sstream>

TEST_CASE("Human getAge method", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    REQUIRE(human.getAge() == 35);
}

TEST_CASE("Human introduce method", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    human.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named John Doe and I have 100% of health.\n"
                            "I am a Engineer and I am 35 years old.\n");
}

TEST_CASE("Human attack method", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    Human opponent("Jane Doe", "Doctor", 1992);
    human.attack(&opponent);
    REQUIRE(opponent.getHealthPercentage() == 90);
}

TEST_CASE("Human toString method", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    REQUIRE(human.toString() == "Human(Creature(name: John Doe, health: 100, maxHealth: 100), occupation: Engineer, bornYear: 1990)");
}

TEST_CASE("Human health does not go below zero", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    Human opponent("Jane Doe", "Doctor", 1992);
    for (int i = 0; i < 11; ++i) {
        human.attack(&opponent);
    }
    REQUIRE(opponent.getHealthPercentage() == 0);
}

TEST_CASE("Human introduce after health decrease", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    human.decreaseHealth(50);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    human.introduce();

    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(output.str() == "I am Creature named John Doe and I have 50% of health.\n"
                            "I am a Engineer and I am 35 years old.\n");
}

TEST_CASE("Human toString after health decrease", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    human.decreaseHealth(40);
    REQUIRE(human.toString() == "Human(Creature(name: John Doe, health: 60, maxHealth: 100), occupation: Engineer, bornYear: 1990)");
}

TEST_CASE("Human getAge for different year", "[Human]") {
    Human human("Alice", "Scientist", 2000);
    REQUIRE(human.getAge() == 25);
}

TEST_CASE("Human decreaseHealth with zero", "[Human]") {
    Human human("John Doe", "Engineer", 1990);
    human.decreaseHealth(0);
    REQUIRE(human.getHealthPercentage() == 100);
}