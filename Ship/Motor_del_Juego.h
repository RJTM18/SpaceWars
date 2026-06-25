int rolAliado;
int rolEnemigo;
char figuraAliado;
char figuraEnemigo;

struct Entidad {
    int x, y;
    int hp;
    char figura;
    int rol;
    bool activo;
};
void limpiar();
void configurarNivel(int nivel);
void mostrarCutscene(int nivel);
int jugarNivel(int nivel, int ANCHO, int ALTO);
