#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream> // Include for input/output operations

class Player {
public:
    Player(int initialBalance);

    void PlaceColorBet(const std::string& chosenColor, int amount);
    void PlaceParityBet(const std::string& chosenParity, int amount);
    void CheckBets(bool fullwin, bool colorwin, bool paritywin);
    int GetBankBalance() const;
    const std::string& GetChosenColor() const; // Get chosen color
    const std::string& GetChosenParity() const; // Get chosen parity
    // New methods for inputting bets
    void InputColorBet(int amount);
    void InputParityBet(int amount);
    int GetBothBets();

private:
    int bankBalance;
    std::string chosenColor;
    std::string chosenParity;
    int colorBet;
    int parityBet;
};

#endif // PLAYER_H
