cmake_minimum_required(VERSION 3.15)
project(Arbeidskrav)

set(CMAKE_CXX_STANDARD 20)

add_executable(Arbeidskrav main.cpp Classes/PlayerCharacter.cpp include/PlayerCharacter.h Classes/Character.cpp include/Character.h Classes/GameManager.cpp include/GameManager.h Classes/HP.cpp include/HP.h Classes/Attack.cpp include/Attack.h)