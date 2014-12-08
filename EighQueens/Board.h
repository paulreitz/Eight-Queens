#pragma once
#include <vector>
#include "Row.h"
#include "RowState.h"
#include "Solution.h"

namespace EightQueens
{
	class Board
	{
		std::vector<Row*> _rows;
		std::vector<Solution*> _solutions;
		bool _continue;
		int _currentRow;
		void placeNext();
		void getSolution();
		void nextRow();
		void previousRow();
		void updateRowStates();
		void ResetRowStates();
	public:
		Board();
		~Board();
		void start();
		int solutionCount();
		void printSolution(int index);
	};
}