#include "IBlock.h"

IBlock::IBlock(const int id, const Position& startOffset, const std::string& imgPath)
	:Block(id, startOffset, imgPath)
{
	Tiles[0][0] = {1 , 0};
	Tiles[0][1] = {1 , 1};
	Tiles[0][2] = {1 , 2};
	Tiles[0][3] = {1 , 3};

	Tiles[1][0] = {0 , 2};
	Tiles[1][1] = {1 , 2};
	Tiles[1][2] = {2 , 2};
	Tiles[1][3] = {3 , 2};

	Tiles[2][0] = {2 , 0};
	Tiles[2][1] = {2 , 1};
	Tiles[2][2] = {2 , 2};
	Tiles[2][3] = {2 , 3};

	Tiles[3][0] = {0 , 1};
	Tiles[3][1] = {1 , 1};
	Tiles[3][2] = {2 , 1};
	Tiles[3][3] = {3 , 1};
}
