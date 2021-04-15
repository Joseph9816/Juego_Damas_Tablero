#pragma once
#include "Maquina.h"
#include <stdlib.h>

class modoFacil : public Maquina
{
	bool mover(string** tab);
	bool moverDama(string** tab);
	bool movimientoRecomendado(string** tab);

};

