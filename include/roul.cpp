//Game logic file, everything to do with Roulette: betting, num generation, number game values like black, odd, even, special 0's.
#include <string>
#include <vector>
#include <iostream>
#include <random>

using namespace std;

std::random_device dev;
std::mt19937 rng(dev());

int rand_int(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(rng);
}

int NumGen(int& randomNumber, std::string& color, std::string& parity) {

    randomNumber = rand_int(0, 36);

    if (randomNumber == 0) {
        color = "Green";
        parity = "0";
    } else if ((randomNumber >= 1 && randomNumber <= 10) || (randomNumber >= 20 && randomNumber <= 28)) {
        color = "Red";
        parity = (randomNumber % 2 == 0) ? "Even" : "Odd";

    } else {
        color = "Black";
        parity = (randomNumber % 2 == 0) ? "Even" : "Odd";

    }

// std::cout << "Number: " << randomNumber << ", Color: " << color << ", E/O: " << parity << std::endl;
// remove comment to print generation results before players have placed bets.
    return 0;
}
