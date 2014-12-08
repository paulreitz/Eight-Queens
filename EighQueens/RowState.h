#pragma once

#include <vector>


namespace EightQueens
{
	class RowState
	{
	public:
		RowState();
		~RowState();
		void setList(std::vector<bool>& lst);
		bool getState(int index);
		void setState(int index, bool state);
	private:
		std::vector<bool> _lst;
	};
}