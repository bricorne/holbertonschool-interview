#include "menger.h"

/**
* menger - Prints an N sized Menger Sponge
* @level: Menger level to print
*
* Return: Void
*/

void menger(int level)
{

	int row, col, _row, _col;
	int size = pow(3, level);
	char character;

	if (level < 0)
	{
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			_row = row;
			_col = col;

			character = '#';

			while (_row || _col)
			{
				if (_row % 3 == 1 && _col % 3 == 1)
				{
					character = ' ';
				}
				_row /= 3;
				_col /= 3;
			}
			putchar(character);
		}
	putchar('\n');
	}
}
