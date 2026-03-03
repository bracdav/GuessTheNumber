#include "NumberOperations.h"
#include <iostream>
#include <random>
#include "math.h"

using namespace std;

bool NumberOperations::validateGuessiongConfig(GuessingConfigs& configs) 
{
    if (!configs.validateBounds()) 
    {
        std::cout << "Check bounds!\n";
        return false;
    }

    if (!configs.validateCompleteness()) 
    {
        std::cout << "No guess made!\n";
        return false;
    }

    if (!configs.validateInBounds()) 
    {
        std::cout << "Guess outside bounds\n";
    }

    return true;
}

int NumberOperations::getRandomNumber(int lower, int upper)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(lower, upper);
	return distrib(gen);
};

int NumberOperations::convertToInt(string number_string)
{
    bool isInt = !number_string.empty() && std::all_of(number_string.begin(), number_string.end(), ::isdigit);

    int number;

    if (isInt)
    {
        return std::stoi(number_string);
    }
    return 0;
};

void NumberOperations::guessNumber(GuessingConfigs& configs) 
{

    if (!NumberOperations::validateGuessiongConfig(configs)) 
    {
        std::cout << "Game is not set up properly!";
    }

    configs.getDeltaGuess();

    while (*configs.number_to_guess != *configs.guess) 
    {
        if (NumberOperations::hotGuess(configs)) 
        {
            std::cout << "Hot!!\n";
        }

        if (NumberOperations::coldGuess(configs)) 
        {
            std::cout << "Cold!!\n";
        }

        NumberOperations::higherOrLower(configs);

        std::cout << "Make a new guess\n";
        string input;
        std::cin >> input;
        *configs.guess = NumberOperations::convertToInt(input);
        configs.getDeltaGuess();
    }

    std:cout << "Found number! My number was " << *configs.number_to_guess << "\n";
}

bool NumberOperations::hotGuess(GuessingConfigs& configs)
{
    if (abs(*configs.delta) > 10) 
    {
        return false;
    }

    return true;
}

bool NumberOperations::coldGuess(GuessingConfigs& configs)
{
    if (abs(*configs.delta) <= 10)
    {
        return false;
    }

    return true;
};

void NumberOperations::higherOrLower(GuessingConfigs& configs)
{
    if (*configs.delta < 0) 
    {
        std::cout << "Guess lower!\n";
        return;
    }

    std::cout << "Guess Higher!\n";
}
