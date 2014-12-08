#pragma once

namespace EightQueens
{
	class Tile
	{
	public:
		Tile();
		~Tile();
		void setOpen(bool value);
		bool getIsOpen();
	private:
		bool _isOpen;
	};
}