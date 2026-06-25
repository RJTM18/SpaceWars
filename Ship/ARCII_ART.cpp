#include <string>
#include <iostream>
#include "ARCII_ART.h"
#include "Motor_del_juego.h"

const std::string ARTE_PRESENTACION =
"  ====================================\n"
"          G U E R R A   D E\n"
"            F I G U R A S\n"
"  ====================================\n"
"              /\\\n"
"             /__\\\n"
"        Una guerra eterna entre\n"
"        triangulos, cuadrados y\n"
"             circulos.\n\n"
"        [1] Iniciar Juego\n"
"        [2] Instrucciones\n"
"        [3] Salir\n";

const std::string ARTE_INSTRUCCIONES =
"  ====================================\n"
"            INSTRUCCIONES\n"
"  ====================================\n"
"   Mover:     W A S D\n"
"   Disparar:  ESPACIO\n"
"   Salir:     Q\n\n"
"   Eres la nave triangular   ^\n"
"   No dispares a tus aliados.\n"
"   Destruye a los enemigos del nivel.\n\n"
"   Nivel 1: aliado circulo (O), enemigo cuadrado (#)\n"
"   Nivel 2: aliado cuadrado (#), enemigo circulo (O)\n"
"   Nivel 3: todos son enemigos\n\n"
"        [ENTER] Volver al menu\n";

const std::string ARTE_GANASTE =
"  ====================================\n"
"             G A N A S T E\n"
"  ====================================\n"
"               \\o/\n"
"                |\n"
"               / \\\n"
"   La nacion triangular ha prevalecido.\n";

const std::string ARTE_PERDISTE =
"  ====================================\n"
"            P E R D I S T E\n"
"  ====================================\n"
"               X X\n"
"              BOOM!\n"
"   Tu nave triangular fue destruida.\n";

const std::string PLANETA_TRIANGULAR =
"     /\\\n"
"    /  \\\n"
"   / /\\ \\\n"
"  /_/__\\_\\\n"
" Planeta Triangular\n";

const std::string PLANETA_CUADRADO =
" +--------+\n"
" | []  [] |\n"
" |  [##]  |\n"
" | []  [] |\n"
" +--------+\n"
" Planeta Cuadrado\n";

const std::string PLANETA_CIRCULAR =
"   .----.\n"
"  / o  o \\\n"
" |   ()   |\n"
"  \\ ---- /\n"
"   '----'\n"
" Planeta Circular\n";

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