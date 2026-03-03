// GuessTheNumber.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "NumberOperations.h"
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    GuessingConfigs config;
    string input;



    std::cout << "Lower bound?\n";
    std::cin >> input;
    config.lower_bound = NumberOperations::convertToInt(input);

    std::cout << "Upper bound?\n";
    std::cin >> input;
    config.upper_bound = NumberOperations::convertToInt(input);


    config.setNumberToGuess();

    std::cout << "Make your first guess:\n";
    std::cin >> input;

    config.guess = NumberOperations::convertToInt(input);

    NumberOperations::guessNumber(config);
}
