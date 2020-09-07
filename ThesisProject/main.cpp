#include "Game.h"
#include "Clientstuff/Client.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SDL.h>
Game* game = nullptr;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	int time = SDL_GetTicks();

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("FYP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;


		if (SDL_GetTicks() > time + 10)
		{
			time = SDL_GetTicks();
			game->subSystemUpdate();
		}

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}


//SERVER SIDE


int main2(int argc, char* argv[])
{
	Client myClient("192.168.178.23", 1111); //Create client to connect to server 127.0.0.1 [localhost] on port 1111
	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
		return -1;
	}
	std::string userinput; //holds the user's chat message
	while (true)
	{
		std::getline(std::cin, userinput); //Get line if user presses enter and fill the buffer
		myClient.SendString(userinput); //Send string to server
	}

	std::cin.get();
	return 0;
}