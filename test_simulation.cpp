// test_simulation.cpp
#include "catch_amalgamated.hpp"
#include "simulation.h"
#include "team.h"
#include "vampire.h"
#include "human.h"
#include "bat.h"

TEST_CASE("Simulation 1", "[Simulation]") {
    Team teamA1;
    Team teamB1;

    Human john("John Doe", "Engineer", 1990);
    Human jane("Jane Doe", "Doctor", 1985);
    Bat batty("Batty", 10, 20);
    Bat flappy("Flappy", 8, 18);
    Human alice("Alice", "Scientist", 1988);
    Bat screech("Screech", 9, 19);
    Human bob("Bob", "Artist", 1992);
    Human eve("Eve", "Nurse", 1987);
    Human charlie("Charlie", "Teacher", 1989);

    teamA1.add(&john);
    teamA1.add(&jane);
    teamA1.add(&batty);
    teamA1.add(&flappy);
    teamA1.add(&alice);
    teamA1.add(&screech);
    teamA1.add(&bob);
    teamA1.add(&eve);
    teamA1.add(&charlie);

    Vampire alucard("Alucard", "Knight", 13, 23);
    Vampire dracula("Dracula", "Count", 15, 25);
    Vampire nosferatu("Nosferatu", "Noble", 12, 22);
    Vampire carmilla("Carmilla", "Queen", 11, 21);
    Vampire lestat("Lestat", "Prince", 14, 24);
    Vampire vlad("Vlad", "Warrior", 16, 26);
    Bat nightwing("Nightwing", 7, 17);
    Bat shadow("Shadow", 6, 16);
    Vampire morbius("Morbius", "Doctor", 17, 27);
    Bat echo("Echo", 5, 15);
    Vampire strahd("Strahd", "Lord", 18, 28);

    teamB1.add(&alucard);
    teamB1.add(&dracula);
    teamB1.add(&nosferatu);
    teamB1.add(&carmilla);
    teamB1.add(&lestat);
    teamB1.add(&vlad);
    teamB1.add(&nightwing);
    teamB1.add(&shadow);
    teamB1.add(&morbius);
    teamB1.add(&echo);
    teamB1.add(&strahd);

    Simulation sim1(&teamA1, &teamB1);
    while (!sim1.isOver()) {
        sim1.executeRound();
    }
    REQUIRE(teamB1.isAlive());
    REQUIRE(!teamA1.isAlive());
    REQUIRE(sim1.getWinner() == &teamB1);
}

TEST_CASE("Simulation 2", "[Simulation]") {
    Team teamA2;
    Team teamB2;

    Human abraham("Abraham Van Helsing", "Professor", 1990);
    Human mina("Mina Harker", "Teacher", 1985);
    Bat drake("Drake", 10, 20);
    Bat fang("Fang", 8, 18);
    Vampire vlad("Vlad Tepes", "Impaler", 15, 25);
    Vampire elizabeth("Elizabeth Bathory", "Countess", 12, 22);
    Vampire lucy("Lucy Westenra", "Lady", 14, 24);
    Human jonathan("Jonathan Harker", "Lawyer", 1988);

    teamA2.add(&abraham);
    teamA2.add(&mina);
    teamA2.add(&drake);
    teamA2.add(&fang);
    teamA2.add(&vlad);
    teamA2.add(&elizabeth);
    teamA2.add(&lucy);
    teamA2.add(&jonathan);

    Bat batty("Batty", 9, 19);
    Vampire vlad2("Vlad the Impaler", "Warrior", 16, 26);
    Vampire knight("Knight", "Knight", 13, 23);
    Vampire queen("Queen", "Queen", 11, 21);
    Human artist("Artist", "Artist", 1992);
    Human nurse("Nurse", "Nurse", 1987);
    Bat bat4("Bat4", 7, 17);
    Bat bat5("Bat5", 6, 16);
    Vampire doctor("Doctor", "Doctor", 17, 27);
    Human teacher("Teacher", "Teacher", 1989);
    Bat bat6("Bat6", 5, 15);
    Vampire lord("Lord", "Lord", 18, 28);

    teamB2.add(&batty);
    teamB2.add(&vlad2);
    teamB2.add(&knight);
    teamB2.add(&queen);
    teamB2.add(&artist);
    teamB2.add(&nurse);
    teamB2.add(&bat4);
    teamB2.add(&bat5);
    teamB2.add(&doctor);
    teamB2.add(&teacher);
    teamB2.add(&bat6);
    teamB2.add(&lord);

    Simulation sim2(&teamA2, &teamB2);
    while (!sim2.isOver()) {
        sim2.executeRound();
    }
    REQUIRE(teamB2.isAlive());
    REQUIRE(!teamA2.isAlive());
    REQUIRE(sim2.getWinner() == &teamB2);
}

TEST_CASE("Simulation 3", "[Simulation]") {
    Team teamA3;
    Team teamB3;

    Human vanHelsing("Van Helsing", "Hunter", 1990);
    Human mina("Mina", "Teacher", 1985);
    Bat batman("Batman", 10, 20);
    Bat robin("Robin", 8, 18);
    Vampire dracula("Dracula", "Count", 15, 25);
    Vampire nosferatu("Nosferatu", "Noble", 12, 22);
    Vampire lestat("Lestat", "Prince", 14, 24);
    Human jonathan("Jonathan", "Lawyer", 1988);
    Bat screech("Screech", 9, 19);
    Vampire vlad("Vlad", "Warrior", 16, 26);
    Vampire alucard("Alucard", "Knight", 13, 23);

    teamA3.add(&vanHelsing);
    teamA3.add(&mina);
    teamA3.add(&batman);
    teamA3.add(&robin);
    teamA3.add(&dracula);
    teamA3.add(&nosferatu);
    teamA3.add(&lestat);
    teamA3.add(&jonathan);
    teamA3.add(&screech);
    teamA3.add(&vlad);
    teamA3.add(&alucard);

    Vampire carmilla("Carmilla", "Queen", 11, 21);
    Human artist("Artist", "Artist", 1992);
    Human nurse("Nurse", "Nurse", 1987);
    Bat nightwing("Nightwing", 7, 17);
    Bat shadow("Shadow", 6, 16);
    Vampire morbius("Morbius", "Doctor", 17, 27);
    Human teacher("Teacher", "Teacher", 1989);
    Bat echo("Echo", 5, 15);
    Vampire strahd("Strahd", "Lord", 18, 28);

    teamB3.add(&carmilla);
    teamB3.add(&artist);
    teamB3.add(&nurse);
    teamB3.add(&nightwing);
    teamB3.add(&shadow);
    teamB3.add(&morbius);
    teamB3.add(&teacher);
    teamB3.add(&echo);
    teamB3.add(&strahd);

    Simulation sim3(&teamA3, &teamB3);
    while (!sim3.isOver()) {
        sim3.executeRound();
    }
    REQUIRE(!teamB3.isAlive());
    REQUIRE(teamA3.isAlive());
    REQUIRE(sim3.getWinner() == &teamA3);
}
