#pragma once
#include "Block.h"
//TBlock has id = 6, startOffSet = {0 , 3}
class TBlock : public Block
{
public:
	TBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

