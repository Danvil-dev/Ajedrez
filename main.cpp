#include <iostream>
using namespace std;
#include "globales.h"
#include "dosJugadores.h"
#include "unJugador.h"
#include <random>
int main() {
    char tablero[x][y];
    int jugador = 1;
    int continuar = 0;
    reseteo(tablero);
    while (continuar != -1) {
        reseteo(tablero);

        cout << "===========================" << endl;
        cout << "Modo de juego: " << endl;
        cout << "1. Dos jugadores" << endl;
        cout << "2. Un jugador vs PC" << endl;
        cout << "===========================" << endl;
        cin >> continuar;
        switch (continuar) {
             default:
                continuar = -1;
                break;
            case 1:
                reseteo(tablero);
                while (verificarVictoria(tablero)==false && empate(tablero) == false) {
                    elegirCasilla(tablero, jugador);
                    dibujarTablero(tablero);
                }
                if (empate(tablero) == true) {
                    cout << "Hubo empate!";
                }
                break;
            case 2:
                reseteo(tablero);
                while (true) {
                    elegirCasillaJugador(tablero);
                    dibujarTablero(tablero);

                    if (verificarVictoria(tablero)) {
                        cout << "Ganaste!!" << endl;
                        break; // Rompe el bucle while y vuelve al menú
                    }
                    if (empate(tablero)) {
                        cout << "Empate!" << endl;
                        break;
                    }

                    cout << "Movimiento PC..." << endl;
                    elegirCasillaPC(tablero);
                    dibujarTablero(tablero);

                    if (verificarVictoria(tablero)) {
                        cout << "La PC ha ganado" << endl;
                        break;
                    }
                    if (empate(tablero)) {
                        cout << "Empate!" << endl;
                        break;
                    }
                }
                break;
        }
    }
}