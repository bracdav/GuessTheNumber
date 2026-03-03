#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <random>

using namespace std;

struct GuessingConfigs 
{
	std::optional<int> lower_bound;
	std::optional<int> upper_bound;
	std::optional<int> guess;
	std::optional<int> delta;

	std::optional<int> number_to_guess;

	bool validateBounds()
	{
		if (!lower_bound)
		{
			std::cout << "Please set lower bound!";
			return false;
		}

		if (!upper_bound)
		{
			std::cout << "Please set upper bound!";
			return false;
		}

		if (!(*lower_bound < *upper_bound))
		{
			return false;
		}
		return true;
	};

	void setNumberToGuess()
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		if (validateBounds()) 
		{
			std::uniform_int_distribution<> dist(*lower_bound, *upper_bound);
			number_to_guess = dist(gen);
		}
	};

	bool validateCompleteness()
	{
		if (!lower_bound && !upper_bound && !guess && !number_to_guess)
		{
			return false;
		}
		return true;
	};

	bool validateInBounds()
	{
		if (!lower_bound)
		{
			std::cout << "Please set lower bound!\n";
			return false;
		}

		if (!upper_bound)
		{
			std::cout << "Please set upper bound!\n";
			return false;
		}

		if (*guess <= *lower_bound || *guess >= *upper_bound)
		{
			std::cout << "Guess out of bounds! Guess again!!\n";
			return false;
		}
		return true;
	};

	void getDeltaGuess() 
	{
		if (!guess) 
		{
			std::cout << "No guess made\n";
			delta = *upper_bound + *lower_bound;
		}

		if (!number_to_guess) 
		{
			std::cout << "No number to guss set!\n";
			delta = *upper_bound + *lower_bound;
		}

		delta = *number_to_guess - *guess;
	}
};


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

