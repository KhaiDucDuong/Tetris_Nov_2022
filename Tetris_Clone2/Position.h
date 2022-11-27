#pragma once

class Position
{
public:
	int Row;
	int Column;
	Position()
	{
		Row = 0;
		Column = 0;
	}

	Position(int row, int column)
	{
		Row = row;
		Column = column;
	}

	Position operator + (const Position& pos)
	{
		Position new_pos;
		new_pos.Row = Row + pos.Row;
		new_pos.Column = Column + pos.Column;
		return new_pos;
	}
};