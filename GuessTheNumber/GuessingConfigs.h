#pragma once
#include <optional>

using namespace std;

class GuessingConfigs
{
	std::optional<int> lower_bound;
	std::optional<int> upper_bound;
	std::optional<int> guess;
	std::optional<int> delta;

	std::optional<int> number_to_guess;

	bool validateBounds();
	void setNumberToGuess();
	bool validateCompleteness();
	bool validateInBounds();
	void getDeltaGuess();
};

