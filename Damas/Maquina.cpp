#include "Maquina.h"



Maquina::Maquina()
{
	this->ficha = new string("O");
	cantidad = 0;
}

Maquina::~Maquina()
{
}

string* Maquina::getFicha()
{
	return ficha;
}

void Maquina::setFicha(string* val)
{
	this->ficha = val;
}

int Maquina::sisComer(string** tab)
{
	cantidad = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j <= 1 && i <= 5)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " ")
				{
					cantidad++;
				}
			}
			else if (j >= 6 && i <= 5)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " ")
				{
					cantidad++;
				}
			}
			else if (i > 5)
			{
				i = 9;
				j = 9;
			}
			else
			{
				if ((tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " ") || (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " "))
				{
					cantidad++;
				}
			}
		}
	}
	return cantidad;
}

bool Maquina::comerNormal(string** tab)
{
	int x = sisComer(tab);
	if (x > 0)
	{
		bool q = comerDos(tab);
		if (q == false)
		{
			q = comerUna(tab);
			if (q == false)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Maquina::comerUna(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j <= 1 && i <= 5)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " ")
				{
					tab[i + 2][j + 2] = tab[i][j];
					tab[i + 1][j + 1] = " ";
					tab[i][j] = " ";
					return true;
				}
			}
			else if (j >= 6 && i <= 5)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " ")
				{
					tab[i + 2][j - 2] = tab[i][j];
					tab[i + 1][j - 1] = " ";
					tab[i][j] = " ";
					return true;
				}
			}
			else if (i > 5)
			{
				i = 9;
				j = 9;
			}
			else
			{
				if ((tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " "))
				{
					tab[i + 2][j - 2] = tab[i][j];
					tab[i + 1][j - 1] = " ";
					tab[i][j] = " ";
					return true;
				}
				else if (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " ")
				{
					tab[i + 2][j + 2] = tab[i][j];
					tab[i + 1][j + 1] = " ";
					tab[i][j] = " ";
					return true;
				}
			}
		}
	}
	return false;
}

