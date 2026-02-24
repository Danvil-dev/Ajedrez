#include "unJugador.h"
#include "dosJugadores.h"
#include "globales.h"
#include <iostream>
#include <random>
using namespace std;
void elegirCasillaJugador(char tablero[x][y]) {
    int fila, columna;
    do {
        cout << "Casilla a elegir, primero fila y luego columna:" << endl;
        cin >> fila;
        cin >> columna;
    } while (fila >= x || columna >= y || fila < 0 || columna < 0 || disponible(tablero, fila, columna) == false);
    tablero[fila][columna] = jX;
}
void elegirCasillaPC(char tablero[x][y], bool &primera) {
    bool ganadora = false;
if (ganadora == false) {
    for (int i=0; i<x; i++) {
        for (int j=0; j<y && ganadora==false; j++) {
            if (disponible(tablero, i, j)==true) {
                tablero[i][j] = jY;
                if (verificarVictoria(tablero)==true) {
                    ganadora = true;
                } else {
                    tablero[i][j] = defecto;
                }
            }
        }
    }
}

    char temp;
    if (ganadora == false) {
        for (int i=0; i<x && ganadora == false; i++) {
            for (int j=0; j<y && ganadora == false; j++) {
                if (disponible(tablero,i,j) == true) {
                    temp = tablero[i][j];
                    tablero[i][j] = jX;
                    if (verificarVictoria(tablero) == true) {
                        tablero[i][j] = jY;
                        ganadora = true;

                    } else {
                        tablero[i][j] = temp;

                    }
                }
            }
        }
    }
    //UPDATES
    if (disponible(tablero,0,0) == false && disponible(tablero,1,1) == false && disponible(tablero,2,2) == false && disponible(tablero,0,1) == true && ganadora == false) {
        tablero[0][1] = jY;
        ganadora = true;
    }
    if (disponible(tablero,0,2) == false && disponible(tablero,1,1) == false && disponible(tablero,2,0) == false && disponible(tablero, 2,1) == true && ganadora == false) {
        tablero[2][1] = jY;
        ganadora = true;
    }
    if (disponible(tablero,1,1) == true && ganadora == false) {
        tablero[1][1] = jY;
        ganadora = true;
    } else {
        if (primera == false && disponible(tablero,0,0) && ganadora == false) {
            tablero[0][0] = jY;
            ganadora = true;
            primera = true;
        }
    if (disponible(tablero,1,1) == false && disponible(tablero,1,2) == false && disponible(tablero,2,1) == false && ganadora == false && disponible(tablero,2,2) == true) {
        tablero[2][2] = jY;
        ganadora =true;
    }
        if (disponible(tablero,1,1) == false && disponible(tablero,0,1) == false && disponible(tablero,1,0) == false && ganadora == false && disponible(tablero,0,0) == true) {
            tablero[0][0] = jY;
            ganadora =true;
        }
        if (disponible(tablero,1,1) == false && disponible(tablero,0,1) == false && disponible(tablero,1,2) == false && ganadora == false && disponible(tablero,0,2) == true) {
            tablero[0][2] = jY;
            ganadora =true;
        }
        if (disponible(tablero,1,1) == false && disponible(tablero,1,0) == false && disponible(tablero,2,1) == false && ganadora == false && disponible(tablero,2,0) == true) {
            tablero[2][0] = jY;
            ganadora =true;
        }
    }
    //FIN UPDATES
    if (ganadora == false) {
        bool puesto = false;
        //FIXME pregunar como funciona!!!
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<int> distFila(0, x-1);
        std::uniform_int_distribution<int> distCol(0, y-1);
        while (puesto == false) {
            int pcx = distFila(rng);
            int pcy = distCol(rng);
            if (disponible(tablero, pcx, pcy)) {
                tablero[pcx][pcy] = jY;
                puesto = true;
            }
        }
    }
    if (primera == false) primera = true;
}