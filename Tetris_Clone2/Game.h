#pragma once
#include "GameState.h"
//#include "BlockQueue.h"
//#include "GameGrid.h"
#include "Image.h"

class Game
{
public:
	Game();
	enum {ScreenW = 580, ScreenH = 760};
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
	

	//GameState _gameState;
	/*Block _curBlock;
	BlockQueue _blockQueue;
	GameGrid _grid;*/

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




	////rotate _curBlock CW
	//void RotateCW();
	////rotate _curBlock CCW
	//void RotateCCW();
	////move _curBlock left
	//void MoveLeft();
	////move _curBlock right
	//void MoveRight();
	////move _curBlock down
	//void MoveDown();

	////place _curBlock to _grid and call ClearFullRows and check IsGameOver, if game is not over, update _curBlock
	//void PlaceBlock();
	////check if game is over; if yes, set _gameOver to true
	//bool IsGameOver();
	////check if _curBlock is in a legal position
	//bool blockFit();





	////get _curBlock id
	//int getCurBlockID();

	////get filePath based on Block's ID
	//std::string getBlockFilePath(const int id);

	////get _curBlock position
	//Position getCurBlockPosition(int tile);

	////get _curBlock FilePath
	//std::string getCurBlockFilePath();
};

