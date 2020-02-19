#include <iostream>
#include "Classes/GameManager.h"

int main() {



    GameManager::getInstance().startGame();
    GameManager::getInstance().run();


    return 0;
}
