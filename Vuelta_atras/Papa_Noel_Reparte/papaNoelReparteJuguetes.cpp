#include <vector>
#include <iostream>
#include <string> 

using namespace std;

typedef struct {
    int numJuguetes;
    int numNinos;
    vector<string> tipos;
} tDatos;

bool esValida(tDatos& datos, vector<int>& solParcial, int k, int juguete) {
    if (k % 2 != 0) {

        if (juguete <= solParcial[k - 1]) {
            return false;
        }
        if (datos.tipos[juguete] == datos.tipos[solParcial[k - 1]]) {
            return false;
        }
    }

    return true;
}

void papaNoelReparte(tDatos& datos, vector<int>& solParcial, int k, bool& hayAsignacion) {
    if (k == solParcial.size()) {
        hayAsignacion = true;
        for (int i = 0; i < solParcial.size(); ++i) {
            cout << solParcial[i];
            if (i < solParcial.size() - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    for (int juguete = 0; juguete < datos.numJuguetes; ++juguete) {
        if (esValida(datos, solParcial, k, juguete)) {
            solParcial[k] = juguete;
            papaNoelReparte(datos, solParcial, k + 1, hayAsignacion);
        }
    }
}

bool casoDePrueba() {
    tDatos datos;
    if (!(cin >> datos.numJuguetes >> datos.numNinos)) {
        return false;
    }

    datos.tipos.resize(datos.numJuguetes);
    for (int i = 0; i < datos.numJuguetes; ++i) {
        cin >> datos.tipos[i];
    }

    bool hayAsignacion = false;
    vector<int> solParcial(datos.numNinos * 2);

    papaNoelReparte(datos, solParcial, 0, hayAsignacion);

    if (!hayAsignacion) {
        cout << "SIN SOLUCION" << endl;
    }
    cout << endl;

    return true;
}

int main() {
    // Optimizacion de E/S habitual en jueces online, aunque no estrictamente necesaria
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    while (casoDePrueba());
    return 0;
}