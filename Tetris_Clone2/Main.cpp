#include "Game.h"


int main(int argc, char** argv)
{
	Game game;
	game.init();
	game.game_loop();
	game.game_quit();

	return 0;
}