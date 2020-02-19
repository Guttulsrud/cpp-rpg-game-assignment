cmake_minimum_required(VERSION 3.15)
project(Arbeidskrav)

set(CMAKE_CXX_STANDARD 20)

add_executable(Arbeidskrav main.cpp Classes/PlayerCharacter.cpp Classes/PlayerCharacter.h Classes/NPCCharacter.cpp Classes/NPCCharacter.h Classes/Character.cpp Classes/Character.h Classes/GameManager.cpp Classes/GameManager.h Classes/HP.cpp Classes/HP.h Classes/Attack.cpp Classes/Attack.h)