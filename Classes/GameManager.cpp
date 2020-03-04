#include <iostream>
#include <algorithm>
#include "../include/GameManager.h"
#include "../include/PlayerCharacter.h"

void GameManager::startGame() {
    std::cout << "\t Welcome!" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "Input number of players" << std::endl;
    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    for (int i = 1; i < numberOfPlayers + 1; i++) {
        std::string name;
        int playerClass;
        std::cout << "Player " << i << ", what is your name?" << std::endl;
        std::cin >> name;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << name << ", what is your class?" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Press 1 for Fighter -- HP:110 / AC:5" << std::endl;
        std::cout << "Press 2 for Druid -- HP:100 / AC:15" << std::endl;
        std::cout << "Press 3 for Wizard -- HP:120 / AC:8" << std::endl;

        std::cin >> playerClass;

        setUpCharacter(name, i, playerClass);
    }
}

void GameManager::setUpCharacter(std::string &name, int id, int playerClass) {

    if (playerClass == 1) {

        HP hp = HP(110, 5);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(Attack("Barbarian Punch", 13, 1, 3));
        p.addAttack(Attack("Double Punch", 17, 2, 4));
        addCharacter(p);
    } else if (playerClass == 2) {

        HP hp = HP(100, 12);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(Attack("Windbash", 15, 2, 3));
        p.addAttack(Attack("Triple Windbash!", 35, 4, 4));
        addCharacter(p);
    } else if (playerClass == 3) {

        HP hp = HP(120, 8);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(Attack("Fire Spell", 32, 4, 3));
        p.addAttack(Attack("Ice Spell", 27, 3, 4));
        addCharacter(p);
    }
}

void GameManager::run() {
    int round = 1;

    while (gameCharacters.size() > 1) {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Round " << round << " started. " << std::endl << "Stats: " << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        for (auto &p : gameCharacters) {
            p.printStatus();
        }
        std::cout << "-----------------------------------" << std::endl;

        for (auto &p : gameCharacters) {
            if (p.HP.getHP() != 0) {
                p.runTurn();
            } else {
                std::cout << p.getName() << " has been defeated!" << std::endl;
                removePlayer(p);
                std::cout << "-----------------------------------" << std::endl;

                if(gameCharacters.size() < 2) {
                    break;
                }
            }
        }
        std::cout << "-----------------------------------" << std::endl;
        round++;

    }
    std::cout << gameCharacters[0].getName() << " is victorious! " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "\t GAME OVER!" << std::endl;
}


void GameManager::addCharacter(PlayerCharacter const &p) {
    gameCharacters.emplace_back(p);
}

void GameManager::removePlayer(PlayerCharacter const &p) {
    auto it = std::remove_if(gameCharacters.begin(),
                             gameCharacters.end(),
                             [p](const PlayerCharacter &player) {
                                 return player.playerId == p.playerId;
                             });

    gameCharacters.erase(it, gameCharacters.end());
}





