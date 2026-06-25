extern int rolAliado; //extern es usado para que otros files usen la misma variables
extern int rolEnemigo;
extern char figuraAliado;
extern char figuraEnemigo;

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


//descanso 10 mins