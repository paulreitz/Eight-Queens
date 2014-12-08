#include "Board.h"
#include <iostream>

using namespace std;

namespace EightQueens
{
	Board::Board() : _currentRow(0), _continue(true)
	{
		for (int i = 0; i < 8; ++i)
		{
			_rows.push_back(new Row(i));
			if (i > 0)
			{
				_rows.at(i - 1)->setNextRow(_rows.at(i));
			}
		}
	}

	Board::~Board()
	{

	}

	void Board::placeNext()
	{
		//cout << "Place next on row: " << _currentRow << " ..." << endl;
		if (_rows.at(_currentRow)->setNextTile())
		{
			if (_currentRow == 7)
			{
				getSolution();
			}
			else
			{
				nextRow();
			}
		}
		else
		{
			if (_currentRow > 0)
			{
				previousRow();
			}
			else
			{
				_continue = false;
			}
		}
	}

	void Board::getSolution()
	{
		int last = _solutions.size();
		_solutions.push_back(new Solution());
		int count = _rows.size();
		for (int i = 0; i < count; ++i)
		{
			_solutions.at(last)->setRowState(i, _rows.at(i)->getCurrentIndex());
		}
		cout << "Found " << _solutions.size() << " solutions." << endl;
	}

	void Board::nextRow()
	{
		//cout << "next row: " << _currentRow << " to " << (_currentRow + 1) << endl;
		updateRowStates();
		_currentRow++;
	}

	void Board::previousRow()
	{
		//cout << "previous row: " << _currentRow << " to " << (_currentRow - 1) << endl;
		_currentRow--;
		ResetRowStates();
	}

	void Board::updateRowStates()
	{
		//cout << "update row states for row: " << _currentRow << endl;
		int count = _rows.size();
		for (int i = 0; i < count; ++i)
		{
			_rows.at(i)->setState(_currentRow);
		}
	}

	void Board::ResetRowStates()
	{
		//cout << "reset row states: " << _currentRow << endl;
		int count = _rows.size();
		for (int i = _currentRow + 1; i < count; ++i)
		{
			_rows.at(i)->setActiveRow(_currentRow);
		}
	}

	void Board::start()
	{
		cout << "Starting search" << endl;
		_continue = true;
		while (_continue)
		{
			placeNext();
		}
	}

	int Board::solutionCount()
	{
		return _solutions.size();
	}

	void Board::printSolution(int index)
	{
		if (index >= 0 && index < _solutions.size())
		{
			_solutions.at(index)->printSolution();
		}
	}
}