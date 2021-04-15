#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class MoverFichas
{
public:
	MoverFichas();
	virtual ~MoverFichas();
	bool movimientoCorrecto();
	bool mover(string** tab, int fil, int col, int fil1, int col1);
	bool moverDama(string** tab, int fil, int col, int fil1, int col1);
	void coronar(string** tab);
	bool comer(string** tab, int fil, int col, int fil1, int col1);
	void forzarEliminacion(string** tab, int fil, int col);
	bool comerDama(string** tab, int fil, int col, int fil1, int col1);
	bool existeFicha(int i, string** tab, int fil, int col);
	bool existeDama(string** tab);
	bool podiaComer(string**);
	bool podiaMover(string** tab);
	bool sinPosibilidad(string **tab);
private:
	bool turno;
	int fila;
	int columna;
	int fila1;
	int columna1;
	string** tablero;
};

