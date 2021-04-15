#include "Tablero.h"

Tablero::Tablero()
{
	columna = 8;
	fila = 8;
	tab = new string * [fila];
	for (int i = 0; i < fila; i++)
	{
		tab[i] = new string[columna];
	}

	tab2 = new string * [fila];
	for (int i = 0; i < fila; i++)
	{
		tab2[i] = new string[columna];

	}
}


Tablero::~Tablero()
{
}

string** Tablero::getTab()
{
	return tab;
}

string** Tablero::getTab2()
{
	return tab2;
}

string Tablero::toString() //Esta funcion muestra el tablero hecho para jugar
{
	stringstream s;
	int cont, cant;
	cont = 1;
	cant = 8;
	system("color 79");
	for (int i = 0; i < fila; i++)
	{
		s << " " << cant << "|" << " ";
		for (int j = 0; j < columna; j++)
		{
			s << tab[i][j] << " " << "|" << " ";
		}
		s << endl;
		s << "-----------------------------------" << endl;
		cant--;
	}
	s << "  " << "|";
	while (cont <= 8)
	{
		s << " " << cont << " " << "|";
		cont++;
	}
	s << endl << endl;
	return s.str();
}

void Tablero::armarTablero()//Aqui se arma el tablero con las fichas de cada jugador
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			if ((i == 0 && j % 2 == 0) || (i == 1 && !(j % 2 == 0)) || (i == 2 && j % 2 == 0))
			{
				tab[i][j] = "O";
			}
			else if ((i == 5 && !(j % 2 == 0)) || (i == 6 && j % 2 == 0) || (i == 7 && !(j % 2 == 0)))
			{
				tab[i][j] = "X";
			}
			else
			{
				tab[i][j] = " ";
			}
		}
	}
}

string Tablero::leer()
{
	stringstream a;
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			if (tab[i][j] == " ")
			{
				tab[i][j] = "-";
			}
			a << tab[i][j];

			a << " ";
		}
		a << endl;
	}

	return a.str();
}

bool Tablero::archivo(string name)
{
	fstream outfile;
	string file = name + ".txt";
	outfile.open(file.c_str(), ios::out);
	if (outfile.is_open())
	{
		outfile << leer() << endl;
		return true;
	}
	else
	{
		return false;
	}
	outfile.close();
}

bool Tablero::cargar(string partida)
{
	int i = 0, j = 0;
	string name = partida + ".txt";
	string line = " ";
	fstream file;
	file.open(name.c_str(), ios::in);
	if (file.is_open())
	{

		while (!file.eof() && i < fila && j < columna)
		{
			file >> line;
			if (line == "-")
			{
				line = " ";
			}
			tab2[i][j] = line;
			if (j == 7) {

				i++;
				j = 0;

			}
			else
			{
				j++;
			}
		}
		return true;
	}
	file.close();
	return false;
}

string Tablero::ordenar()
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			if (tab2[i][j] == "-")
			{
				tab2[i][j] = " ";
			}
		}
	}
	stringstream e;
	int cont, cant;
	cont = 1;
	cant = 8;
	for (int i = 0; i < fila; i++)
	{
		e << " " << cant << "|" << " ";
		for (int j = 0; j < columna; j++)
		{
			e << tab2[i][j] << " " << "|" << " ";
		}
		e << endl;
		e << "-----------------------------------" << endl;
		cant--;
	}
	e << "  " << "|";
	while (cont <= 8)
	{
		e << " " << cont << " " << "|";
		cont++;
	}
	e << endl << endl;
	return e.str();
}

void Tablero::igualar()
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			tab[i][j] = tab2[i][j];
		}
	}
}

int Tablero::ganar(){
	int cont = 0, cont2 = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {

			if(tab[i][j] == "X" || tab[i][j] == "B" ){

				cont++;

			}
			else if(tab[i][j] == "O" || tab[i][j] == "N"){

				cont2++;

			}
		}
	}
	if (cont == 0) {
		return 1;
	}
	else if (cont2 == 0) {
		return 0;
	}
	return -1;
}

void Tablero::registroMovi(int tip, int fil, int col, int fil1, int col1)
{
	int movi = 1;
	int come = 1;
	fstream registro;
	registro.open("Registro de movimientos del jugador.txt", ios::out | ios::app);
	if (registro.is_open())
	{
		if (tip == 0)
		{
			registro << "Movimiento " << movi << endl;
			registro << fil << col << "-" << fil1 << col1 << "." << endl;
			movi++;
		}
		if (tip == 1)
		{
			registro << "Comer " << movi << endl;
			registro << fil << col << "-" << fil1 << col1 << "." << endl;
			come++;
		}
	}
	registro.close();
}
