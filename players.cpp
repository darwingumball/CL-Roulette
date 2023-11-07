#include <iostream>
#include "players.h"

Player::Player(int initialBalance) : bankBalance(initialBalance), chosenColor(""), chosenParity(""), colorBet(0), parityBet(0) {
    std::cout << "Enter your color choice (Black, Red, Green): ";
    std::cin >> chosenColor;
    std::cout << "Enter your parity choice (Even, Odd, 0): ";
    std::cin >> chosenParity;
}

void Player::PlaceColorBet(const std::string& chosenColor, int amount) {
    if (amount <= bankBalance) {

            colorBet = amount;
            bankBalance -= amount;

    }
}

void Player::PlaceParityBet(const std::string& chosenParity, int amount) {
    if (amount <= bankBalance) {
            parityBet = amount;
            bankBalance -= amount;
    }
}

int Player::GetBothBets(){
return colorBet;
return parityBet;
}

void Player::CheckBets(bool fullwin, bool colorwin, bool paritywin) {

    GetBothBets();
// just need to make colorbet and paritybet values get here before if statements, then im done.
    if (fullwin) {
        bankBalance += (colorBet + parityBet);
    }
    if(colorwin){
       bankBalance += (colorBet*2);
    }
    if(paritywin){
        bankBalance += (parityBet*2);
    }
}


int Player::GetBankBalance() const {
    return bankBalance;
}


void Player::InputColorBet(int amount) {

    PlaceColorBet(chosenColor, amount);
}

void Player::InputParityBet(int amount) {
    
    PlaceParityBet(chosenParity, amount);
}

const std::string& Player::GetChosenColor() const {
    return chosenColor;
}

const std::string& Player::GetChosenParity() const {
    return chosenParity;
}