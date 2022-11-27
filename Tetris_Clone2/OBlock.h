#pragma once
#include "Block.h"
//OBlock has id = 4, startOffSet = {0, 4}
class OBlock : public Block
{
public:
	OBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

