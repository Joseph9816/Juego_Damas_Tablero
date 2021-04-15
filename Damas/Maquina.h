#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Maquina
{
public:
	Maquina();
	virtual ~Maquina();
	string* getFicha();
	void setFicha(string* val);
	int sisComer(string** tab);
	bool comerNormal(string** tab);
	bool comerUna(string** tab);
	bool comerDos(string** tab);
	virtual bool mover(string** tab) = 0;
	virtual bool moverDama(string** tab) = 0;
	void coronar(string** tab);
	bool existeDama(string** tab);
	bool podiaMover(string** tab);
	bool sinPosibilidad(string** tab);
	bool comerDama(string** tab);
private:
	string *ficha;
	int cantidad;
};

