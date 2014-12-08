#include <iostream>
#include <string>

#include "RowState.h"
#include "Row.h"
#include "Direction.h"
#include "Solution.h"
#include "Board.h"

using namespace std;
using namespace EightQueens;

/*
The goal of the Eight Queens Puzzle is to place eight queens 
on a chess board in such a way that no two queens threaten 
each other. There are 92 possible solutions. This program is 
intended to find all 92 solutions.
*/

int main()
{
	Board* board = new Board();
	board->start();
	string in;
	bool proceed = true;
	while (proceed)
	{
		cout << "Enter a number from 0 to " << (board->solutionCount() - 1) << ", or 'q' to quit" << endl;
		cin >> in;
		if (in == "q")
		{
			proceed = false;
		}
		else
		{
			int val = atoi(in.c_str());
			if (val >= 0 && val < board->solutionCount())
			{
				board->printSolution(val);
			}
			else
			{
				cout << "Invalid selection " << endl;
				cout << endl;
			}
		}
	}
	return EXIT_SUCCESS;
}