#pragma once
#include "GameState.h"
#include "Image.h"
#include "Text.h"

class Game
{
public:
	Game(const int level);
	enum {ScreenW = 580, ScreenH = 760};
	enum {BlockW = 36, BlockH = 36};
	enum {GridStartPosX = 20, GridStartPosY = 20};
	enum {UIBlockW = 20, UIBlockH = 20};
	enum {NextBlockStartPosX = 386, NextBlockStartPosY = 292};
	enum {ScoreStartPosX = 445, ScoreStartPosY = 55};
	enum {PointStartPosX = 435, PointStartPosY = 115};
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
	bool exitGame;
	int point;
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
	std::string font_path = "res/font.ttf";
	std::string rightArrow_path = "res/right arrow.png";
	std::string leftArrow_path = "res/left arrow.png";

	const int fontSize = 24;

	//draw background
	void drawBackground();
	//draw game Grid
	void drawGrid();
	//draw player UI
	void drawUI();
	//draw the current dropping block
	void drawCurBlock();
	//draw the blocks placed on grid
	void drawGridBlock();

	//draw Score
	void drawScore();

	//draw level UI for players to interact with
	void drawLevelDifficulty();

	//draw preview NextBlock
	void drawNextBlock();

	//draw GameOverText when game is lost
	void drawGameOver();



	const int fps = 60;
	int timePassed;
	int level;
	int timeTillDrop;

};

