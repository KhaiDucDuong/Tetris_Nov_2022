#include "BlockQueue.h"

Block BlockQueue::RandomBlock()
{
    Block random_block = _blocks[random.GetRandomNum()];
    return random_block; 
}

BlockQueue::BlockQueue()
{
    _nextBlock = RandomBlock();

    //IBlock_start = { -1,3 };
    //JBlock_start = { 0,3 };
    //LBlock_start = { 0,3 };
    //OBlock_start = { 0,4 };
    //SBlock_start = { 0,3 };
    //TBlock_start = { 0,3 };
    //ZBlock_start = { 0,3 };

    //IBlock_file_path = "res/BlueSquare.png";
    //JBlock_file_path = "res/CyanSquare.png";
    //LBlock_file_path = "res/GreenSquare.png";
    //OBlock_file_path = "res/OrangeSquare.png";
    //SBlock_file_path = "res/PurpleSquare.png";
    //TBlock_file_path = "res/RedSquare.png";
    //ZBlock_file_path = "res/YellowSquare.png";

    //_blocks[0] = IBlock(1, IBlock_start, IBlock_file_path);
    //_blocks[1] = JBlock(1, JBlock_start, JBlock_file_path);
    //_blocks[2] = LBlock(1, LBlock_start, LBlock_file_path);
    //_blocks[3] = OBlock(1, OBlock_start, OBlock_file_path);
    //_blocks[4] = SBlock(1, SBlock_start, SBlock_file_path);
    //_blocks[5] = TBlock(1, TBlock_start, TBlock_file_path);
    //_blocks[6] = ZBlock(1, ZBlock_start, ZBlock_file_path);
}

Block BlockQueue::GetandUpdate()
{
    Block cur_block = _nextBlock;
    do
    {
        _nextBlock = RandomBlock();
    } while (_nextBlock.GetId() == cur_block.GetId());

    return cur_block;
}

std::string BlockQueue::getBlockPath(const int id)
{
    switch (id)
    {
    case 1:
    {
        return IBlock_file_path;
    }
    case 2:
    {
        return JBlock_file_path;
    }
    case 3:
    {
        return LBlock_file_path;
    }
    case 4:
    {
        return OBlock_file_path;
    }
    case 5:
    {
        return SBlock_file_path;
    }
    case 6:
    {
        return TBlock_file_path;
    }
    case 7:
    {
        return ZBlock_file_path;
    }
    default:
    {
        return "";
    }

    }
    
}
