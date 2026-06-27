
struct Entidad {
    int x, y;
    int hp;
    char figura;
    int rol;
    bool activo;
};

struct Roles_figuras {
    char aliado;
    char enemigo;
};

void limpiar();
void mostrarCutscene(int nivel);
struct Roles_figuras configurarNivel(int nivel, Roles_figuras &faccion);
int jugarNivel(int nivel, int ANCHO, int ALTO, Roles_figuras &faccion);


//descanso 10 mins