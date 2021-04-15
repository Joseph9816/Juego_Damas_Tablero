#include "modoDificil.h"

bool modoDificil::mover(string** tab) {

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int noRecomendado1[25];
	int noRecomendado[25];
	int recomendado1[25];
	int recomendado[25];
	int mejor[25];
	int mejor1[25];
	for (int i = 0; i < 25; i++)
	{
		noRecomendado1[i] = 0;
		noRecomendado[i] = 0;
		recomendado1[i] = 0;
		recomendado[i] = 0;
		mejor[i] = 0;
		mejor1[i] = 0;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0 && i < 7)
			{
				if (tab[i][j] == "O")
				{
					if (tab[i + 1][j + 1] == " ")
					{
						if ((tab[i + 2][j + 2] == "X" || tab[i + 2][j + 2] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j + 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j] == "X" || tab[i + 2][j] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j + 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j + 2] == "O" || tab[i + 2][j + 2] == "N"))
						{
							if (((tab[i + 2][j] == " ") || (tab[i + 2][j] == "O" || tab[i + 2][j] == "N")) && i != 0)
							{
								tab[i + 1][j + 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j + 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;

							}
						}
						else if ((tab[i + 2][j] == "O" || tab[i + 2][j] == "N"))
						{
							if (j >= 2 && ((tab[i + 2][j + 2] == " ") || (tab[i + 2][j + 2] == "O" || tab[i + 2][j + 2] == "N")) && 1 != 0)
							{
								tab[i + 1][j + 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j + 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;

							}
						}
						else if (tab[i + 2][j + 2] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j + 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
						else if (tab[i + 2][j] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j + 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
					}
				}
			}
			else if (j == 7 && i < 7)
			{
				if (tab[i][j] == "O")
				{
					if (tab[i + 1][j - 1] == " ")
					{
						if ((tab[i + 2][j - 2] == "X" || tab[i + 2][j - 2] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j - 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j] == "X" || tab[i + 2][j] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j - 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j - 2] == "O" || tab[i + 2][j - 2] == "N"))
						{
							if (((tab[i + 2][j] == " ") || (tab[i + 2][j] == "O" || tab[i + 2][j] == "N")) && 1 != 0)
							{
								tab[i + 1][j - 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j - 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}

						}
						else if ((tab[i + 2][j] == "O" || tab[i + 2][j] == "N"))
						{
							if (((tab[i + 2][j - 2] == " ") || (tab[i + 2][j - 2] == "O" || tab[i + 2][j - 2] == "N")) && 1 != 0)
							{
								tab[i + 1][j - 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j - 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}
						}
						else if (tab[i - 2][j - 2] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j - 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
						else if (tab[i + 2][j] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j - 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
					}
				}
			}
			else if (i == 7)
			{
				j = 8;
			}
			else
			{
				if (tab[i][j] == "O")
				{
					if (tab[i + 1][j + 1] == " ")
					{
						if ((tab[i + 2][j + 2] == "X" || tab[i + 2][j + 2] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j + 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j] == "X" || tab[i + 2][j] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j + 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j + 2] == "O" || tab[i + 2][j + 2] == "N"))
						{
							if (((tab[i + 2][j] == " ") || (tab[i + 2][j] == "O" || tab[i + 2][j] == "N")) && 1 != 0)
							{
								tab[i + 1][j + 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j + 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}
						}
						else if ((tab[i + 2][j] == "O" || tab[i + 2][j] == "N"))
						{
							if (j >= 2 && ((tab[i + 2][j + 2] == " ") || (tab[i + 2][j + 2] == "O" || tab[i + 2][j + 2] == "N")) && 1 != 0)
							{
								tab[i + 1][j + 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j + 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}
						}
						else if (tab[i + 2][j + 2] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j + 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
						else if (tab[i + 2][j] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j + 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
					}
					if (tab[i + 1][j - 1] == " ")
					{
						if ((tab[i + 2][j - 2] == "X" || tab[i + 2][j - 2] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j - 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j] == "X" || tab[i + 2][j] == "B"))
						{
							noRecomendado1[c] = i + 1;
							c++;
							noRecomendado1[c] = j - 1;
							c++;
							noRecomendado[a] = i;
							a++;
							noRecomendado[a] = j;
							a++;
						}
						else if ((tab[i + 2][j - 2] == "O" || tab[i + 2][j - 2] == "N"))
						{
							if (((tab[i + 2][j] == " ") || (tab[i + 2][j] == "O" || tab[i + 2][j] == "N")) && 1 != 0)
							{
								tab[i + 1][j - 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j - 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}

						}
						else if ((tab[i + 2][j] == "O" || tab[i + 2][j] == "N"))
						{
							if (((tab[i + 2][j - 2] == " ") || (tab[i + 2][j - 2] == "O" || tab[i + 2][j - 2] == "N")) && 1 != 0)
							{
								tab[i + 1][j - 1] = tab[i][j];
								tab[i][j] = " ";
								return true;
							}
							else
							{
								mejor1[e] = i + 1;
								e++;
								mejor1[e] = j - 1;
								e++;
								mejor[e] = i;
								f++;
								mejor[e] = j;
								f++;
							}
						}
						else if (tab[i - 2][j - 2] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j - 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
						else if (tab[i + 2][j] == " ")
						{
							recomendado1[d] = i + 1;
							d++;
							recomendado1[d] = j - 1;
							d++;
							recomendado[b] = i;
							b++;
							recomendado[b] = j;
							b++;
						}
					}
				}

			}
		}
	}

	if (e != 0)
	{
		int num = rand() % (e + 1);
		if (num == 0)
		{
			tab[mejor1[num]][mejor1[num + 1]] = tab[mejor[num]][mejor[num + 1]];
			tab[mejor[num]][mejor[num + 1]] = " ";
			return true;
		}
		else if (num % 2 == 0)
		{
			tab[mejor1[num]][mejor1[num + 1]] = tab[mejor[num]][mejor[num + 1]];
			tab[mejor[num]][mejor[num + 1]] = " ";
			return true;
		}
		else
		{
			tab[mejor1[num - 1]][mejor1[num]] = tab[mejor[num - 1]][mejor[num]];
			tab[mejor[num - 1]][mejor[num]] = " ";
			return true;
		}
	}
	else if (b != 0)
	{
		int num = rand() % (b + 1);
		if (num == 0)
		{
			tab[recomendado1[num]][recomendado1[num + 1]] = tab[recomendado[num]][recomendado[num + 1]];
			tab[recomendado[num]][recomendado[num + 1]] = " ";
			return true;
		}
		else if (num % 2 == 0)
		{
			tab[recomendado1[num]][recomendado1[num + 1]] = tab[recomendado[num]][recomendado[num + 1]];
			tab[recomendado[num]][recomendado[num + 1]] = " ";
			return true;
		}
		else
		{
			tab[recomendado1[num - 1]][recomendado1[num]] = tab[recomendado[num - 1]][recomendado[num]];
			tab[recomendado[num - 1]][recomendado[num]] = " ";
			return true;
		}
	}
	else if (a != 0)
	{
		int num = rand() % (a + 1);
		if (num == 0)
		{
			tab[recomendado1[num]][recomendado1[num + 1]] = tab[recomendado[num]][recomendado[num + 1]];
			tab[recomendado[num]][recomendado[num + 1]] = " ";
			return true;
		}
		else if (num % 2 == 0)
		{
			tab[recomendado1[num]][recomendado1[num + 1]] = tab[recomendado[num]][recomendado[num + 1]];
			tab[recomendado[num]][recomendado[num + 1]] = " ";
			return true;
		}
		else
		{
			tab[recomendado1[num - 1]][recomendado1[num]] = tab[recomendado[num - 1]][recomendado[num]];
			tab[recomendado[num - 1]][recomendado[num]] = " ";
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool modoDificil::moverDama(string** tab)
{
	if (existeDama(tab) == false)
	{
		return false;
	}
	else
	{
		int a = 0, q = 0, w = 0;
		int damas[10];
		for (int i = 0; i < 10; i++)
		{
			damas[i] = 0;
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (tab[i][j] == "N")
				{
					damas[a] = i;
					a++;
					damas[a] = j;
					a++;
				}
			}
		}
		int z = rand() % (a + 1);
		if (z == 0)
		{
			q = damas[z];
			w = damas[z + 1];
		}
		else if (z % 2 == 0)
		{
			q = damas[z];
			w = damas[z + 1];
		}
		else
		{
			q = damas[z - 1];
			w = damas[z];
		}

		int contDerecha = 0, contIzquierda = 0;
		if (q <= 3)
		{
			if (w == 0)
			{
				while (q < 7 && w < 7)
				{
					if (tab[q + 1][w + 1] == " ")
					{
						if (((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == " ")) || ((tab[q][w + 2] == " ") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")))
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
						}
					}
					else
					{
						break;
					}
					q++;
					w++;
				}
				return true;
			}
			else if (w == 7)
			{
				while (q < 7 && w > 1)
				{
					if (tab[q + 1][w - 1] == " ")
					{
						if (((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == " ")) || ((tab[q][w - 2] == " ") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")))
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
						}
					}
					else
					{
						break;
					}
					q++;
					w--;
				}
				return true;
			}
			else
			{
				while (q < 7 && w < 7)
				{
					if (tab[q + 1][w + 1] == " ")
					{
						if (((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q + 2][w] == " ")) || ((tab[q][w + 2] == " ") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")))
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							contDerecha++;
						}
					}
					else
					{
						break;
					}
					q++;
					w++;
				}
				while (q < 7 && w > 1)
				{
					if (tab[q + 1][w - 1] == " ")
					{
						if (((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q + 2][w] == "X" || tab[q + 2][w] == "B")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q + 2][w] == " ")) || ((tab[q][w - 2] == " ") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q + 2][w] == "O" || tab[q + 2][w] == "N")))
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							contIzquierda++;
						}
					}
					else
					{
						break;
					}
					q++;
					w--;
				}
				if (contDerecha > contIzquierda)
				{
					while (q < 7 && w < 7)
					{
						if (tab[q + 1][w + 1] == " ")
						{
							tab[q + 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
						}
						else
						{
							break;
						}
						q++;
						w++;
					}
					return true;
				}
				else
				{
					while (q < 7 && w > 1)
					{
						if (tab[q + 1][w - 1] == " ")
						{
							tab[q + 1][w - 1] = tab[q][w];
							tab[q][w] = " ";
						}
						else
						{
							break;
						}
						q++;
						w--;
					}
					return true;
				}
			}
		}

		else
		{
			if (w == 0)
			{
				while (q > 1 && w < 7)
				{
					if (tab[q - 1][w + 1] == " ")
					{
						if (((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == " ")) || ((tab[q][w + 2] == " ") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")))
						{
							tab[q - 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							tab[q - 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
						}
					}
					else
					{
						break;
					}
					q--;
					w++;
				}
				return true;
			}
			else if (w == 7)
			{
				while (q > 1 && w > 1)
				{
					if (tab[q - 1][w - 1] == " ")
					{
						if (((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == " ")) || ((tab[q][w - 2] == " ") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")))
						{
							tab[q - 1][w - 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							tab[q - 1][w - 1] = tab[q][w];
							tab[q][w] = " ";
						}
					}
					else
					{
						break;
					}
					q--;
					w--;
				}
				return true;
			}
			else
			{
				while (q > 1 && w < 7)
				{
					if (tab[q - 1][w + 1] == " ")
					{
						if (((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w + 2] == "O" || tab[q][w + 2] == "N") && (tab[q - 2][w] == " ")) || ((tab[q][w + 2] == " ") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w + 2] == "X" || tab[q][w + 2] == "B") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")))
						{
							tab[q - 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							contDerecha++;
						}
					}
					else
					{
						break;
					}
					q--;
					w++;
				}
				while (q > 1 && w > 1)
				{
					if (tab[q - 1][w - 1] == " ")
					{
						if (((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q - 2][w] == "X" || tab[q - 2][w] == "B")) || ((tab[q][w - 2] == "O" || tab[q][w - 2] == "N") && (tab[q - 2][w] == " ")) || ((tab[q][w - 2] == " ") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")) || ((tab[q][w - 2] == "X" || tab[q][w - 2] == "B") && (tab[q - 2][w] == "O" || tab[q - 2][w] == "N")))
						{
							tab[q - 1][w - 1] = tab[q][w];
							tab[q][w] = " ";
							return true;
						}
						else
						{
							contIzquierda++;
						}
					}
					else
					{
						break;
					}
					q--;
					w--;
				}
				if (contDerecha > contIzquierda)
				{
					while (q > 1 && w < 7)
					{
						if (tab[q - 1][w + 1] == " ")
						{
							tab[q - 1][w + 1] = tab[q][w];
							tab[q][w] = " ";
						}
						else
						{
							break;
						}
						q--;
						w++;
					}
					return true;
				}
				else
				{
					while (q > 1 && w > 1)
					{
						if (tab[q - 1][w - 1] == " ")
						{
							tab[q - 1][w - 1] = tab[q][w];
							tab[q][w] = " ";
						}
						else
						{
							break;
						}
						q--;
						w--;
					}
					return true;
				}
			}
		}
	}
}