bool Maquina::comerDos(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j <= 1 && i <= 3)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " ")
				{
					if ((tab[i + 3][j + 1] == "X" || tab[i + 3][j + 1] == "B") && tab[i + 4][j] == " ")
					{
						tab[i + 1][j + 1] = " ";
						tab[i + 3][j + 1] = " ";
						tab[i + 4][j] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
					else if ((tab[i + 3][j + 3] == "X" || tab[i + 3][j + 3] == "B") && tab[i + 4][j + 4] == " ")
					{
						tab[i + 1][j + 1] = " ";
						tab[i + 3][j + 3] = " ";
						tab[i + 4][j + 4] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
				}
			}
			else if (j >= 6 && i <= 3)
			{
				if (tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " ")
				{
					if ((tab[i + 3][j - 1] == "X" || tab[i + 3][j - 1] == "B") && tab[i + 4][j] == " ")
					{
						tab[i + 1][j - 1] = " ";
						tab[i + 3][j - 1] = " ";
						tab[i + 4][j] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
					else if ((tab[i + 3][j - 3] == "X" || tab[i + 3][j - 3] == "B") && tab[i + 4][j - 4] == " ")
					{
						tab[i + 1][j - 1] = " ";
						tab[i + 3][j - 3] = " ";
						tab[i + 4][j - 4] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
				}
			}
			else if (i > 3)
			{
				i = 9;
				j = 9;
			}
			else
			{
				if (tab[i][j] == "O" && (tab[i + 1][j + 1] == "X" || tab[i + 1][j + 1] == "B") && tab[i + 2][j + 2] == " ")
				{
					if ((tab[i + 3][j + 1] == "X" || tab[i + 3][j + 1] == "B") && tab[i + 4][j] == " ")
					{
						tab[i + 1][j + 1] = " ";
						tab[i + 3][j + 1] = " ";
						tab[i + 4][j] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
					else if ((tab[i + 3][j + 3] == "X" || tab[i + 3][j + 3] == "B") && tab[i + 4][j + 4] == " ")
					{
						tab[i + 1][j + 1] = " ";
						tab[i + 3][j + 3] = " ";
						tab[i + 4][j + 4] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
				}
				if (tab[i][j] == "O" && (tab[i + 1][j - 1] == "X" || tab[i + 1][j - 1] == "B") && tab[i + 2][j - 2] == " ")
				{
					if ((tab[i + 3][j - 1] == "X" || tab[i + 3][j - 1] == "B") && tab[i + 4][j] == " ")
					{
						tab[i + 1][j - 1] = " ";
						tab[i + 3][j - 1] = " ";
						tab[i + 4][j] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
					else if ((tab[i + 3][j - 3] == "X" || tab[i + 3][j - 3] == "B") && tab[i + 4][j - 4] == " ")
					{
						tab[i + 1][j - 1] = " ";
						tab[i + 3][j - 3] = " ";
						tab[i + 4][j - 4] = tab[i][j];
						tab[i][j] = " ";
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Maquina::coronar(string** tab)
{
	int i = 7;
	for (int j = 0; j < 8; j++)
	{
		if (tab[i][j] == "O")
		{
			tab[i][j] = "N";
		}
	}
}

bool Maquina::existeDama(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tab[i][j] == "N")
			{
				return true;
			}
		}
	}
	return false;
}

bool Maquina::podiaMover(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tab[i][j] == "O" || tab[i][j] == "N")
			{
				if (i = 0)
				{
					if (j == 0)
					{
						if (tab[i + 1][j + 1] == " ")
						{
							return true;
						}
					}
					else if (j == 7)
					{
						if (tab[i + 1][j - 1] == " ")
						{
							return true;
						}
					}
				}
				else if (i = 7)
				{
					if (j == 0)
					{
						if (tab[i - 1][j + 1] == " ")
						{
							return true;
						}
					}
					else if (j == 7)
					{
						if (tab[i - 1][j - 1] == " ")
						{
							return true;
						}
					}
				}
				else
				{

					if (j == 0)
					{
						if (tab[i - 1][j + 1] == " ")
						{
							return true;
						}
					}
					else if (j == 7)
					{
						if (tab[i - 1][j - 1] == " ")
						{
							return true;
						}
					}
					else
					{
						if (tab[i + 1][j + 1] == " " || tab[i + 1][j - 1] == " " || tab[i - 1][j - 1] == " " || tab[i - 1][j + 1] == " ")
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Maquina::sinPosibilidad(string** tab)
{
	if (sisComer(tab) == 0)
	{
		if (podiaMover(tab) == false)
		{
			return false;
		}
	}
	return true;
}

bool Maquina::comerDama(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; i < 8; i++)
		{
			if (tab[i][j] == "N")
			{
				if (i >= 2 && j == 0 && i <= 5)
				{
					int x = i, y = j;
					while (x < 6 && y < 8)
					{
						if ((tab[x + 1][y + 1] != " " && tab[x + 1][y + 1] != "O" && tab[x + 1][y + 1] != "N") && tab[x + 2][y + 2] == " ")
						{
							if (x + 2 == 7 || x == 4)
							{
								if ((tab[x + 1][y + 3] == "X" || tab[x + 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x + 1][y + 3] == "X" || tab[x + 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x + 1][y + 1] != " " && tab[x + 1][y + 1] == "O" && tab[x + 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x++;
							y++;
						}
					}
					x = i, y = j;
					while (x > 1 && y > 0)
					{
						if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] != "O" && tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
						{
							if (x - 2 == 0)
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] == "O" && tab[x - 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x--;
							y--;
						}
					}
				}


				else if (i >= 2 && j == 7 && i <= 5)
				{
					int x = i, y = j;
					while (x < 6 && y < 8)
					{
						if ((tab[x + 1][y - 1] != " " && tab[x + 1][y - 1] != "O" && tab[x + 1][y - 1] != "N") && tab[x + 2][y - 2] == " ")
						{
							if (x + 2 == 7 || x == 4)
							{
								if ((tab[x + 1][y - 3] == "X" || tab[x + 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 2][y - 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x + 1][y - 3] == "X" || tab[x + 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 1][y - 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" || tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x + 1][y - 1] != " " && tab[x + 1][y - 1] == "O" && tab[x + 1][y - 1] == "N"))
						{
							break;
						}
						else
						{
							x++;
							y++;
						}
					}
					x = i, y = j;
					while (x > 1 && y > 0)
					{
						if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] != "O" && tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
						{
							if (x - 2 == 0)
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] == "O" && tab[x - 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x--;
							y--;
						}
					}
				}

				else if (i >= 2 && i <= 5)
				{
					int x = i, y = j;
					while (x < 6 && y < 8)
					{
						if ((tab[x + 1][y + 1] != " " && tab[x + 1][y + 1] != "O" && tab[x + 1][y + 1] != "N") && tab[x + 2][y + 2] == " ")
						{
							if (x + 2 == 7 || x == 4)
							{
								if ((tab[x + 1][y + 3] == "X" || tab[x + 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x + 1][y + 3] == "X" || tab[x + 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y + 1] = " ";
									tab[x + 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x + 1][y + 1] != " " && tab[x + 1][y + 1] == "O" && tab[x + 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x++;
							y++;
						}
					}
					x = i, y = j;
					while (x > 1 && y > 0)
					{
						if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] != "O" && tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
						{
							if (x - 2 == 0)
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] == "O" && tab[x - 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x--;
							y--;
						}
					}

					x = i, y = j;
					while (x < 6 && y < 8)
					{
						if ((tab[x + 1][y - 1] != " " && tab[x + 1][y - 1] != "O" && tab[x + 1][y - 1] != "N") && tab[x + 2][y - 2] == " ")
						{
							if (x + 2 == 7 || x == 4)
							{
								if ((tab[x + 1][y - 3] == "X" || tab[x + 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 2][y - 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x + 1][y - 3] == "X" || tab[x + 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x + 1][y - 1] = " ";
									tab[x + 1][y - 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" || tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x + 1][y - 1] != " " && tab[x + 1][y - 1] == "O" && tab[x + 1][y - 1] == "N"))
						{
							break;
						}
						else
						{
							x++;
							y++;
						}
					}
					x = i, y = j;
					while (x > 1 && y > 0)
					{
						if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] != "O" && tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
						{
							if (x - 2 == 0)
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
							else
							{
								if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" || tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] = "N";
									return true;
								}
							}
						}
						else if ((tab[x - 1][y + 1] != " " && tab[x - 1][y + 1] == "O" && tab[x - 1][y + 1] == "N"))
						{
							break;
						}
						else
						{
							x--;
							y--;
						}
					}
				}

				else if (i > 5)
				{
					int x = i, y = j;
					if (j == 0)
					{
						while (x >= 0)
						{
							if (tab[x - 1][y + 1] != " " && (tab[x - 1][y + 1] != "O" || tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
							{
								if ((tab[i - 3][y + 1] == "X" && tab[i - 3][y + 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y + 3] == "X" && tab[x - 3][y + 3] == "B") && tab[x - 4][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 3] = " ";
									tab[x - 4][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" && tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] == "N";
									return true;
								}
							}
							x--;
						}
					}
					else if (j == 7)
					{

						while (x >= 0)
						{
							if (tab[x - 1][y - 1] != " " && (tab[x - 1][y - 1] != "O" || tab[x - 1][y - 1] != "N") && tab[x - 2][y - 2] == " ")
							{
								if ((tab[i - 3][y - 1] == "X" && tab[i - 3][y - 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y - 3] == "X" && tab[x - 3][y - 3] == "B") && tab[x - 4][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 3] = " ";
									tab[x - 4][y - 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" && tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] == "N";
									return true;
								}
							}
							x--;
						}
					}
					else
					{
						while (x >= 0)
						{
							if (tab[x - 1][y + 1] != " " && (tab[x - 1][y + 1] != "O" || tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
							{
								if ((tab[i - 3][y + 1] == "X" && tab[i - 3][y + 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y + 3] == "X" && tab[x - 3][y + 3] == "B") && tab[x - 4][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 3] = " ";
									tab[x - 4][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" && tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] == "N";
									return true;
								}
							}
							x--;
						}
						while (x >= 0)
						{
							if (tab[x - 1][y - 1] != " " && (tab[x - 1][y - 1] != "O" || tab[x - 1][y - 1] != "N") && tab[x - 2][y - 2] == " ")
							{
								if ((tab[i - 3][y - 1] == "X" && tab[i - 3][y - 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y - 3] == "X" && tab[x - 3][y - 3] == "B") && tab[x - 4][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 3] = " ";
									tab[x - 4][y - 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" && tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] == "N";
									return true;
								}
							}
							x--;
						}
					}
				}

				else if (i < 2)
				{
					int x = i, y = j;
					if (j == 0)
					{
						while (x < 8)
						{
							if (tab[x - 1][y + 1] != " " && (tab[x - 1][y + 1] != "O" || tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
							{
								if ((tab[i - 3][y + 1] == "X" && tab[i - 3][y + 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y + 3] == "X" && tab[x - 3][y + 3] == "B") && tab[x - 4][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 3] = " ";
									tab[x - 4][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" && tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] == "N";
									return true;
								}
							}
							x++;
						}
					}
					else if (j == 7)
					{

						while (x < 8)
						{
							if (tab[x - 1][y - 1] != " " && (tab[x - 1][y - 1] != "O" || tab[x - 1][y - 1] != "N") && tab[x - 2][y - 2] == " ")
							{
								if ((tab[i - 3][y - 1] == "X" && tab[i - 3][y - 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y - 3] == "X" && tab[x - 3][y - 3] == "B") && tab[x - 4][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 3] = " ";
									tab[x - 4][y - 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" && tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] == "N";
									return true;
								}
							}
							x++;
						}
					}
					else
					{
						while (x < 8)
						{
							if (tab[x - 1][y + 1] != " " && (tab[x - 1][y + 1] != "O" || tab[x - 1][y + 1] != "N") && tab[x - 2][y + 2] == " ")
							{
								if ((tab[i - 3][y + 1] == "X" && tab[i - 3][y + 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y + 3] == "X" && tab[x - 3][y + 3] == "B") && tab[x - 4][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 3][y + 3] = " ";
									tab[x - 4][y + 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y + 3] == "X" && tab[x - 1][y + 3] == "B") && tab[x][y + 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 1][y + 3] = " ";
									tab[x][y + 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y + 1] = " ";
									tab[x - 2][y + 2] == "N";
									return true;
								}
							}
							x++;
						}
						while (x < 8)
						{
							if (tab[x - 1][y - 1] != " " && (tab[x - 1][y - 1] != "O" || tab[x - 1][y - 1] != "N") && tab[x - 2][y - 2] == " ")
							{
								if ((tab[i - 3][y - 1] == "X" && tab[i - 3][y - 1] == "B") && tab[i - 4][y] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 1] = " ";
									tab[x - 4][y] = "N";
									return true;
								}
								else if ((tab[x - 3][y - 3] == "X" && tab[x - 3][y - 3] == "B") && tab[x - 4][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 3][y - 3] = " ";
									tab[x - 4][y - 4] = "N";
									return true;
								}
								else if ((tab[x - 1][y - 3] == "X" && tab[x - 1][y - 3] == "B") && tab[x][y - 4] == " ")
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 1][y - 3] = " ";
									tab[x][y - 4] = "N";
									return true;
								}
								else
								{
									tab[x][y] = " ";
									tab[x - 1][y - 1] = " ";
									tab[x - 2][y - 2] == "N";
									return true;
								}
							}
							x++;
						}
					}
				}
			}
		}
	}
	return false;
}
