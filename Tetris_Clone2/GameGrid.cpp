#include "GameGrid.h"

GameGrid::GameGrid()
{
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < columns; c++)
			grid[r][c] = 0;
}

bool GameGrid::isInside(const int& r, const int& c)
{
	return r >= 0 && r < rows && c >= 0 && c < columns;
}

bool GameGrid::isEmpty(const int& r, const int& c)
{
	return isInside(r, c) && grid[r][c] == 0;
}

bool GameGrid::isRowFull(const int& r)
{
	for (int c = 0; c < columns; c++)
		if (grid[r][c] == 0)
			return false;
	return true;
}

bool GameGrid::isRowEmpty(const int& r)
{
	for (int c = 0; c < columns; c++)
		if (grid[r][c] != 0)
			return false;
	return true;
}

int GameGrid::clearRows()
{
	int cleared = 0;
	for (int r = rows - 1; r >= 0; r--)
	{
		if (isRowFull(r))
		{
			clearRow(r);
			cleared++;
		}
		else if (cleared > 0 && !isRowEmpty(r))
			moveRowDown(r, cleared);
	}
	return cleared;
}

void GameGrid::SetGridValue(const int& r, const int& c, const int& new_value)
{
	if (isInside(r, c))
		grid[r][c] = new_value;
}

int GameGrid::getValueAt1Position(const int& r, const int& c)
{
	if (isInside(r, c))
		return grid[r][c];
	else
		return 0;
}

void GameGrid::clearRow(const int& r)
{
	for (int c = 0; c < columns; c++)
		grid[r][c] = 0;
}

void GameGrid::moveRowDown(const int& r, const int& RowsCleared)
{
	for (int c = 0; c < columns; c++)
	{
		grid[r + RowsCleared][c] = grid[r][c];
		grid[r][c] = 0;
	}
}
