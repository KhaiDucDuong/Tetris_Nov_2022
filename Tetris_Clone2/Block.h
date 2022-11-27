#pragma once
#include "Position.h"
#include "GameGrid.h"
#include <string>
#include "Image.h"

//#include "IBlock.h"
//#include "SBlock.h"
//#include "JBlock.h"
//#include "OBlock.h"
//#include "ZBlock.h"
//#include "LBlock.h"
//#include "TBlock.h"

class Block
{
protected:
	//Position Cur_Tiles[GameGrid::rows][GameGrid::columns];
	Position Tiles[GameGrid::rows][GameGrid::columns];
	Position _StartOffset;
	int _Id;
	int _RotationState;
	Position _OffSet;

	std::string _imgPath;
public:
	enum {nRotations = 4, nTiles = 4};
	//init everything except Tiles (this property will be inited by the derived classes)
	Block(const int id, const Position & startOffset, const std::string &imgPath);

	//default constructor
	Block();

	int GetId();
	//get the Position of a tile of a block by returning the position of the Tiles + offsetValue
	Position GetPosition(const int tile);
	//rotate the block clock wise
	void RotateCW();
	//rotate the block counter clock wise
	void RotateCCW();
	//move - by adding rows value and columns value to offset
	void Move(const int& r, const int& c);
	//reset the block to its original position
	void Reset();

	//img proccessing methods
	SDL_Texture GetBlockTexture(const std::string& imgPath, SDL_Renderer *render);
};

