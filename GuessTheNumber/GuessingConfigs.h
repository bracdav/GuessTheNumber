#pragma once
#include <optional>

using namespace std;

class GuessingConfigs
{
public:
	std::optional<int> lower_bound;
	std::optional<int> upper_bound;
	std::optional<int> guess;
	std::optional<int> delta;

	std::optional<int> number_to_guess;

	void setNumberToGuess();
	bool validateBounds();
	bool validateCompleteness();
	bool validateInBounds();
	void getDeltaGuess();
};

