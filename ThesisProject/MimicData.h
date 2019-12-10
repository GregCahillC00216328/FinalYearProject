#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
class MimicData
{
public:
	MimicData();
	~MimicData();
	void playerInput();
private:
	std::string playerEnteredString;
	std::string possibleChoicesA[3] = {"All","Apple","Andy"};
	int timesChosenA[3] = { 0 };
	std::string possibleChoicesB[3] = {"Ben", "Ball", "Breath"};
	int timesChosenB[3] = { 0 };
	std::string possibleChoicesC[3] = { "Cat", "Crate", "Cyan" };
	int timesChosenC[3] = { 0 };

	int timesGuessedCorrect=0;
	int timesGuessedIncorrect = 0;

	std::string guess(int temp);
};

