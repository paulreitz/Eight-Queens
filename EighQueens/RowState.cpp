#include "RowState.h"

using namespace std;

namespace EightQueens
{
	RowState::RowState()
	{
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
		_lst.push_back(true);
	}
	
	RowState::~RowState()
	{

	}

	void RowState::setList(vector<bool>& lst)
	{
		int count = lst.size();
		for (int i = 0; i < count; ++i)
		{
			_lst[i] = _lst.at(i);
		}
	}

	bool RowState::getState(int index)
	{
		if (index >= 0 && index < _lst.size())
		{
			return _lst.at(index);
		}
		return false;
	}

	void RowState::setState(int index, bool state)
	{
		if (index >= 0 && index < _lst.size())
		{
			_lst[index] = state;
		}
	}
}