#include "GuessingConfigs.h"
#include <iostream>
#include <random>

using namespace std;


bool GuessingConfigs::validateBounds()
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

void GuessingConfigs::setNumberToGuess()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	if (validateBounds())
	{
		std::uniform_int_distribution<> dist(*lower_bound, *upper_bound);
		number_to_guess = dist(gen);
	}
};

bool GuessingConfigs::validateCompleteness()
{
	if (!lower_bound && !upper_bound && !guess && !number_to_guess)
	{
		return false;
	}
	return true;
};

bool GuessingConfigs::validateInBounds()
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

void GuessingConfigs::getDeltaGuess()
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