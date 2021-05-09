#include <Game.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv)
{
	Game* game = new Game();

	game->run();

	delete game;
	return 0;
}
