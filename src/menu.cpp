#ifndef MENU
#define MENU

#include "menu.h"
#include "game.h"
#include "leaderboard.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

Menu::Menu()
{
    leaderboard = new Leaderboard;
    lenght = 4;
}

Menu::~Menu()
{
    delete leaderboard;
}

int Menu::join()
{
    int key = 0;
    std::string str;
    bool flag = false;
    while (!flag) {
        std::cout << "1 new game" << std::endl;
        std::cout << "2 leaders board" << std::endl;
        std::cout << "3 about program" << std::endl;
        std::cout << "4 settings" << std::endl;
        std::cout << "5 exit" << std::endl;
        std::getline(std::cin, str);
        if (!is_valid(str)) {
            std::cout << "invalid input" << std::endl;
            continue;
        }
        key = str[0] - 48;
        switch (key) {
        case 1:
            start();
            break;
        case 2:
            leaderboard->show_leader_board();
            break;
        case 3:
            about();
            break;
        case 4:
            settings();
            break;
        case 5:
            flag = true;
        }
    }
    return 0;
}

void Menu::settings()
{
    std::string str;
    bool is_valid = false;
    int in;
    while (!is_valid) {
        std::cout << "enter new lenght of sequence from 2 to 9" << std::endl;
        std::getline(std::cin, str);
        if (str.size() > 1) {
            std::cout << "invalid input" << std::endl;
            continue;
        }
        in = str[0] - 48;
        for (int i = 2; i < 10; ++i) {
            if (in == i) {
                is_valid = true;
                break;
            }
        }
        if (!is_valid) {
            std::cout << "invalid input" << std::endl;
        }
    }
    lenght = in;
}

bool Menu::is_valid(std::string str)
{
    if (str.size() > 1) {
        return false;
    }
    int key = str[0] - 48;
    if (key < 1 || key > 5) {
        return false;
    }
    return true;
}

void Menu::start()
{
    game = new Game(lenght);
    int res = game->join();
    leaderboard->compare(res);
    delete game;
}

void Menu::about()
{
    std::string line;

    std::ifstream in("data/about.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            std::cout << line << std::endl;
        }
    }
    in.close();
}

#endif
