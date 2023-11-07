#include <iostream>
#include "include/roul.cpp" // Replace with "include/roul.h" header when you can compile
#include "include/players.cpp"
#include "include/roul.h"
#include "include/players.h"

int main() {
    std::vector<Player> players;  // Create a vector to store player objects

    // Ask how many players want to play
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    // Initialize players with a starting balance of $200
    for (int i = 0; i < numPlayers; ++i) {
        players.emplace_back(200);
    }

    // Generate a single roulette number and display it
    int randomNumber;
    std::string drawncolor, drawnparity;
    NumGen(randomNumber, drawncolor, drawnparity);

    // Iterate through each player to allow them to place bets and update bank balances
    for (int i = 0; i < numPlayers; ++i) {
        Player& player = players[i];

        // Display the player's current balance
        std::cout << "Player " << i + 1 << "'s Current Balance: $" << player.GetBankBalance() << std::endl;

        int choice;
        std::cout << "Player " << i + 1 << ", choose an option:\n";
        std::cout << "1. Place color bet\n";
        std::cout << "2. Place parity bet\n";
        std::cout << "3. Place both color and parity bets\n";
        std::cout << "4. Skip\n";
        std::cin >> choice;

        if (choice == 1 || choice == 3) {
    int amount;
    std::cout << "Enter the Color bet amount: ";
    std::cin >> amount;
    int colorBet = amount;
    player.InputColorBet(amount);
        }

        if (choice == 2 || choice == 3) {
    int amount;
    std::cout << "Enter the Parity bet amount: ";
    std::cin >> amount;
    int parityBet = amount;
    player.InputParityBet(amount);
        }
    }

    // Display the results of NumGen after all players have placed their bets
    std::cout << "Roulette Result - Number: " << randomNumber << ", Color: " << drawncolor << ", Parity: " << drawnparity << std::endl;

    // Iterate through each player to update their balances based on the outcome
    for (int i = 0; i < numPlayers; ++i) {
        Player& player = players[i];
        
        bool fullwin = false;
        bool colorwin = false;
        bool paritywin = false;

        if (player.GetChosenColor() == drawncolor && player.GetChosenParity() == drawnparity) {
            fullwin = true;
        } else if (player.GetChosenColor() == drawncolor) {
            colorwin = true;
        } else if (player.GetChosenParity() == drawnparity) {
            paritywin = true;
        }

// Check the bets and update the player's balance based on the outcome
        player.CheckBets(fullwin, colorwin, paritywin);

        // Display the updated player's balance
        std::cout << "Player " << i + 1 << "'s Balance: $" << player.GetBankBalance() << std::endl;
    }

    main();
}



