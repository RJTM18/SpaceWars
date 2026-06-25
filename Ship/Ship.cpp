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

    bool salir = false;
    while (!salir) {
        limpiar();
        imprimirArtePresentacion();
        std::cout << "\n Selecciona una opcion: ";
        char op = _getch();

        if (op == '1') {
            limpiar();
            std::cout << " ZONA DE CONFLICTO\n\n";
            void imprimirPlanetaTriangular();
            void imprimirPlanetaCuadrado();
            void imprimirPlanetaCircular();
            std::cout << " [ENTER] Continuar\n";
            std::cin.get();

            bool gano = true;
            for (int nivel = 1; nivel <= 3; nivel++) {
                mostrarCutscene(nivel);
                int r = jugarNivel(nivel, ANCHO, ALTO);
                if (r == -1) {
                    gano = false;
                    break;
                }
                if (r == 0) {
                    gano = false;
                    limpiar();
                    void imprimirArtePerdiste();
                    std::cout << "\n [ENTER] Volver al menu\n";
                    std::cin.get();
                    break;
                }
            }
            if (gano) {
                limpiar();
                void imprimirArteGanaste();
                std::cout << "\n [ENTER] Volver al menu\n";
                std::cin.get();
            }
        }
        else if (op == '2') {
            limpiar();
            void imprimirArteInstrucciones();
            std::cin.get();
        }
        else if (op == '3') {
            salir = true;
        }
    }

    limpiar();
    std::cout << " Gracias por jugar Guerra de Figuras.\n";
    return 0;
}