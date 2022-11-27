#pragma once
#include "Block.h"
//IBlock has id = 1, startOffSet = {-1, 3}
class IBlock : public Block
{
public:
	IBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

