#pragma once
#include "team.h"

class Simulation {
    Team* teamA;
    Team* teamB;
public:
    Simulation(Team* teamA, Team* teamB)
        : teamA(teamA), teamB(teamB) {}

    void executeRound() {
        teamA->attack(teamB);
        teamB->attack(teamA);
    }

    bool isOver() const {
        return !teamA->isAtLeastOneAlivedMember() || !teamB->isAtLeastOneAlivedMember();
    }

    Team* getWinner() const {
        if (teamA->isAtLeastOneAlivedMember() && !teamB->isAtLeastOneAlivedMember())
            return teamA;
        if (teamB->isAtLeastOneAlivedMember() && !teamA->isAtLeastOneAlivedMember())
            return teamB;
        return nullptr;
    }
};