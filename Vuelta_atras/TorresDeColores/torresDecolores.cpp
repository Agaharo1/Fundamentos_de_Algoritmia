#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constantes para los colores (0, 1, 2)
const int AZUL = 0;
const int ROJO = 1;
const int VERDE = 2;


typedef struct {
    int altura;
    vector<int> colores; 
} tDatos;

string nombreColor(int c) {
    if (c == AZUL) return "azul";
    if (c == ROJO) return "rojo";
    if (c == VERDE) return "verde";
    return "";
}

bool esValida(const tDatos& datos, const vector<int>& solParcial, const vector<int>& usados, int k, int color) {
    if (usados[color] + 1 > datos.colores[color]) return false;

    if (k == 0 && color != ROJO) return false;

    if (color == VERDE && k > 0 && solParcial[k - 1] == VERDE) return false;

    int verdesNext = (color == VERDE) ? usados[VERDE] + 1 : usados[VERDE];
    int azulesNext = (color == AZUL) ? usados[AZUL] + 1 : usados[AZUL];

    if (verdesNext > azulesNext) return false;

    return true;
}


void marcar(vector<int>& usados, int color) {
    usados[color]++;
}

void desmarcar(vector<int>& usados, int color) {
    usados[color]--;
}


void torresdeColores(tDatos& datos, vector<int>& solParcial, vector<int>& usados, int k, bool& found) {

  
    if (k == datos.altura) {
        if (usados[ROJO] > (usados[AZUL] + usados[VERDE])) {
            for (int i = 0; i < datos.altura; ++i) {
                cout << nombreColor(solParcial[i]) << (i < datos.altura - 1 ? " " : "");
            }
            cout << endl;
            found = true;
        }
        return;
    }

    
    for (int color = 0; color < 3; ++color) {
       
        if (esValida(datos, solParcial, usados, k, color)) {
            solParcial[k] = color;       
            marcar(usados, color);       
            torresdeColores(datos, solParcial, usados, k + 1, found);
            desmarcar(usados, color); 
        }
    }
}

bool casoDePrueba() {
    tDatos datos;
    datos.colores = vector<int>(3);

    cin >> datos.altura >> datos.colores[0] >> datos.colores[1] >> datos.colores[2];

    if ((datos.altura == 0) && (datos.colores[0] == 0) && (datos.colores[1] == 0) && (datos.colores[2] == 0)) {
        return false;
    }
    else {
        vector<int> torre(datos.altura);
        vector<int> usados(3, 0);  
        bool found = false;

        torresdeColores(datos, torre, usados, 0, found);

        if (!found) {
            cout << "SIN SOLUCION" << endl;
        }
        cout << endl;
        return true;
    }
}

int main()
{
    while (casoDePrueba());
    return 0;
}