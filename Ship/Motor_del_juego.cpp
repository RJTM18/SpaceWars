#include <windows.h>
#include "Motor_del_Juego.h"
#include <iostream>
#include <vector>
#include <conio.h>

void limpiar() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD inicio = { 0, 0 };
    DWORD escritos;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);
    DWORD total = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(h, ' ', total, inicio, &escritos);
    SetConsoleCursorPosition(h, inicio);
}

struct Roles_figuras configurarNivel(int nivel, Roles_figuras &faccion) { //funcion que retorna un struct //creating copy of the struct
    if (nivel == 1) {
        faccion.aliado = 'O'; 
        faccion.enemigo = '#';
    }
    else if (nivel == 2) {
        faccion.aliado = '#';
        faccion.enemigo = 'O';
    }
    else {
        faccion.aliado = ' ';
        faccion.enemigo = '#';
    }
    return faccion;
}

int jugarNivel(int nivel, 
    int ANCHO, 
    int ALTO,
    Roles_figuras &faccion) {
    
    int rolAliado = 1;
    int rolEnemigo = 2;

    Entidad jugador;
    jugador.x = ANCHO / 2;
    jugador.y = ALTO - 2;
    jugador.hp = 10;
    jugador.figura = '^';
    jugador.rol = 0;
    jugador.activo = true;

    std::vector<Entidad> enemigos;
    std::vector<Entidad> aliados;
    std::vector<Entidad> balas;

    int bajasNecesarias = 5;
    int bajas = 0;
    int contadorSpawn = 0;
    bool tieneAliados = (nivel != 3);

    while (jugador.hp > 0 && bajas < bajasNecesarias) {

        if (_kbhit()) {
            char t = _getch();
            if ((t == 'a' or t == '4') && jugador.x > 1) jugador.x--;
            if ((t == 'd' or t == '6') && jugador.x < ANCHO - 2) jugador.x++;
            if ((t == 'w' or t == '8') && jugador.y > 1) jugador.y--;
            if ((t == 's' or t == '5') && jugador.y < ALTO - 2) jugador.y++;
            if (t == ' ') { //space
                Entidad b;
                b.x = jugador.x;
                b.y = jugador.y - 1;
                b.hp = 0;
                b.figura = '|';
                b.rol = 0;
                b.activo = true;
                balas.push_back(b);
            }
            if (t == 'q') return -1;
        }

        contadorSpawn++;
        if (contadorSpawn >= 8) {
            contadorSpawn = 0;
            Entidad e;
            e.x = 1 + rand() % (ANCHO - 2);
            e.y = 1;
            e.hp = 1;
            e.figura = faccion.enemigo; //figuraEnemigo que valor tiene?
            e.rol = rolEnemigo;
            e.activo = true;
            enemigos.push_back(e);

            if (tieneAliados && rand() % 2 == 0) {
                Entidad a;
                a.x = 1 + rand() % (ANCHO - 2);
                a.y = 1;
                a.hp = 1;
                a.figura = faccion.aliado;
                a.rol = rolAliado;
                a.activo = true;
                aliados.push_back(a);
            }
        }

        for (size_t i = 0; i < enemigos.size(); i++) { 
            enemigos[i].y++;
            if (enemigos[i].x == jugador.x && enemigos[i].y == jugador.y) {
                jugador.hp -= 2;
                enemigos[i].activo = false;
            }
            if (enemigos[i].y >= ALTO - 1) enemigos[i].activo = false;
        }
        for (size_t i = 0; i < aliados.size(); i++) {
            aliados[i].y++;
            if (aliados[i].y >= ALTO - 1) aliados[i].activo = false;
        }

        for (size_t i = 0; i < balas.size(); i++) {
            balas[i].y--;
            if (balas[i].y < 1) {
                balas[i].activo = false;
                continue;
            }
            for (size_t j = 0; j < enemigos.size(); j++) {
                if (enemigos[j].activo && balas[i].activo &&
                    balas[i].x == enemigos[j].x && balas[i].y == enemigos[j].y) {
                    enemigos[j].activo = false;
                    balas[i].activo = false;
                    bajas++;
                }
            }
            for (size_t j = 0; j < aliados.size(); j++) {
                if (aliados[j].activo && balas[i].activo &&
                    balas[i].x == aliados[j].x && balas[i].y == aliados[j].y) {
                    balas[i].activo = false;
                    jugador.hp -= 1;
                }
            }
        }

        std::vector<Entidad> tmpE, tmpA, tmpB;
        for (size_t i = 0; i < enemigos.size(); i++) if (enemigos[i].activo) tmpE.push_back(enemigos[i]);
        for (size_t i = 0; i < aliados.size(); i++) if (aliados[i].activo) tmpA.push_back(aliados[i]);
        for (size_t i = 0; i < balas.size(); i++) if (balas[i].activo) tmpB.push_back(balas[i]);
        enemigos = tmpE;
        aliados = tmpA;
        balas = tmpB;

        std::vector<std::string> pantalla(ALTO, std::string(ANCHO, ' '));
        for (int x = 0; x < ANCHO; x++) {
            pantalla[0][x] = '=';
            pantalla[ALTO - 1][x] = '=';
        }
        for (int y = 0; y < ALTO; y++) {
            pantalla[y][0] = '|';
            pantalla[y][ANCHO - 1] = '|';
        }

        for (size_t i = 0; i < enemigos.size(); i++) pantalla[enemigos[i].y][enemigos[i].x] = enemigos[i].figura;
        for (size_t i = 0; i < aliados.size(); i++) pantalla[aliados[i].y][aliados[i].x] = aliados[i].figura;
        for (size_t i = 0; i < balas.size(); i++) pantalla[balas[i].y][balas[i].x] = '|';
        pantalla[jugador.y][jugador.x] = jugador.figura;

        limpiar();
        std::cout << " HP: " << jugador.hp << "   NIVEL: " << nivel
            << "   BAJAS: " << bajas << "/" << bajasNecesarias << "\n";
        if (nivel == 3)
            std::cout << " OBJETIVO: destruye a todos. No hay aliados.\n";
        else
            std::cout << " OBJETIVO: destruye los enemigos (" << faccion.enemigo
            << "). NO dispares a los aliados (" << faccion.aliado << ").\n";
        for (int y = 0; y < ALTO; y++) std::cout << pantalla[y] << "\n";

        Sleep(80);
    }

    if (jugador.hp <= 0) return 0;
    return 1;
}