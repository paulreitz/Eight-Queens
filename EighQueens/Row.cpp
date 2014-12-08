#include "Row.h"
#include <iostream>

using namespace std;

namespace EightQueens
{
	Row::Row(int index) : _index(index), _nextRow(nullptr), _currentTile(-1)
	{
		for (int i = 0; i < 8; ++i)
		{
			_tiles.push_back(new Tile());
			_states.push_back(new RowState());
		}
	}

	Row::~Row()
	{

	}

	void Row::setTileLocked(int index, Direction d)
	{
		if (index >= 0 && index < _tiles.size())
		{
			_tiles.at(index)->setOpen(false);
			if (_nextRow != nullptr)
			{
				int newIndex = index + d;
				_nextRow->setTileLocked(newIndex, d);
			}
		}
	}

	bool Row::setNextTile()
	{
		int count = _tiles.size();
		for (int i = (_currentTile + 1); i < count; ++ i)
		{
			if (_tiles.at(i)->getIsOpen())
			{
				_currentTile = i;
				if (_nextRow != nullptr)
				{
					_nextRow->setTileLocked(i + EQ_DIAGONAL_LEFT, EQ_DIAGONAL_LEFT);
					_nextRow->setTileLocked(i + EQ_DIAGONAL_RIGHT, EQ_DIAGONAL_RIGHT);
					_nextRow->setTileLocked(i, EQ_DOWN);
				}
				//cout << "set " << _currentTile << " on row " << _index << endl;
				return true;
			}
		}
		return false;
	}

	void Row::setState(int index)
	{
		if (index >= 0 && index < _states.size())
		{
			int count = _tiles.size();
			for (int i = 0; i < count; ++i)
			{
				_states.at(index)->setState(i, _tiles.at(i)->getIsOpen());
			}
		}
	}

	void Row::setActiveRow(int index)
	{
		int count = _tiles.size();
		if (index == 0)
		{
			for (int i = 0; i < count; ++i)
			{
				_tiles.at(i)->setOpen(true);
			}
		}
		else if (index > 0 && index < _states.size())
		{
			for (int i = 0; i < count; ++i)
			{
				_tiles.at(i)->setOpen(_states.at(index - 1)->getState(i));
			}
		}
		_currentTile = -1;
	}

	void Row::setNextRow(Row*& next)
	{
		_nextRow = next;
	}

	int Row::getCurrentIndex()
	{
		return _currentTile;
	}
}