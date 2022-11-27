#pragma once
#include "BlockQueue.h"
#include "GameGrid.h"
class GameState
{
private:
	Block _curBlock;
	BlockQueue *_blockQueue = new BlockQueue();
	GameGrid *_grid = new GameGrid();
	bool _gameOver; 

	
public:
	//set _gameover to false and _curBlock
	GameState();
	//rotate _curBlock CW
	void RotateCW();
	//rotate _curBlock CCW
	void RotateCCW();
	//move _curBlock left
	void MoveLeft();
	//move _curBlock right
	void MoveRight();
	//move _curBlock down
	void MoveDown();

	//place _curBlock to _grid and call ClearFullRows and check IsGameOver, if game is not over, update _curBlock
	void PlaceBlock();
	//check if game is over; if yes, set _gameOver to true
	bool IsGameOver();
	//check if _curBlock is in a legal position
	bool blockFit();

	//return gameOver
	bool getGameOver();

	//get _curBlock id
	int getCurBlockID();

	//get filePath based on Block's ID
	std::string getBlockFilePath(const int id);

	//get _curBlock position
	Position getCurBlockPosition(int tile);

	//get _curBlock FilePath
	std::string getCurBlockFilePath();

	//set _curBlock to _nextBlock and update new _nextBlock
	void GetAndUpdateCurBlock();

	//get the value of a position in _grid
	int GetGridValue(const int& r, const int& c);
};

