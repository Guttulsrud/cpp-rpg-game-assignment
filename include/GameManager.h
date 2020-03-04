#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <unordered_set>
#include "Character.h"
#include "PlayerCharacter.h"

class GameManager {
public:
    static void startGame();

    static void run();

    static GameManager &getInstance() {
        static GameManager instance;
        return instance;
    }

    static std::vector<PlayerCharacter> &getCharacters() {
        return getInstance().gameCharacters;
    };

    std::vector<PlayerCharacter> gameCharacters;

    bool checkIfWon(int id);

private:
    GameManager() = default;

    static void addCharacter(const PlayerCharacter &p);

    static void setUpCharacter(std::string &name, int id, int playerClass);

};


#endif
