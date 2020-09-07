#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include<stdio.h>


#include <stdlib.h>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <vector>

#include "Paddles.h"


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void subSystemUpdate();
	void render();
	void clean();

	

	bool running() { return isRunning; }
	
	
	SDL_Renderer* m_renderer;
	SDL_Event m_event;
private:
	
	bool isRunning;
	SDL_Window* m_window;
	
	SDL_Rect rect;
	std::vector<std::thread> threads;
	bool left, right, up, down;
	int rectX, rectY, rectH, rectW;
	void handleUpdatesOfDelay();

	Paddle m_pads;
	

	
	bool keyTest = false;
	std::string lastChoice;
	std::string guess;
	
	float m_timer = 0.0f;
	float m_frames = 1.0f / 60.0f;
};
