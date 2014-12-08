#include "Tile.h"

namespace EightQueens
{
	Tile::Tile() : _isOpen(true)
	{

	}

	Tile::~Tile(){}

	void Tile::setOpen(bool value)
	{
		_isOpen = value;
	}

	bool Tile::getIsOpen()
	{
		return _isOpen;
	}
}