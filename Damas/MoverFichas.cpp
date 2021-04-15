#include "MoverFichas.h"

MoverFichas::MoverFichas()
{
	turno = 1;
	fila = 0;
	columna = 0;
	fila1 = 0;
	columna1 = 0;
	tablero = new string * [8];
	for (int i = 0; i < 8; i++)
	{
		tablero[i] = new string[8];
	}
}

MoverFichas::~MoverFichas()
{
}

bool MoverFichas::movimientoCorrecto()//verifica si el movimiento es correcto
{
	if (existeFicha(1, tablero, fila, columna))
	{
		if (tablero[fila1][columna1] == " " && fila1 == fila-1)
		{
			if (columna1 == columna + 1 || columna1 == columna - 1)
			{
				return true;
			}
		}
	}
	return false;
}

bool MoverFichas::mover(string** tab, int fil, int col, int fil1, int col1)//una vez verificado mueve la ficha
{
	fila = fil - 8;
	fila = abs(fila);
	columna = col - 1;
	fila1 = fil1 - 8;
	fila1 = abs(fila1);
	columna1 = col1 - 1;
	tablero = tab;
	if (movimientoCorrecto() && podiaComer(tab) == false)
	{
		tablero[fila1][columna1] = tablero[fila][columna];
		tablero[fila][columna] = " ";
		return true;
	}
	return false;
}

