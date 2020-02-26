//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_GAMEMANAGER_H
#define ARBEIDSKRAV_GAMEMANAGER_H


#include <vector>
#include <unordered_set>
#include "Character.h"
#include "PlayerCharacter.h"

class GameManager {
public:
    void startGame();

    void run();


    static GameManager &getInstance() {
        static GameManager instance;
        return instance;
    }

    void addCharacter(const PlayerCharacter& p);
    std::vector<PlayerCharacter> getCharacters();
    std::vector<PlayerCharacter> gameCharacters;

private:
    GameManager() = default;

};


#endif
