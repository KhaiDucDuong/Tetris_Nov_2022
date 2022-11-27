#pragma once
class GameGrid
{
public:
	//default numbers of rows and columns for tetris game (only 20 rows will be displayed, the top 2 rows will be used to check if game is over
	//if row 0 or row 1 is not empty then game is over
	enum {rows = 22, columns = 10};
	//init every position in grid to 0
	GameGrid();
	//check if a position is in grid
	bool isInside(const int& r, const int& c);
	//check if a position is in grid and is empty (an empty position will have a value of 0)
	bool isEmpty(const int& r, const int& c);
	//check if a row in grid is full
	bool isRowFull(const int& r);
	//check if a row in grid is empty
	bool isRowEmpty(const int& r);
	
	//check every row, clear full rows and move rows that are not full down
	int clearRows();

	//set grid value to new block id
	void SetGridValue(const int& r, const int& c, const int& new_value);
private:
	int grid[rows][columns];

	void clearRow(const int& r);
	void moveRowDown(const int& r, const int& RowsCleared);
};

