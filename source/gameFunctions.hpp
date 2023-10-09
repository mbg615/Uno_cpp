//
// Created by Maddox Guthrie on 12/31/22.
//

#ifndef UNO_GAMEFUNCTIONS_HPP
#define UNO_GAMEFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "dataTypes.hpp"

void clearScreen() {
    std::cout << std::endl;
    system("clear");
}

void addPlayers(std::vector<Player> &players, std::string &playerName) {
    players.emplace_back(playerName);
}

void progressPlayerList(std::vector<Player> &players) {
    std::rotate(players.begin(), players.begin() + 1, players.end());
}

void setWildColor(Card &card) {
    std::cout << "(\033[;31mRed\033[0m, \033[;32mGreen\033[0m, \033[;33mYellow\033[0m, \033[;34mBlue\033[0m)";
    std::string colorForWild;
    std::cout << "Choose a color to start the game: ";
    std::cin >> colorForWild;
    card.setWildColor(colorForWild);

    while (card.getCardColor() == None) {
        std::cout << "\nSorry that is not a valid color.\n";
        std::cout << "Choose a color to start the game: ";
        std::cin >> colorForWild;
        card.setWildColor(colorForWild);
    }
}

#endif //UNO_GAMEFUNCTIONS_HPP
