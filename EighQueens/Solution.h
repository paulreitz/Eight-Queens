#pragma once
#include <vector>

namespace EightQueens
{

	class Solution
	{
		std::vector<int> _rows;
	public:
		Solution();
		void printSolution();
		void setRowState(int index, int queenPosition);
	};
}