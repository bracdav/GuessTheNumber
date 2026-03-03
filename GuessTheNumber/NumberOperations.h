#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <random>
#include "GuessingConfigs.h"

using namespace std;

class NumberOperations
{
private:
	static bool validateGuessiongConfig(GuessingConfigs& configs);
	static bool hotGuess(GuessingConfigs& configs);
	static bool coldGuess(GuessingConfigs& configs);
	static void higherOrLower(GuessingConfigs& configs);
public:
	static int getRandomNumber(int lower, int upper);
	static int convertToInt(string number_string);
	static void guessNumber(GuessingConfigs& configs);
};

