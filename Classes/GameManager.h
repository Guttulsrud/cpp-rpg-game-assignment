//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_GAMEMANAGER_H
#define ARBEIDSKRAV_GAMEMANAGER_H


#include <vector>
#include "Character.h"
#include "PlayerCharacter.h"

class GameManager {
public:
    void startGame();

    void run();

    std::vector<PlayerCharacter> gameCharacters;

    static GameManager &getInstance() {
        static GameManager instance;
        return instance;
    }

private:
    GameManager() = default;
};


#endif
