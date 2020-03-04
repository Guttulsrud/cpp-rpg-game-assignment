cmake_minimum_required(VERSION 3.15)
project(homeExam_1_2020)

set(CMAKE_CXX_STANDARD 20)

add_executable(homeExam_1_2020 main.cpp src/PlayerCharacter.cpp include/PlayerCharacter.h src/Character.cpp include/Character.h src/GameManager.cpp include/GameManager.h src/HP.cpp include/HP.h src/Attack.cpp include/Attack.h)