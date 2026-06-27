#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "ARCII_ART.h"
#include "Motor_del_Juego.h"


const int ANCHO = 40;
const int ALTO = 40;

int main() {
    SetConsoleOutputCP(437);
    srand((unsigned)time(0));

    Roles_figuras faccion;
    faccion.aliado = ' ';
    faccion.enemigo = ' ';

    bool salir = false;
    while (!salir) {
        limpiar();
        imprimirArtePresentacion();
        std::cout << "\n Selecciona una opcion: ";
        char op = _getch();

        if (op == '1') {
            limpiar();
            std::cout << " ZONA DE CONFLICTO\n\n";
            imprimirPlanetaTriangular();
            imprimirPlanetaCuadrado();
            imprimirPlanetaCircular();
            std::cout << " [ENTER] Continuar\n";
            std::cin.get();

            bool gano = true;
            for (int nivel = 1; nivel <= 3; nivel++) {
                mostrarCutscene(nivel);

                configurarNivel(nivel, faccion); //funcion que retorna un struct

                int r = jugarNivel(nivel, ANCHO, ALTO, faccion);
                if (r == -1) {
                    gano = false;
                    break;
                }
                if (r == 0) {
                    gano = false;
                    limpiar();
                    imprimirArtePerdiste();
                    std::cout << "\n [ENTER] Volver al menu\n";
                    std::cin.get();
                    break;
                }
            }
            if (gano) {
                limpiar();
                imprimirArteGanaste();
                std::cout << "\n [ENTER] Volver al menu\n";
                std::cin.get();
            }
        }
        else if (op == '2') { //intrucciones
            limpiar();
            imprimirArteInstrucciones();
            std::cin.get(); //espera un ENTER como imput
        }
        else if (op == '3') { //creditos
            limpiar();
            imprimirCreditos();
            std::cout << "\n [ENTER] Volver al menu\n";
            std::cin.get();
        }
        else if (op == '4') salir = true; //salir dell juego
    }

    limpiar();
    std::cout << " Gracias por jugar Guerra de Figuras.\n";
    return 0;
}