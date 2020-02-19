//
// Created by Håkon Guttulsrud on 05.02.2020.
//


#include <iostream>
#include <algorithm>
#include "GameManager.h"
#include "PlayerCharacter.h"
#include "NPCCharacter.h"


void GameManager::startGame() {


    std::string  s1("Hei");
    std::string  s2("Hello");
    std::string  s3("Halla");
    std::string  s4("Hola");

    PlayerCharacter p1(s1, 1);
    PlayerCharacter p2(s2, 2);
    PlayerCharacter p3(s3, 3);


    gameCharacters.emplace_back(p1);
    gameCharacters.emplace_back(p2);
    gameCharacters.emplace_back(p3);

}


void GameManager::run() {


    // for_each(gameCharacters.begin(), gameCharacters.end(), [](PlayerCharacter p) {p.runTurn()})
    for(auto &p : gameCharacters) {
        p.runTurn(gameCharacters);
    }





}

