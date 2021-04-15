#pragma once
#include <iostream>
#include "MoverFichas.h"
#include<fstream>
#include <sstream>
#include <string>

using namespace std;

class Tablero
{
public:
	Tablero();
	virtual ~Tablero();
	string** getTab();
	string** getTab2();
	string toString();
	void armarTablero();
	string leer();
	bool cargar(string);
	bool archivo(string);
	string ordenar();
	void igualar();
	int ganar();
	void registroMovi(int tip, int fil, int col, int fil1, int col1);
protected:
	string** tab;
private:
	string** tab2;
	int columna;
	int fila;
};




