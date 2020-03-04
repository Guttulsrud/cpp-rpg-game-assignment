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

    static std::vector<PlayerCharacter> &getCharacters() {
        return getInstance().gameCharacters;
    };

    std::vector<PlayerCharacter> gameCharacters;

    bool checkIfWon(int id);

private:
    GameManager() = default;

    void addCharacter(const PlayerCharacter &p);

    void setUpCharacter(std::string &name, int id, int playerClass);

    void removePlayer(const PlayerCharacter &p);

    static bool checkIfWon();

};


#endif
