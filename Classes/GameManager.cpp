//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include "windows.h"
#include <iostream>
#include <algorithm>
#include "GameManager.h"
#include "PlayerCharacter.h"
#include "NPCCharacter.h"


void GameManager::startGame() {
    std::cout << "Input number of players" << std::endl;
    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    for (int i = 1; i < numberOfPlayers + 1; i++) {
        std::string name;
        int playerClass;
        std::cout << "Player " << i << ", what is your name?" << std::endl;
        std::cin >> name;

        std::cout << name << ", what is your class?" << std::endl;
        std::cout << "Press 1 for Fighter -- HP:110 / AC:5" << std::endl;
        std::cout << "Press 2 for Druid -- HP:100 / AC:15" << std::endl;
        std::cout << "Press 3 for Wizard -- HP:120 / AC:8" << std::endl;
        std::cin >> playerClass;

        setUpCharacter(name, i, playerClass);
    }
}

void GameManager::setUpCharacter(std::string &name, int id, int playerClass) {
    std::string mainAttackName = "Punch";
    std::string mainAttackName2 = "Charge";

    Attack baseAttack = Attack(mainAttackName, 8, 0);
    Attack baseAttack2 = Attack(mainAttackName2, 16, 3);

    if (playerClass == 1) {
        // Fighter
        std::string attackName = "Barbarian Punch";
        std::string attackName2 = "Double Punch";

        Attack attack = Attack(attackName, 13, 1);
        Attack attack2 = Attack(attackName2, 17, 2);

        HP hp = HP(110, 5);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(baseAttack);
        p.addAttack(baseAttack2);
        p.addAttack(attack);
        p.addAttack(attack2);
        addCharacter(p);

    } else if (playerClass == 2) {
        // Druid

        std::string attackName = "Windbash";
        std::string attackName2 = "Triple Windbash!";

        Attack attack = Attack(attackName, 15, 2);
        Attack attack2 = Attack(attackName, 35, 4);

        HP hp = HP(100, 12);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(baseAttack);
        p.addAttack(baseAttack2);
        p.addAttack(attack);
        p.addAttack(attack2);
        addCharacter(p);
    } else {
        // Wizard

        std::string attackName = "Fire Spell";
        std::string attackName2 = "Ice Spell";

        Attack attack = Attack(attackName, 32, 4);
        Attack attack2 = Attack(attackName, 27, 3);

        HP hp = HP(120, 8);
        PlayerCharacter p = PlayerCharacter(name, id, hp);
        p.addAttack(baseAttack);
        p.addAttack(baseAttack2);
        p.addAttack(attack);
        p.addAttack(attack2);
        addCharacter(p);
    }
}

void GameManager::run() {
    int round = 1;


    while (gameCharacters.size() > 1) {
        std::cout << "\nRound " << round << " started. " << std::endl << "Stats: " << std::endl;
        for (auto &p : gameCharacters) {
            p.printStatus();
        }

        for (auto &p : gameCharacters) {
            p.runTurn();
        }

        round++;

    }
}


void GameManager::addCharacter(PlayerCharacter const &p) {
    gameCharacters.emplace_back(p);
}

