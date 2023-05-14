#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	if (rand()%4 == 0)
	{
		return true;
	}
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
	celija_zauzeta(i + 1, j + 1);
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i == 0 || i == REDAKA - 1 || j == 0 || j == STUPACA)
			{
				_sljedeca_generacija[i][j] = false;
			}
			_sljedeca_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA - 1; i++)
	{
		for (int j = 0; j < STUPACA - 1; j++)
		{
			int broj = 0;
			if (_generacija[i - 1][j - 1])broj++;
			else if (_generacija[i][j - 1])broj++;
			else if (_generacija[i - 1][j])broj++;
			else if (_generacija[i + 1][j + 1])broj++;
			else if (_generacija[i + 1][j - 1])broj++;
			else if (_generacija[i + 1][j])broj++;
			else if (_generacija[i - 1][j + 1])broj++;
			else if (_generacija[i][j + 1])broj++;;
			{
				if (_generacija[i][j])
				{
					if (broj < 2 || broj > 3)
					{
						_sljedeca_generacija[i][j] = false;
					}
				}
				else
				{
					if (broj == 3)
					{
						_sljedeca_generacija[i][j] = true;
					}

				}
			}
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 1; i < REDAKA; i++)
	{
		for (int j = 1; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	for (int i = 1; i < REDAKA - 1; i++)
	{
		for (int j = 1; j < STUPACA - 1; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
}

