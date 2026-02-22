#ifndef TRESENRAYA_DOSJUGADORES_H
#define TRESENRAYA_DOSJUGADORES_H
#include <iostream>
#include "globales.h"
bool disponible(char tablero[x][y], int x1, int y1);
void reseteo(char tablero[x][y]);
void dibujarTablero(char tablero[x][y]);
int elegirCasilla(char tablero[x][y], int &jugador);
bool verificarVictoria(char tablero[x][y]);
bool empate(char tablero[x][y]);
#endif //TRESENRAYA_DOSJUGADORES_H