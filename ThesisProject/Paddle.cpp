#include "Paddles.h"
#include <fstream>
#include <sstream>
Paddle::Paddle()
{
	for (int i = 0; i < MAX_PADDLES; i++)
	{
		dstrect[i] = { 0, -120, 120, 120 };
		srcrect[i] = { 0, i * 120, 120, 120 };
		if (i >= 2)
			srcrect[i].y -= 600;
	}
}

void Paddle::setUp(SDL_Renderer* t_screen)
{
	m_screen = t_screen;
	m_loadedSurface = SDL_LoadBMP("ASSETS/IMAGES/Paddles.bmp");
	m_texture = SDL_CreateTextureFromSurface(m_screen, m_loadedSurface);
}

int Paddle::posUpdate(std::string t_pos, int t_hostPlayerNum)
{
	
	std::istringstream input;
	input.str(t_pos);
	std::string message = "";
	std::getline(input, message, ':');
	int playerNum = std::stoi(message);
	int index = 0;
	//handles the passing of the positions of either paddle that will be sent to the server, 
	//so that both players recieve the data of either player on there own end.
	if (playerNum * 5 > dstrect2.size())
	{
		while (std::getline(input, message, '-'))
		{
			SDL_Rect temp = { 0, -120, 120, 120 };
			std::getline(input, message, ',');
			temp.x = std::stoi(message);
			std::getline(input, message, ',');
			temp.y = std::stoi(message);
			dstrect2.push_back(temp);
		}
		paddlesSignal.push_back(int(100));
	}
	else
	{
		while (std::getline(input, message, '-'))
		{
			SDL_Rect temp = { 0, -120, 120, 120 };
			std::getline(input, message, ',');
			temp.x = std::stoi(message);
			std::getline(input, message, ',');
			temp.y = std::stoi(message);
			dstrect2.at(((playerNum - 1) * 5) + index) = temp;
			index++;
		}
		paddlesSignal.at(playerNum - 1) = 100;
	}
	return playerNum;
}

void Paddle::update(int* t_hostPlayerNum)
{
	int index = 0;
	for (auto currentPaddleSignal : paddlesSignal)
	{
		paddlesSignal.at(index) -= 1;
		if (currentPaddleSignal <= 0)
		{
			reset(index + 1, t_hostPlayerNum);
			paddlesSignal.erase(paddlesSignal.begin() + index);
			index--;
		}
		index++;
	}

}

void Paddle::render(int t_currentPlayerNum)
{
	
	int index = 0;
	for (auto currentDstrect : dstrect2)
	{
		if (index / 5 != t_currentPlayerNum - 1)
		{
			SDL_RenderCopy(m_screen, m_texture, &srcrect[index % 5], &currentDstrect);
		}
		index++;
	}
}

void Paddle::reset(int t_leftPlayer, int* t_hostPlayerNum)
{
	int playerStart = (t_leftPlayer - 1) * 5;
	dstrect2.erase(dstrect2.begin() + playerStart, dstrect2.begin() + playerStart + 2);
	if (*t_hostPlayerNum > t_leftPlayer)
	{
		(*t_hostPlayerNum)--;
	}
}
