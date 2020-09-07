#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
class Paddle
{
public:
	Paddle();
	void setUp(SDL_Renderer* t_screen);
	int posUpdate(std::string t_pos, int t_hostPlayerNum);
	void update(int* t_hostPlayerNum);
	void render(int t_currentPlayerNum);
	void reset(int t_leftPlayer, int* t_hostPlayerNum);

	const static int MAX_PADDLES = 2;
	int playerPaddle = 0;
private:
	SDL_Renderer* m_screen;
	SDL_Surface* m_loadedSurface;
	SDL_Texture* m_texture;
	SDL_Rect dstrect[MAX_PADDLES];
	SDL_Rect srcrect[MAX_PADDLES];
	std::vector<SDL_Rect>dstrect2;
	std::vector<int>paddlesSignal;
};