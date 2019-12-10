#include "MimicData.h"

MimicData::MimicData()
{
}

MimicData::~MimicData()
{
}

void MimicData::playerInput()
{
	bool isCorrect = false;
	if (GetKeyState('A') & 0x8000)
	{
		std::cout << "Possible guesses: " << possibleChoicesA[0] << " " << possibleChoicesA[1] << " " << possibleChoicesA[2] << std::endl;
		std::cout << "Guess: " << guess(0) << std::endl << "Correct guesses: " << timesGuessedCorrect << " Incorrect Guesses " << timesGuessedIncorrect << std::endl;
		std::cin >> playerEnteredString;
		for (int i = 0; i < 3; i++)
		{
			if (playerEnteredString == possibleChoicesA[i])
			{
				timesChosenA[i]++;
				isCorrect = true;
			}
			
		}
		if (isCorrect)
		{
			timesGuessedCorrect++;
		}
		else
		{
			timesGuessedIncorrect++;
		}
		
	}
	else if (GetKeyState('B') & 0x8000)
	{
		std::cout << "Possible guesses: " << possibleChoicesB[0] << " " << possibleChoicesB[1] << " " << possibleChoicesB[2] << std::endl;
		std::cout << "Guess: " << guess(1) << std::endl << "Correct guesses: " << timesGuessedCorrect << " Incorrect Guesses " << timesGuessedIncorrect << std::endl;
		std::cin >> playerEnteredString;
		for (int i = 0; i < 3; i++)
		{
			if (playerEnteredString == possibleChoicesB[i])
			{
				timesChosenB[i]++;
				isCorrect = true;
			}
		}
		if (isCorrect)
		{
			timesGuessedCorrect++;
		}
		else
		{
			timesGuessedIncorrect++;
		}
	}
	else if (GetKeyState('C') & 0x8000)
	{
		std::cout << "Possible guesses: " << possibleChoicesC[0] << " " << possibleChoicesC[1] << " " << possibleChoicesC[2] << std::endl;
		std::cout << "Guess: " << guess(0) << std::endl << "Correct guesses: " << timesGuessedCorrect << " Incorrect Guesses " << timesGuessedIncorrect << std::endl;
		std::cin >> playerEnteredString;
		for (int i = 0; i < 3; i++)
		{
			if (playerEnteredString == possibleChoicesC[i])
			{
				timesChosenC[i]++;
				isCorrect = true;
			}
		}
		if (isCorrect)
		{
			timesGuessedCorrect++;
		}
		else
		{
			timesGuessedIncorrect++;
		}
	}
	
	system("CLS");
}

std::string MimicData::guess(int temp)
{
	std::string strToRet;
	int currCheck;
	if (temp == 0)
	{
		strToRet = possibleChoicesA[0];
		currCheck = timesChosenA[0];
		for (int i = 0; i < 3; i++)
		{
			
			if (timesChosenA[i] > currCheck)
			{
				currCheck = timesChosenA[i];
				strToRet = possibleChoicesA[i];
			}
		}
	}
	if (temp == 1)
	{
		
			strToRet = possibleChoicesB[0];
			currCheck = timesChosenB[0];
			for (int i = 0; i < 3; i++)
			{

				if (timesChosenB[i] > currCheck)
				{
					currCheck = timesChosenB[i];
					strToRet = possibleChoicesB[i];
				}
			}
		
	}
	if (temp == 2)
	{
		
			strToRet = possibleChoicesC[0];
			currCheck = timesChosenC[0];
			for (int i = 0; i < 3; i++)
			{

				if (timesChosenC[i] > currCheck)
				{
					currCheck = timesChosenC[i];
					strToRet = possibleChoicesC[i];
				}
			}
		
	}
	return strToRet;
}
