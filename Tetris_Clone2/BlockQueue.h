#pragma once

#include "Block.h"
#include "Position.h"
#include <iostream>
#include "Random.h"

#include "IBlock.h"
#include "SBlock.h"
#include "JBlock.h"
#include "OBlock.h"
#include "ZBlock.h"
#include "LBlock.h"
#include "TBlock.h"

class BlockQueue
{
public:
	enum { nBlocks = 7 };
private:
	std::string IBlock_file_path = "res/BlueSquare.png";
	std::string JBlock_file_path = "res/CyanSquare.png";
	std::string LBlock_file_path = "res/GreenSquare.png";
	std::string OBlock_file_path = "res/OrangeSquare.png";
	std::string SBlock_file_path = "res/PurpleSquare.png";
	std::string TBlock_file_path = "res/RedSquare.png";
	std::string ZBlock_file_path = "res/YellowSquare.png";

	Position IBlock_start = { -1,3 };
	Position JBlock_start = { 0,3 };
	Position LBlock_start = { 0,3 };
	Position OBlock_start = { 0,4 };
	Position SBlock_start = { 0,3 };
	Position TBlock_start = { 0,3 };
	Position ZBlock_start = { 0,3 };

	Block _blocks[nBlocks]
	{
		IBlock(1, IBlock_start, IBlock_file_path),
		JBlock(2, JBlock_start, JBlock_file_path),
		LBlock(3, LBlock_start, LBlock_file_path),
		OBlock(4, OBlock_start, OBlock_file_path),
		SBlock(5, SBlock_start, SBlock_file_path),
		TBlock(6, TBlock_start, TBlock_file_path),
		ZBlock(7, ZBlock_start, ZBlock_file_path)
	};

	Random random{ 0, nBlocks - 1 };

	Block _nextBlock;

	Block RandomBlock();

public:
	//init _nextBlock = RandomBlock()
	BlockQueue();
	//return _nextBlock and update _nextBlock
	Block GetandUpdate();
	//get BlockIDPath
	std::string getBlockPath(const int id);
};

