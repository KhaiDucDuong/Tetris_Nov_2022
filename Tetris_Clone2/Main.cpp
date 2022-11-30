#include "Game.h"

/*how to play
since I'm lazy, I won't make a menu teaching you how to play
left arrow key - move block to the left
right arrow key - move block to the right
down arrow key - move block down
up arrow key - rotate block clock wise
z button - rotate block counter clock wise
spacebar - drop a block instantly
enter - press to restart game when game is over

player UI:
you can set the difficulty - block drop speed by clicking the arrows on the level difficulty UI
change songs or pause music by clicking buttons on the music UI
you can see the point at the top of the UI
you can see the next block under point

have fun*/
int main(int argc, char** argv)
{
	Game game(5);
	game.init();
	game.game_loop();
	game.game_quit();

	return 0;
}