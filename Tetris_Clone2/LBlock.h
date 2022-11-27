#pragma once
#include "Block.h"
//LBlock has id = 3, startOffSet = {0, 3}
class LBlock : public Block
{
public:
	LBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

