#include <string>
#include <iostream>
#include "ARCII_ART.h"
#include "Motor_del_juego.h"

#include <iostream>

inline void imprimirArtePresentacion() {
    std::cout << "  ====================================\n";
    std::cout << "          G U E R R A   D E\n";
    std::cout << "            F I G U R A S\n";
    std::cout << "  ====================================\n";
    std::cout << "              /\\\n";
    std::cout << "             /__\\\n";
    std::cout << "        Una guerra eterna entre\n";
    std::cout << "        triangulos, cuadrados y\n";
    std::cout << "             circulos.\n\n";
    std::cout << "        [1] Iniciar Juego\n";
    std::cout << "        [2] Instrucciones\n";
    std::cout << "        [3] Salir\n";
}

inline void imprimirArteInstrucciones() {
    std::cout << "  ====================================\n";
    std::cout << "            INSTRUCCIONES\n";
    std::cout << "  ====================================\n";
    std::cout << "   Mover:     W A S D\n";
    std::cout << "   Disparar:  ESPACIO\n";
    std::cout << "   Salir:     Q\n\n";
    std::cout << "   Eres la nave triangular   ^\n";
    std::cout << "   No dispares a tus aliados.\n";
    std::cout << "   Destruye a los enemigos del nivel.\n\n";
    std::cout << "   Nivel 1: aliado circulo (O), enemigo cuadrado (#)\n";
    std::cout << "   Nivel 2: aliado cuadrado (#), enemigo circulo (O)\n";
    std::cout << "   Nivel 3: todos son enemigos\n\n";
    std::cout << "        [ENTER] Volver al menu\n";
}

inline void imprimirArteGanaste() {
    std::cout << "  ====================================\n";
    std::cout << "             G A N A S T E\n";
    std::cout << "  ====================================\n";
    std::cout << "               \\o/\n";
    std::cout << "                |\n";
    std::cout << "               / \\\n";
    std::cout << "   La nacion triangular ha prevalecido.\n";
}

inline void imprimirArtePerdiste() {
    std::cout << "  ====================================\n";
    std::cout << "            P E R D I S T E\n";
    std::cout << "  ====================================\n";
    std::cout << "               X X\n";
    std::cout << "              BOOM!\n";
    std::cout << "   Tu nave triangular fue destruida.\n";
}

inline void imprimirPlanetaTriangular() {
    std::cout << "     /\\\n";
    std::cout << "    /  \\\n";
    std::cout << "   / /\\ \\\n";
    std::cout << "  /_/__\\_\\\n";
    std::cout << " Planeta Triangular\n";
}

inline void imprimirPlanetaCuadrado() {
    std::cout << " +--------+\n";
    std::cout << " | []  [] |\n";
    std::cout << " |  [##]  |\n";
    std::cout << " | []  [] |\n";
    std::cout << " +--------+\n";
    std::cout << " Planeta Cuadrado\n";
}

inline void imprimirPlanetaCircular() {
    std::cout << "   .----.\n";
    std::cout << "  / o  o \\\n";
    std::cout << " |   ()   |\n";
    std::cout << "  \\ ---- /\n";
    std::cout << "   '----'\n";
    std::cout << " Planeta Circular\n";
}

void mostrarCutscene(int nivel) {
    limpiar();
    std::cout << "  ====================================\n";
    if (nivel == 1) {
        std::cout << "              NIVEL 1\n";
        std::cout << "  ====================================\n";
        std::cout << "  Los triangulos y circulos se alian\n";
        std::cout << "  contra el imperio cuadrado.\n\n";
        std::cout << "  Aliado:  circulo  (O)\n";
        std::cout << "  Enemigo: cuadrado (#)\n";
    }
    else if (nivel == 2) {
        std::cout << "              NIVEL 2\n";
        std::cout << "  ====================================\n";
        std::cout << "  Los circulos te traicionan.\n";
        std::cout << "  Ahora te alias con los cuadrados.\n\n";
        std::cout << "  Aliado:  cuadrado (#)\n";
        std::cout << "  Enemigo: circulo  (O)\n";
    }
    else {
        std::cout << "              NIVEL 3\n";
        std::cout << "  ====================================\n";
        std::cout << "  Todos te han traicionado.\n";
        std::cout << "  Estas solo contra el mundo.\n\n";
        std::cout << "  No hay aliados.\n";
        std::cout << "  Enemigos: todas las figuras (#)\n";
    }
    std::cout << "\n  [ENTER] Comenzar batalla\n";
    std::cin.get();
}