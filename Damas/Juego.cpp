#include "Juego.h"

void Juego::juego()
{
	Tablero* t = new Tablero();
	MoverFichas* mov = new MoverFichas();
	Maquina* m = new modoNormal;
	int fila, columna, fila1, columna1 = 0;
	t->armarTablero();
	system("cls");
	system("color 4B");
	cout << "                                   *********************************************                                    " << endl;
	cout << "                                   *  Bienvenido al juego de damas espanolas   *                           " << endl;
	cout << "                                   *********************************************                                    " << endl << endl;
	cout << "                       #####################################################################             " << endl;
	cout << "                       #  Proyecto a cargo de Joseph Alfaro Bolaños y Carlos Sibaja Solis  #                          " << endl;
	cout << "                       #####################################################################                      " << endl << endl;
	cin.ignore();
	bool p = true;
	while (p)
	{
		try {
			string opc;
			system("cls");
			system("color 1F");
			cout << "Digite que accion desea realizar" << endl;
			cout << "1-Jugar" << endl;
			cout << "2-Cargar partida anterior" << endl;
			cout << "3-Salir" << endl;
			getline(cin, opc);
			if (opc != "1" && opc != "2" && opc != "3")
			{
				throw opc;
			}
			switch (stoi(opc))
			{
			case 1:
			{
				system("cls");
				string difi;
				cout << "Digite 1 si lo quiere en modo facil" << endl;
				cout << "Digite 2 si lo quiere en modo ofensivo" << endl;
				cout << "Digite 3 si lo quiere en modo defensivo" << endl;
				getline(cin, difi);
				if (difi == "1")
				{
					m = new modoFacil();
				}
				else if (difi == "2")
				{
					m = new modoNormal();
				}
				else if (difi == "3")
				{
					m = new modoDificil();
				}
				else
				{
					throw difi;
				}
				string ini;
				bool turno = true;
				cout << endl << "Digite 1 si quiere iniciar usted o 2 si desea que inicie la maquina" << endl;
				getline(cin, ini);
				if (ini == "1")
				{
					turno = true;
				}
				else if (ini == "2")
				{
					turno = false;
				}
				else
				{
					throw ini;
				}
				int x = 1;
				while (x == 1)
				{
					if (t->ganar() == 0)
					{
						system("cls");
						cout << "FELICIDADES HAS GANADO" << endl;
						system("pause");
						break;
					}
					else if (t->ganar() == 1) 
					{
						system("cls");
						cout << "HAS PERDIDO, INTENTALO DE NUEVO\t" << endl;
						system("pause");
						break;
					}
					if (turno == true)
					{
						m->coronar(t->getTab());
						mov->coronar(t->getTab());
						string ele;
						try
						{
							system("cls");
							cout << t->toString();
							cout << "Digite que accion desea realizar" << endl;
							cout << "1-Mover ficha" << endl;
							cout << "2-Comer" << endl;
							cout << "3-Cambiar dificultad" << endl;
							cout << "4-Salir" << endl;
							getline(cin, ele);
							if (ele != "1" && ele != "2" && ele != "3" && ele != "4")
							{
								throw ele;
							}
							switch (stoi(ele))
							{
							case 1:
							{
								system("cls");
								if (mov->podiaComer(t->getTab()) == true)
								{
									cout << "No puedes mover ya que puedes comer" << endl;
									system("pause");
								}
								else
								{
									string mover = "2";
									if (mov->existeDama(t->getTab()) == true)
									{
										cout << "1-Mover con la dama" << endl;
										cout << "2-Mover ficha" << endl;
										getline(cin, mover);
										system("cls");
									}
									if (mover == "1")
									{
										bool z = false;
										while (!z)
										{
											system("cls");
											cout << t->toString();
											z = true;
											cout << "Digite la fila de la dama que desea mover: ";
											cin >> fila;
											cout << "Digite la columna de la dama que desea mover: ";
											cin >> columna;
											cout << "Digite la fila donde desea mover la dama: ";
											cin >> fila1;
											cout << "Digite la columna donde desea mover la dama: ";
											cin >> columna1;
											if (mov->moverDama(t->getTab(), fila, columna, fila1, columna1) == false)
											{
												cout << "Movimiento incorrecto, intento nuevamente" << endl;
												z = false;
											}
											else
											{
												t->registroMovi(0, fila, columna, fila1, columna1);
											}
											system("pause");
										}
									}
									else if (mover == "2")
									{
										bool z = false;
										while (!z)
										{
											system("cls");
											cout << t->toString();
											z = true;
											cout << "Digite la fila de la ficha que desea mover: ";
											cin >> fila;
											cout << "Digite la columna de la ficha que desea mover: ";
											cin >> columna;
											cout << "Digite la fila donde desea mover la ficha: ";
											cin >> fila1;
											cout << "Digite la columna donde desea mover la ficha: ";
											cin >> columna1;
											if (mov->mover(t->getTab(), fila, columna, fila1, columna1) == false)
											{
												cout << "Movimiento incorrecto, intento nuevamente" << endl;
												z = false;
											}
											else
											{
												t->registroMovi(0, fila, columna, fila1, columna1);
											}
											system("pause");
										}
									}
									else
									{
										throw mover;
									}
								}
								turno = false;
								cin.ignore();
								break;
							}
							case 2:
							{
								string com = "2";
								system("cls");
								if (mov->existeDama(t->getTab()) == true)
								{
									cout << "1-Comer con dama" << endl;
									cout << "2-Comer con ficha" << endl;
									getline(cin, com);
									system("cls");
								}
								if (com == "1")
								{
									int comer, ele = 0, ele2 = 0;
									bool z = false;
									while (!z)
									{
										system("cls");
										cout << t->toString();
										cout << "Digite cuantas fichas va a comer" << endl;
										cin >> comer;
										cout << "Digite la fila de la dama a mover" << endl;
										cin >> fila;
										cout << "Digite la columna de la dama a mover" << endl;
										cin >> columna;
										if (!(mov->existeFicha(0, t->getTab(), fila, columna)))
										{
											cout << "No existe la dama, intentelo nuevamente" << endl;
											system("pause");
										}
										else
										{
											for (int i = 0; i < comer; i++)
											{
												system("cls");
												cout << t->toString();
												cout << "A continuacion digite la fila de la ficha que desea comer: " << endl;
												cin >> ele;
												cout << "A continuacion digite la columna de la ficha que desea comer: " << endl;
												cin >> ele2;
												cout << "Digite la fila donde desea mover la dama" << endl;
												cin >> fila1;
												cout << "Digite la columna donde desea mover la dama" << endl;
												cin >> columna1;
												if (mov->comerDama(t->getTab(), fila, columna, fila1, columna1) == false)
												{
													cout << "Movimiento incorrecto, intento nuevamente" << endl;
													i = i - 1;
													system("pause");
												}
												else
												{
													mov->forzarEliminacion(t->getTab(), ele, ele2);
													t->registroMovi(1, fila, columna, fila1, columna1);
												}
											}
											z = true;
										}
									}
								}
								else if (com == "2")
								{
									int comer, ele = 0, ele2 = 0;
									bool z = false;
									while (!z)
									{
										system("cls");
										cout << t->toString();
										cout << "Digite cuantas fichas va a comer" << endl;
										cin >> comer;
										cout << "Digite la fila de la ficha a mover" << endl;
										cin >> fila;
										cout << "Digite la columna de la ficha a mover" << endl;
										cin >> columna;
										if (!(mov->existeFicha(0, t->getTab(), fila, columna)))
										{
											cout << "No existe la ficha, intentelo nuevamente" << endl;
											system("pause");
										}
										else
										{
											for (int i = 0; i < comer; i++)
											{
												system("cls");
												cout << t->toString();
												cout << "A continuacion digite la fila de la ficha que desea comer: " << endl;
												cin >> ele;
												cout << "A continuacion digite la columna de la ficha que desea comer: " << endl;
												cin >> ele2;
												cout << "Digite la fila donde desea mover la ficha" << endl;
												cin >> fila1;
												cout << "Digite la columna donde desea mover la ficha" << endl;
												cin >> columna1;
												if (mov->comer(t->getTab(), fila, columna, fila1, columna1) == false)
												{
													cout << "Movimiento incorrecto, intento nuevamente" << endl;
													i = i - 1;
													system("pause");
												}
												else
												{
													mov->forzarEliminacion(t->getTab(), ele, ele2);
													t->registroMovi(1, fila, columna, fila1, columna1);
												}
											}
											z = true;
										}
									}
								}
								else
								{
									throw com;
								}
								turno = false;
								cin.ignore();
								break;
							}
							case 3:
							{
								difi = "";
								system("cls");
								cout << "Digite 1 si lo quiere en modo facil" << endl;
								cout << "Digite 2 si lo quiere en modo ofensivo" << endl;
								cout << "Digite 3 si lo quiere en modo defensivo" << endl;
								getline(cin, difi);
								if (difi == "1")
								{
									m = new modoFacil();
								}
								else if (difi == "2")
								{
									m = new modoNormal();
								}
								else if (difi == "3")
								{
									m = new modoDificil();
								}
								else
								{
									throw difi;
								}
								break;
							}
							case 4:
							{
								int y = 0;
								string name = "";
								system("cls");
								cout << "Seguro que va salir de la partida" << endl;
								cout << "1-Si     2-No :" << endl;
								cin >> x;
								if (x == 1)
								{
									cout << "¿Desea guardar la partida?" << endl;
									cout << "1-Si  2-No" << endl;
									cin >> y;
									if (y == 1) {
										cout << "Digite el nombre de la partida" << endl;
										cin >> name;
										t->archivo(name);
										cin.ignore();
									}
									else if (y == 2) {
										cout << "Saliendo del juego..." << endl;
										cin.ignore();
									}
									else
									{
										cin.ignore();
										throw ele;
									}
									t = new Tablero();
									t->armarTablero();
									x = 0;
								}
								else if (x == 2)
								{
									cin.ignore();
									x = 1;
								}
								else
								{
									cin.ignore();
									throw ele;
								}
								break;
							}

							}
						}
						catch (string ele)
						{
							cout << "Se ha generado un error, por favor intentelo de nuevo" << endl;
							system("pause");
						}

					}
					else
					{
						system("cls");
						m->coronar(t->getTab());
						mov->coronar(t->getTab());
						cout << t->toString();
						bool l;
						if (m->existeDama(t->getTab()) == true)
						{
							int p = rand() % 2;
							if (p == 0)
							{
								l = m->comerNormal(t->getTab());
								if (l == false)
								{
									l = m->comerDama(t->getTab());
								}
							}
							else
							{
								l = m->comerDama(t->getTab());
								if (l == false)
								{
									l = m->comerNormal(t->getTab());
								}
							}
						}
						else
						{
							l = m->comerNormal(t->getTab());
						}
						if (l == false)
						{
							bool s;
							if (m->existeDama(t->getTab()) == true)
							{
								int ñ = rand() % 2;
								if (ñ == 0)
								{
									s = m->mover(t->getTab());
									if (s == false)
									{
										s = m->moverDama(t->getTab());
									}
								}
								else
								{
									s = m->moverDama(t->getTab());
									if (s == false)
									{
										s = m->mover(t->getTab());
									}
								}
							}
							else
							{
								s = m->mover(t->getTab());
							}


							if (s == false)
							{
								cout << "No hay movimientos posibles" << endl;
							}
							else
							{
								cout << "Maquina jugando..." << endl;
							}
						}
						else
						{
							cout << "Maquina jugando..." << endl;
						}
						system("pause");
						turno = true;
					}
				}
				t = new Tablero();
				t->armarTablero();
				m = new modoNormal();
				break;
			}
			case 2:
			{
				string n;
				cout << "Digite el nombre de la partida que desea cargar: " << endl;
				getline(cin, n);
				if (t->cargar(n) == true)
				{
					t->igualar();
					cout << "Se ha cargado correctamente la partida, a continuacion seleccione la opcion jugar para reanudar la partida" << endl;
				}
				else
				{
					cout << "No existe dicha partida guardada o el nombre de la partida esta mal escrito" << endl;
				}
				system("pause");
				break;
			}
			case 3:
			{
				string ele;
				system("cls");
				cout << "Seguro que va salir del juego" << endl;
				cout << "1-Si     2-No :" << endl;
				cin >> ele;
				if (ele == "1")
				{
					cout << "Saliendo..." << endl;
					system("pause");
					exit(0);
				}
				else if (ele == "2")
				{
					p = true;
					cin.ignore();
				}
				else
				{
					cin.ignore();
					throw ele;
				}
			}
			break;
			}
		}
		catch (string opc)
		{
			cout << "Se ha generado un error, por favor intentelo de nuevo" << endl;
			system("pause");
		}
	}
	cin.get();
}
