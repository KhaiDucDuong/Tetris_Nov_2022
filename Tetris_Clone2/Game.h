#pragma once
#include "GameState.h"
#include "Image.h"

class Game
{
public:
	Game(const int level);
	enum {ScreenW = 580, ScreenH = 760};
	enum {BlockW = 36, BlockH = 36};
	enum {GridStartPosX = 20, GridStartPosY = 20};
	//init SDL and and other classes
	void init();
	//loop game_logic and game_rendering until gameOver is true
	void game_loop();
	//clear everything and quit the game
	void game_quit();
	//reset everything and start game over
	void game_restart();
private:
	bool gameOver;
	//handling game logic
	void game_logic();
	//rendering the current game
	void game_rendering();
	//handle events input (keys pressed, mouse clicked)
	void game_events();

	SDL_Window* window;
	SDL_Renderer* render;
	
	
	GameState _gameState;

	std::string bg_path = "res/Background.jpg";
	std::string UI_path = "res/UI.png";
	std::string grid_path = "res/Grid.png";

	//hard code the width and pos right now - cause i'm lazy...
	void drawBackground();
	//hard code the width and pos right now - cause i'm lazy...
	void drawGrid();
	//hard code the width and pos right now - cause i'm lazy...
	void drawUI();
	//draw the current dropping block
	void drawCurBlock();
	//draw the blocks placed on grid
	void drawGridBlock();

	const int fps = 60;
	int timePassed;
	int level;
	int timeTillDrop;

};