bool MoverFichas::moverDama(string** tab, int fil, int col, int fil1, int col1)
{
	fila = fil - 8;
	fila = abs(fila);
	columna = col - 1;
	fila1 = fil1 - 8;
	fila1 = abs(fila1);
	columna1 = col1 - 1;
	int x = abs(columna - columna1);
	int y = abs(fila - fila1);
	if (tab[fila][columna] == "B")
	{
		if (x == y)
		{
			if (fila1 > fila)
			{
				if (fila1 == fila + y)
				{
					if (columna1 > columna)
					{
						for (int i = x; i >= 0; i--)
						{
							for (int j = y; j >= 0; j--)
							{
								if (!(tab[fila + i][columna + j] == " "))
								{
									//return false;
								}
							}
						}
						tab[fila1][columna1] = tab[fila][columna];
						tab[fila][columna] = " ";
						return true;
					}
					else if (columna1 < columna)
					{
						for (int i = x; i >= 0; i--)
						{
							for (int j = y; j >= 0; j--)
							{
								if (!(tab[fila + i][columna - j] == " "))
								{
									//return false;
								}
							}
						}
						tab[fila1][columna1] = tab[fila][columna];
						tab[fila][columna] = " ";
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (fila1 == fila - y)
				{
					if (columna1 > columna)
					{
						for (int i = x; i >= 0; i--)
						{
							for (int j = y; j >= 0; j--)
							{
								if (!(tab[fila - i][columna + j] == " "))
								{
									//return false;
								}
							}
						}
						tab[fila1][columna1] = tab[fila][columna];
						tab[fila][columna] = " ";
						return true;
					}
					else if (columna1 < columna)
					{
						for (int i = x; i >= 0; i--)
						{
							for (int j = y; j >= 0; j--)
							{
								if (!(tab[fila - i][columna - j] == " "))
								{
									//return false;
								}
							}
						}
						tab[fila1][columna1] = tab[fila][columna];
						tab[fila][columna] = " ";
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return false;
}

void MoverFichas::coronar(string** tab)
{
	int i = 0;
	for (int j = 0; j < 8; j++)
	{
		if (tab[i][j] == "X")
		{
			tab[i][j] = "B";
		}
	}
}

bool MoverFichas::comer(string** tab, int fil, int col, int fil1, int col1)//algoritmo de comer
{
	fila = fil - 8;
	fila = abs(fila);
	columna = col - 1;
	fila1 = fil1 - 8;
	fila1 = abs(fila1);
	columna1 = col1 - 1;



	if (existeFicha(1, tab, fila, columna) == true && fila1 == fila - 2)
	{
		if (columna1 == columna - 2 && columna1 >= 0)
		{
			if (tab[fila - 1][columna - 1] == "O")
			{
				tab[fila1][columna1] = tab[fila][columna];
				tab[fila][columna] = " ";
				forzarEliminacion(tab, fila - 1, columna - 1);
				//tab[fila - 1][columna - 1] == " ";
				return true;
			}
		}
		else if (columna1 == columna + 2 && columna1 <= 7)
		{
			if (tab[fila - 1][columna + 1] == "O")
			{
				tab[fila1][columna1] = tab[fila][columna];
				tab[fila][columna] = " ";
				forzarEliminacion(tab, fila - 1, columna + 1);
				//tab[fila - 1][columna + 1] == " ";
				return true;
			}
		}

	}
	return false;
}

void MoverFichas::forzarEliminacion(string** tab, int fil, int col)
{
	fila = fil - 8;
	fila = abs(fila);
	columna = col - 1;
	tab[fila][columna] = " ";
}

bool MoverFichas::comerDama(string** tab, int fil, int col, int fil1, int col1)
{
	fila = fil - 8;
	fila = abs(fila);
	columna = col - 1;
	fila1 = fil1 - 8;
	fila1 = abs(fila1);
	columna1 = col1 - 1;
	int x = abs(columna - columna1);
	int y = abs(fila - fila1);
	int cont = 0, filBorrar = 0, colBorrar = 0;
	if (tab[fila][columna] == "B")
	{
		if (x == y)
		{
			if (fila1 > fila)
			{
				if (fila1 == fila + y)
				{
					if (columna1 > columna)
					{

						for (int i = x; i > 0; i--)
						{
							for (int j = y; j > 0; j--)
							{
								if (!(tab[fila + i][columna + j] == " "))
								{
									if (tab[fila + i][columna + j] == "O" || tab[fila + i][columna + j] == "N")
									{
										filBorrar = fila + i;
										colBorrar = columna + j;
										cont++;
									}
									else
									{
										return false;
									}
								}
							}
						}
						if (cont == 1)
						{
							tab[fila1][columna1] = tab[fila][columna];
							tab[fila][columna] = " ";
							tab[filBorrar][colBorrar] = " ";
							return true;
						}
						else
						{
							return false;
						}
					}
					else if (columna1 < columna)
					{
						for (int i = x; i > 0; i--)
						{
							for (int j = y; j > 0; j--)
							{
								if (!(tab[fila + i][columna - j] == " "))
								{
									if (tab[fila + i][columna - j] == "O" || tab[fila + i][columna - j] == "N")
									{
										filBorrar = fila + i;
										colBorrar = columna - j;
										cont++;
									}
									else
									{
										return false;
									}
								}
							}
						}
						if (cont == 1)
						{
							tab[fila1][columna1] = tab[fila][columna];
							tab[fila][columna] = " ";
							tab[filBorrar][colBorrar] = " ";
							return true;
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					if (fila1 = fila - y)
					{
						if (columna1 > columna)
						{
							for (int i = x; i >= 0; i--)
							{
								for (int j = y; j >= 0; j--)
								{
									if (!(tab[fila - i][columna + j] == " "))
									{
										if (tab[fila - i][columna + j] == "O" || tab[fila - i][columna + j] == "N")
										{
											filBorrar = fila - i;
											colBorrar = columna - j;
											cont++;
										}
										else
										{
											return false;
										}
									}
								}
							}
							if (cont == 1)
							{
								tab[fila1][columna1] = tab[fila][columna];
								tab[fila][columna] = " ";
								tab[filBorrar][colBorrar] = " ";
								return true;
							}
							else
							{
								return false;
							}
						}
						else if (columna1 < columna)
						{
							for (int i = x; i >= 0; i--)
							{
								for (int j = y; j >= 0; j--)
								{
									if (!(tab[fila - i][columna - j] == " "))
									{
										if (tab[fila - i][columna - j] == "O" || tab[fila - i][columna - j] == "N")
										{
											filBorrar = fila - i;
											colBorrar = columna - j;
											cont++;
										}
										else
										{
											return false;
										}
									}
								}
							}
							if (cont == 1)
							{
								tab[fila1][columna1] = tab[fila][columna];
								tab[fila][columna] = " ";
								tab[filBorrar][colBorrar] = " ";
								return true;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool MoverFichas::existeFicha(int i, string **tab, int fil, int col)//Valida si la ficha exite en esa posicion
{
	if(i==0)
	{
		fila = fil - 8;
		fila = abs(fila);
		columna = col - 1;
		tablero = tab;
	}
	else
	{
		fila = fil;
		columna = col;
		tablero = tab;
	}
	return((tablero[fila][columna] == "X") || (tablero[fila][columna] == "B"));
}

bool MoverFichas::existeDama(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tab[i][j] == "B")
			{
				return true;
			}
		}
	}
	return false;
}

bool MoverFichas::podiaComer(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j <= 1 && i >= 2)
			{
				if ((tab[i][j] == "X" || tab[i][j] == "B") && (tab[i - 1][j + 1] == "O" || tab[i - 1][j + 1] == "N") && tab[i - 2][j + 2] == " ")
				{
					return true;
				}
			}
			else if (j >= 6 && i >= 2)
			{
				if ((tab[i][j] == "X" || tab[i][j] == "B") && (tab[i - 1][j - 1] == "O" || tab[i - 1][j - 1] == "N") && tab[i - 2][j - 2] == " ")
				{
					return true;
				}
			}
			else if (i < 2)
			{
				i = 9;
				j = 9;
			}
			else
			{
				if ((tab[i][j] == "X" || tab[i][j] == "B") && ((tab[i - 1][j - 1] == "O" || tab[i - 1][j - 1] == "N") && tab[i - 2][j - 2] == " ") || (tab[i][j] == "X" || tab[i][j] == "B") && (tab[i - 1][j + 1] == "O" || tab[i - 1][j + 1] == "N") && tab[i - 2][j + 2] == " ")
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool MoverFichas::podiaMover(string** tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tab[i][j] == "X" || tab[i][j] == "B")
			{
				if (tab[i + 1][j + 1] == " " || tab[i + 1][j - 1] == " " || tab[i - 1][j - 1] == " " || tab[i - 1][j + 1] == " ")
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool MoverFichas::sinPosibilidad(string** tab)
{
	if (podiaComer(tab) == false)
	{
		if (podiaMover(tab) == false)
		{
			return false;
		}
	}
	return true;
}