#include <iostream>
#include <random>
#include "include/GameManager.h"


using namespace std;

int main() {



    GameManager::getInstance().startGame();
    GameManager::getInstance().run();

    return 0;
}
