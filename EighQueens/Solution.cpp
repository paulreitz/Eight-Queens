#include "Solution.h"
#include <iostream>

using namespace std;

namespace EightQueens
{
	Solution::Solution()
	{
		for (int i = 0; i < 8; ++i)
		{
			_rows.push_back(-1);
		}
	}

	void Solution::printSolution()
	{
		int count = _rows.size();
		cout << " _ _ _ _ _ _ _ _ " << endl;
		for (int i = 0; i < count; ++i)
		{
			cout << "|";
			int current = _rows.at(i);
			for (int j = 0; j < 8; ++j)
			{
				if (j == current)
				{
					cout << "Q|";
				}
				else
				{
					cout << " |";
				}
			}
			cout << endl;
			cout << " - - - - - - - - " << endl;
		}
	}

	void Solution::setRowState(int index, int state)
	{
		if (index >= 0 && index < _rows.size())
		{
			_rows[index] = state;
		}
	}
}