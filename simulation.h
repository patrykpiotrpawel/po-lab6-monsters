#pragma once

#include "team.h"

class Simulation {
    Team* teamA;
    Team* teamB;
    bool over = false;
    Team* winner = nullptr;

public:
    Simulation(Team* a, Team* b) : teamA(a), teamB(b) {}

    void executeRound() {
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

    bool isOver() const {
        return over || (!teamA->isAlive() || !teamB->isAlive());
    }

    Team* getWinner() const {
        if (!over) {
            if (teamA->isAlive() && !teamB->isAlive()) return teamA;
            if (teamB->isAlive() && !teamA->isAlive()) return teamB;
            return nullptr;
        }
        return winner;
    }
};