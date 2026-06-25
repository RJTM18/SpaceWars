#pragma once

// Listado de funciones para mostrar el arte del juego
void imprimirArtePresentacion();
void imprimirArteInstrucciones();
void imprimirArteGanaste();
void imprimirArtePerdiste();

// Listado de funciones para mostrar los planetas
void imprimirPlanetaTriangular();
void imprimirPlanetaCuadrado();
void imprimirPlanetaCircular();

// esta funcion depende del nivel
void mostrarCutscene(int nivel);