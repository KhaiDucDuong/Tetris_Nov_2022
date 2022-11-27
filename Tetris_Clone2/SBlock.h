#pragma once
#include "Block.h"
//SBlock has id = 5, startOffSet = {0, 3}
class SBlock : public Block
{
public:
	SBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

