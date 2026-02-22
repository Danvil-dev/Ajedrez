#include <iostream>
#include "globales.h"
using namespace std;

bool disponible(char tablero[x][y], int x1, int y1) {
    if (tablero[x1][y1] == jX || tablero[x1][y1] == jY) {
        return false;
    } else {
        return true;
    }
}
void reseteo(char tablero[x][y]) {
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            tablero[i][j] = defecto;
        }
    }
}
void dibujarTablero(char tablero[x][y]) {
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
}
void elegirCasilla(char tablero[x][y], int &jugador) {
    int fila, columna;
    do {
        cout << "Casilla a elegir, primero fila y luego columna, jugador " << jugador << ":" << endl;
        cin >> fila;
        cin >> columna;
    } while (fila >= x || columna >= y || fila < 0 || columna < 0 || disponible(tablero, fila, columna) == false);
    if (jugador == 2) {
        tablero[fila][columna] = jY;
        jugador--;
    } else {
        tablero[fila][columna] = jX;
        jugador++;
    }
}
bool verificarVictoria(char tablero[x][y]) {
    int contadorX = 0, contadorO = 0;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (tablero[i][j] == jX) {
                contadorX++;
            }
            if (tablero[i][j] == jY) {
                contadorO++;
            }
        }
        if (contadorX == y || contadorO == y) {
            return true;
        }
        contadorX = 0;
        contadorO = 0;
    }
    contadorX = 0;
    contadorO = 0;
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (tablero[j][i] == jX) {
                contadorX++;
            }
            if (tablero[j][i] == jY) {
                contadorO++;
            }
        }
        if (contadorX == x || contadorO == x) {
            return true;
        }
        contadorX = 0;
        contadorO = 0;
    }
    contadorX = 0;
    contadorO = 0;
    for (int i=0; i<x; i++) {
        if (tablero[i][i] == jX) {
            contadorX++;
        }
        if (tablero[i][i] == jY) {
            contadorO++;
        }
    }
    if (contadorX == x || contadorO == x) {
        return true;
    }
    contadorX = 0;
    contadorO = 0;
    for (int i=0; i<x; i++) {
        if (tablero[i][x-1-i] == jX) {
            contadorX++;
        }
        if (tablero[i][x-1-i] == jY) {
            contadorO++;
        }
    }
    if (contadorX == x || contadorO == x) {
        return true;
    }
    return false;
}
bool empate(char tablero[x][y]) {
    if (verificarVictoria(tablero)) {
        return false;
    }
    if (verificarVictoria(tablero) != true) {
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                if (tablero[i][j] == defecto) {
                    return false;
                }
            }
        }
    }
    return true;
}