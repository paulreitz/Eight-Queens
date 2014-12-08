#pragma once

#include <vector>
#include "Tile.h"
#include "Direction.h"
#include "RowState.h"

namespace EightQueens
{
	class Row
	{
	public:
		Row(int index);
		Row() :_nextRow(nullptr), _index(0), _currentTile(0), _tiles(0), _states(0) {}
		~Row();
		void setTileLocked(int index, Direction d);
		bool setNextTile();
		void setState(int index);
		void setActiveRow(int index);
		void setNextRow(Row*& nextRow);
		int getCurrentIndex();
	private:
		Row* _nextRow;
		int _index;
		int _currentTile;
		std::vector<Tile*> _tiles;
		std::vector<RowState*> _states;
	};
}