#include "Block.h"

//#include "IBlock.h"
//#include "SBlock.h"
//#include "JBlock.h"
//#include "OBlock.h"
//#include "ZBlock.h"
//#include "LBlock.h"
//#include "TBlock.h"

Block::Block(const int id, const Position& startOffset, const std::string& imgPath)
{
	_Id = id;
	_StartOffset = startOffset;
	_imgPath = imgPath;

	_OffSet = _StartOffset;
	_RotationState = 0;
}

Block::Block()
{
	_Id = -1;
	_StartOffset = { 0, 0 };
	_imgPath = "";

	_OffSet = _StartOffset;
	_RotationState = 0;
}

int Block::GetId()
{
	return _Id;
}

Position Block::GetPosition(const int tile)
{
	return Tiles[_RotationState][tile] + _OffSet;
}

void Block::RotateCW()
{
	_RotationState = (_RotationState + 1) % nRotations;
}

void Block::RotateCCW()
{
	if (_RotationState == 0)
		_RotationState = nRotations - 1;
	else
		_RotationState = _RotationState - 1;
}

void Block::Move(const int& r, const int& c)
{
	_OffSet.Row += r;
	_OffSet.Column += c;
}

void Block::Reset()
{
	_OffSet = _StartOffset;
	_RotationState = 0;
}
