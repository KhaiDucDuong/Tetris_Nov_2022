#pragma once
#include"Block.h"
//ZBlock has id = 7, startOffSet = {0, 3}
class ZBlock : public Block
{
public:
	ZBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

