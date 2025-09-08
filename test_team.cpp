// test_team.cpp
#include "catch_amalgamated.hpp"
#include "team.h"
#include "vampire.h"
#include "human.h"
#include "bat.h"

TEST_CASE("Team add and getLivingCreatures methods", "[Team]") {
    Team team;
    Vampire vampire1("Dracula", "Count", 15, 25);
    Vampire vampire2("Nosferatu", "Noble", 12, 22);
    Human human1("John Doe", "Engineer", 1990);
    Human human2("Jane Doe", "Doctor", 1985);
    Bat bat1("Batty", 10, 20);
    Bat bat2("Flappy", 8, 18);
    Vampire vampire3("Lestat", "Prince", 14, 24);
    Human human3("Alice", "Scientist", 1988);
    Bat bat3("Screech", 9, 19);
    Vampire vampire4("Vlad", "Warrior", 16, 26);

    team.add(&vampire1);
    team.add(&vampire2);
    team.add(&human1);
    team.add(&human2);
    team.add(&bat1);
    team.add(&bat2);
    team.add(&vampire3);
    team.add(&human3);
    team.add(&bat3);
    team.add(&vampire4);

    auto livingCreatures = team.getLivingCreatures();
    REQUIRE(livingCreatures.size() == 10);
}

TEST_CASE("Team getLivingCreatures returns only alive", "[Team]") {
    Team team;
    Human h1("Alive", "Worker", 1990);
    Human h2("Dead", "Worker", 1990);
    team.add(&h1);
    team.add(&h2);
    h2.decreaseHealth(100);
    auto living = team.getLivingCreatures();
    REQUIRE(living.size() == 1);
    REQUIRE(living[0]->toString() == h1.toString());
}

TEST_CASE("Team getDefender method", "[Team]") {
    Team team;
    Vampire vampire1("Dracula", "Count", 15, 25);
    Vampire vampire2("Nosferatu", "Noble", 12, 22);
    Human human1("John Doe", "Engineer", 1990);
    Human human2("Jane Doe", "Doctor", 1985);
    Bat bat1("Batty", 10, 20);
    Bat bat2("Flappy", 8, 18);
    Vampire vampire3("Lestat", "Prince", 14, 24);
    Human human3("Alice", "Scientist", 1988);
    Bat bat3("Screech", 9, 19);
    Vampire vampire4("Vlad", "Warrior", 16, 26);

    team.add(&vampire1);
    team.add(&vampire2);
    team.add(&human1);
    team.add(&human2);
    team.add(&bat1);
    team.add(&bat2);
    team.add(&vampire3);
    team.add(&human3);
    team.add(&bat3);
    team.add(&vampire4);

    Creature *defender = team.getDefender();
    REQUIRE(defender != nullptr);
    REQUIRE(defender->toString() == vampire1.toString());
}

TEST_CASE("Team getDefender returns nullptr if all dead", "[Team]") {
    Team team;
    Human h1("Dead", "Worker", 1990);
    team.add(&h1);
    h1.decreaseHealth(100);
    REQUIRE(team.getDefender() == nullptr);
}

TEST_CASE("Team attack method", "[Team]") {
    Team team1;
    Team team2;
    Vampire vampire1("Dracula", "Count", 15, 25);
    Vampire vampire2("Nosferatu", "Noble", 12, 22);
    Human human1("John Doe", "Engineer", 1990);
    Human human2("Jane Doe", "Doctor", 1985);
    Bat bat1("Batty", 10, 20);
    Bat bat2("Flappy", 8, 18);
    Vampire vampire3("Lestat", "Prince", 14, 24);
    Human human3("Alice", "Scientist", 1988);
    Bat bat3("Screech", 9, 19);
    Vampire vampire4("Vlad", "Warrior", 16, 26);

    Vampire vampire5("Alucard", "Knight", 13, 23);
    Vampire vampire6("Carmilla", "Queen", 11, 21);
    Human human4("Bob", "Artist", 1992);
    Human human5("Eve", "Nurse", 1987);
    Bat bat4("Nightwing", 7, 17);
    Bat bat5("Shadow", 6, 16);
    Vampire vampire7("Morbius", "Doctor", 17, 27);
    Human human6("Charlie", "Teacher", 1989);
    Bat bat6("Echo", 5, 15);
    Vampire vampire8("Strahd", "Lord", 18, 28);

    team1.add(&vampire1);
    team1.add(&vampire2);
    team1.add(&human1);
    team1.add(&human2);
    team1.add(&bat1);
    team1.add(&bat2);
    team1.add(&vampire3);
    team1.add(&human3);
    team1.add(&bat3);
    team1.add(&vampire4);

    team2.add(&vampire5);
    team2.add(&vampire6);
    team2.add(&human4);
    team2.add(&human5);
    team2.add(&bat4);
    team2.add(&bat5);
    team2.add(&vampire7);
    team2.add(&human6);
    team2.add(&bat6);
    team2.add(&vampire8);

    team1.attack(&team2);

    REQUIRE(vampire5.getHealthPercentage() < 100);
    REQUIRE(human4.getHealthPercentage() == 100);
    REQUIRE(bat4.getHealthPercentage() == 100);
}

