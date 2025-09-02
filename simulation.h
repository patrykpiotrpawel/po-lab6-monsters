#ifndef SIMULATION_H
#define SIMULATION_H

#include "team.h"

class Simulation {
private:
    Team* teamA;
    Team* teamB;

public:
    Simulation(Team* teamA, Team* teamB) : teamA(teamA), teamB(teamB) {}

    void executeRound() {
        teamA->attack(teamB);
        teamB->attack(teamA);
    }

    bool isOver() const {
        return !teamA->isAtLeastOneAliveMember() || !teamB->isAtLeastOneAliveMember();
    }

    Team* getWinner() const {
        if (teamA->isAtLeastOneAliveMember()) return teamA;
        if (teamB->isAtLeastOneAliveMember()) return teamB;
        return nullptr;
    }
};

#endif