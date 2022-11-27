#pragma once
#include "Block.h"
//JBlock has id = 2, startOffSet = {0, 3}
class JBlock :public Block
{
public:
	JBlock(const int id, const Position& startOffset, const std::string& imgPath);
};