TEST_CASE("Team attack does nothing if opponent dead", "[Team]") {
    Team team1, team2;
    Human h1("Attacker", "Worker", 1990);
    Human h2("Defender", "Worker", 1990);
    team1.add(&h1);
    team2.add(&h2);
    h2.decreaseHealth(100);
    team1.attack(&team2);
    REQUIRE(h2.getHealthPercentage() == 0);
}

TEST_CASE("Team isAlive method", "[Team]") {
    Team team;
    Vampire vampire1("Dracula", "Count", 15, 25);
    Vampire vampire2("Nosferatu", "Noble", 12, 22);
    Human human1("John Doe", "Engineer", 1990);
    Human human2("Jane Doe", "Doctor", 1985);
    Bat bat1("Batty", 10, 20);
    Bat bat2("Flappy", 8, 18);
    Vampire vampire3("Lestat", "Prince", 14, 24);
    Human human3("Alice", "Scientist", 1988);
    Bat bat3("Screech", 9, 19);
    Vampire vampire4("Vlad", "Warrior", 16, 26);

    team.add(&vampire1);
    team.add(&vampire2);
    team.add(&human1);
    team.add(&human2);
    team.add(&bat1);
    team.add(&bat2);
    team.add(&vampire3);
    team.add(&human3);
    team.add(&bat3);
    team.add(&vampire4);

    REQUIRE(team.isAlive() == true);

    vampire1.decreaseHealth(1000);
    vampire2.decreaseHealth(1000);
    human1.decreaseHealth(100);
    human2.decreaseHealth(100);
    bat1.decreaseHealth(40);
    bat2.decreaseHealth(40);
    vampire3.decreaseHealth(1000);
    human3.decreaseHealth(100);
    bat3.decreaseHealth(40);
    vampire4.decreaseHealth(1000);

    REQUIRE(team.isAlive() == false);
}

TEST_CASE("Team isAlive false for empty team", "[Team]") {
    Team team;
    REQUIRE(team.isAlive() == false);
}

TEST_CASE("Team toString method", "[Team]") {
    Team team;
    Vampire vampire1("Dracula", "Count", 15, 25);
    Vampire vampire2("Nosferatu", "Noble", 12, 22);
    Human human1("John Doe", "Engineer", 1990);
    Human human2("Jane Doe", "Doctor", 1985);
    Bat bat1("Batty", 10, 20);
    Bat bat2("Flappy", 8, 18);
    Vampire vampire3("Lestat", "Prince", 14, 24);
    Human human3("Alice", "Scientist", 1988);
    Bat bat3("Screech", 9, 19);
    Vampire vampire4("Vlad", "Warrior", 16, 26);

    team.add(&vampire1);
    team.add(&vampire2);
    team.add(&human1);
    team.add(&human2);
    team.add(&bat1);
    team.add(&bat2);
    team.add(&vampire3);
    team.add(&human3);
    team.add(&bat3);
    team.add(&vampire4);

    std::string expected = "Team(Vampire(Creature(name: Dracula, health: 1000, maxHealth: 1000), Human(Creature(name: Dracula, health: 1000, maxHealth: 1000), occupation: Count, bornYear: 1897), Bat(Creature(name: Dracula, health: 1000, maxHealth: 1000), wingspan: 15, flightSpeed: 25)), Vampire(Creature(name: Nosferatu, health: 1000, maxHealth: 1000), Human(Creature(name: Nosferatu, health: 1000, maxHealth: 1000), occupation: Noble, bornYear: 1897), Bat(Creature(name: Nosferatu, health: 1000, maxHealth: 1000), wingspan: 12, flightSpeed: 22)), Human(Creature(name: John Doe, health: 100, maxHealth: 100), occupation: Engineer, bornYear: 1990), Human(Creature(name: Jane Doe, health: 100, maxHealth: 100), occupation: Doctor, bornYear: 1985), Bat(Creature(name: Batty, health: 40, maxHealth: 40), wingspan: 10, flightSpeed: 20), Bat(Creature(name: Flappy, health: 40, maxHealth: 40), wingspan: 8, flightSpeed: 18), Vampire(Creature(name: Lestat, health: 1000, maxHealth: 1000), Human(Creature(name: Lestat, health: 1000, maxHealth: 1000), occupation: Prince, bornYear: 1897), Bat(Creature(name: Lestat, health: 1000, maxHealth: 1000), wingspan: 14, flightSpeed: 24)), Human(Creature(name: Alice, health: 100, maxHealth: 100), occupation: Scientist, bornYear: 1988), Bat(Creature(name: Screech, health: 40, maxHealth: 40), wingspan: 9, flightSpeed: 19), Vampire(Creature(name: Vlad, health: 1000, maxHealth: 1000), Human(Creature(name: Vlad, health: 1000, maxHealth: 1000), occupation: Warrior, bornYear: 1897), Bat(Creature(name: Vlad, health: 1000, maxHealth: 1000), wingspan: 16, flightSpeed: 26)), )";
    REQUIRE(team.toString() == expected);
}

TEST_CASE("Team toString empty team", "[Team]") {
    Team team;
    REQUIRE(team.toString() == "Team()");
}