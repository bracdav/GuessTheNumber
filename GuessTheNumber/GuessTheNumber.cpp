// GuessTheNumber.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "NumberOperations.h"
#include <string>
#include <algorithm>

using namespace std;

bool keepPlaying(bool keep_playing) 
{
    string play_string;
    std::cout << "Wanna keep playing? (yes/no)\n";
    std::cin >> play_string;

    while (play_string != "y" && play_string != "n") 
    {
        std::cout << "Allowed inputs are y or n\n";
        std::cin >> play_string;
    }

    if (play_string == "n")
    {
        return false;
    }

    return keep_playing;
}

int main()
{
    bool play = true;

    while (play) {
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

        play = keepPlaying(play);
    }
}
