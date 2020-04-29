#include "Game.h"

Game::Game()
{


}

Game::~Game()
{

}



void Game::handleEvents()
{
	SDL_PollEvent(&m_event);
	left = false;
	right = false;
	up = false;
	down = false;
	guess = "blank";
	switch (m_event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (m_event.key.keysym.sym) {
		case SDLK_LEFT:
			left = true;
			lastChoice = "left";
			break;
		case SDLK_RIGHT:
			right = true;
			lastChoice = "right";
			break;
		case SDLK_UP:
			up = true;
			lastChoice = "up";
			break;
		case SDLK_DOWN:
			down = true;
			lastChoice = "down";
			break;
		default:
			
			break;


		}
		
		break;


	}

}
void updateThreadDelay(int &rectX, int& rectY, int num1, int num2)
{
	rectX = num1;
	rectY = num2;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void handleEventsDelay(int& rectX, int& rectY, bool up, bool down, bool left, bool right)
{
	if (left)
	{
		rectX -= 5;
	}
	else if (right)
	{
		rectX += 5;
	}
	if (up)
	{
		rectY -= 5;
	}
	else if (down)
	{
		rectY += 5;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
void updateThreadRollback(int& rectX, int& rectY, int num1, int num2)
{
	rectX = num1;
	rectY = num2;
}
void handleEventsRollback(int& rectX, int& rectY, std::string guess,std::string &lastGuess)
{
	
	
	if (guess=="left")
	{
		lastGuess = "left";
		rectX -= 5;
	}
	else if (guess == "right")
	{
		lastGuess = "right";
		rectX += 5;
	}
	else if (guess == "up")
	{
		lastGuess = "up";
		rectY -= 5;
	}
	else if (guess == "down")
	{
		lastGuess = "down";
		rectY += 5;
	}
	else
	{
		lastGuess = "blank";
	}
	
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	rect.x = 200; rect.y = 200; rect.w = 50; rect.h = 50;
	rectX = rect.x; rectY = rect.y; rectW = rect.w; rectH = rect.h;
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

		}

		isRunning = true;
	}

	

}
void Game::update()
{
	{		//Delay based sim.
		/*std::thread second(handleEventsDelay, std::ref(rect.x), std::ref(rect.y), rectX, rectY);
		std::thread first(updateThreadDelay, std::ref(rectX), std::ref(rectY), up, down, left, right);
		first.join();
		second.join();*/
	}

	{// rollback based sim
		if (left)
		{
			guess = "left";
		}
		else if (right)
		{
			guess = "right";
		}
		if (up)
		{
			guess = "up";
		}
		else if (down)
		{
			guess = "down";
		}
		/* guess= "blank";
		 if (guess == "blank")
		 {
			 guess = lastChoice;
		}*/
		 
		std::thread second(updateThreadRollback, std::ref(rect.x), std::ref(rect.y), rectX, rectY);
		std::thread first(handleEventsRollback, std::ref(rectX), std::ref(rectY), guess,std::ref(lastChoice));
		first.join();
		second.join();
		guess = "blank";
	}
	//handleUpdatesOfDelay();
}



void Game::subSystemUpdate()
{
	
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(m_renderer, &rect);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	
	SDL_RenderPresent(m_renderer);
}


void Game::clean()
{
	stick.close();
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	isRunning = false;
}







