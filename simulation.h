#pragma once

#include "team.h"

class Simulation {
    Team* teamA;      // wskaźnik na drużynę A
    Team* teamB;      // wskaźnik na drużynę B
    bool over = false;      // czy symulacja zakończona
    Team* winner = nullptr; // wskaźnik na zwycięzcę

public:
    Simulation(Team* a, Team* b) : teamA(a), teamB(b) {} // konstruktor

    void executeRound() { // wykonuje jedną rundę walki
        if (isOver()) return;
        teamA->attack(teamB);
        teamB->attack(teamA);
        if (!teamA->isAlive() && teamB->isAlive()) {
            over = true;
            winner = teamB;
        } else if (!teamB->isAlive() && teamA->isAlive()) {
            over = true;
            winner = teamA;
        } else if (!teamA->isAlive() && !teamB->isAlive()) {
            over = true;
            winner = nullptr;
        }
    }

    bool isOver() const { // czy symulacja zakończona
        return over || (!teamA->isAlive() || !teamB->isAlive());
    }

    Team* getWinner() const { // zwraca zwycięzcę
        if (!over) {
            if (teamA->isAlive() && !teamB->isAlive()) return teamA;
            if (teamB->isAlive() && !teamA->isAlive()) return teamB;
            return nullptr;
        }
        return winner;
    }
};