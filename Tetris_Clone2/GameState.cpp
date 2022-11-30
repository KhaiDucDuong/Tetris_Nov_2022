#include "GameState.h"

void GameState::PlaceBlock(int &point)
{
    for (int i = 0; i < Block::nTiles; i++)
    {
        Position pos = _curBlock.GetPosition(i);
        _grid->SetGridValue(pos.Row, pos.Column, _curBlock.GetId());
    }

    int point_added = _grid->clearRows();
    point += point_added * point_added;

    if (IsGameOver())
        _gameOver = true;
    else
    {
        _curBlock = _blockQueue->GetandUpdate();
        //_curBlock.Reset();
    }
}

bool GameState::IsGameOver()
{
    return !(_grid->isRowEmpty(0) && _grid->isRowEmpty(1));
}

bool GameState::blockFit()
{
    for (int i = 0; i < Block::nTiles; i++)
    {
        Position pos = _curBlock.GetPosition(i);
        if (!_grid->isInside(pos.Row, pos.Column) || !_grid->isEmpty(pos.Row, pos.Column))
            return false;
    }
    return true;
}

GameState::GameState()
{
    _gameOver = false;
    _curBlock = _blockQueue->GetandUpdate();
}


void GameState::RotateCW()
{
    _curBlock.RotateCW();
    if (!blockFit())
        _curBlock.RotateCCW();
}

void GameState::RotateCCW()
{
    _curBlock.RotateCCW();
    if (!blockFit())
        _curBlock.RotateCW();
}

void GameState::MoveLeft()
{
    _curBlock.Move(0, -1);
    if (!blockFit())
        _curBlock.Move(0, 1);
}

void GameState::MoveRight()
{
    _curBlock.Move(0, 1);
    if (!blockFit())
        _curBlock.Move(0, -1);
}

bool GameState::MoveDown(int & point)
{
    _curBlock.Move(1, 0);
    if (!blockFit())
    {
        _curBlock.Move(-1, 0);
        PlaceBlock(point);
        return false;
    }
    return true;
}

void GameState::hardDrop(int &point)
{
    bool CanMoveDown = true;
    while (CanMoveDown)
    {
        CanMoveDown = MoveDown(point);
    }
}

bool GameState::getGameOver()
{
    return _gameOver;
}

int GameState::getCurBlockID()
{
    return _curBlock.GetId();
}

std::string GameState::getBlockFilePath(const int id)
{
    return _blockQueue->getBlockPath(id);
}

Position GameState::getCurBlockPosition(int tile)
{
    return _curBlock.GetPosition(tile);
}

std::string GameState::getCurBlockFilePath()
{
    return _blockQueue->getBlockPath(_curBlock.GetId());
}

void GameState::GetAndUpdateCurBlock()
{
    _curBlock = _blockQueue->GetandUpdate();
}

int GameState::GetGridValue(const int& r, const int& c)
{
    return _grid->getValueAt1Position(r, c);
}

Position GameState::getNextBlockPosition(int tile)
{
    return _blockQueue->getNextBlockPosition(tile);
}

std::string GameState::getNextBlockFilePath()
{
    const int nextBlockID = _blockQueue->getNextBlockID();
    return _blockQueue->getBlockPath(nextBlockID);
}

void GameState::ResetGrid()
{
    _grid->ResetGrid();
}

void GameState::newGame()
{
    ResetGrid();
    GetAndUpdateCurBlock();
    _gameOver = false;
}
