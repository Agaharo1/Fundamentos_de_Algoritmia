#include <vector>
#include <iostream>
#include <string> 

using namespace std;

typedef struct {
    int numJuguetes;
    int numNinos;
    int satisMin;
    vector<int>cantidadJuguete;
    vector<string> tipos;
    vector<vector<int>> satisfacion;
} tDatos;

bool esValida(tDatos& datos, vector<int>& solParcial, int k, int juguete, vector<int>& juguetesElegidos, int nino) {
    if (juguetesElegidos[juguete] >= datos.cantidadJuguete[juguete]) {//No se pueden elegir mas juguetes de este tipo 
        return false;
    }
    if (k % 2 != 0) {

        if (juguete <= solParcial[k - 1]) {
            return false;
        }
        if (datos.tipos[juguete] == datos.tipos[solParcial[k - 1]]) {
            return false;
        }

        if ((datos.satisfacion[nino][juguete] + datos.satisfacion[nino][solParcial[k - 1]]) < datos.satisMin) {
            return false;
        }

    }

    return true;
}

void papaNoelReparte(tDatos& datos, vector<int>& solParcial, vector<int>& juguetesElegidos, int k, bool& hayAsignacion) {
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
        if (esValida(datos, solParcial, k, juguete, juguetesElegidos, k / 2)) {
            solParcial[k] = juguete;
            juguetesElegidos[juguete]++;
            papaNoelReparte(datos, solParcial, juguetesElegidos, k + 1, hayAsignacion);
            juguetesElegidos[juguete]--;
        }
    }
}

bool casoDePrueba() {
    tDatos datos;
    if (!(cin >> datos.numJuguetes >> datos.numNinos >> datos.satisMin)) {
        return false;
    }
    datos.cantidadJuguete.resize(datos.numJuguetes);
    for (int a = 0; a < datos.numJuguetes; ++a) {
        cin >> datos.cantidadJuguete[a];
    }
    datos.tipos.resize(datos.numJuguetes);
    for (int i = 0; i < datos.numJuguetes; ++i) {
        cin >> datos.tipos[i];
    }
    datos.satisfacion.resize(datos.numNinos, vector<int>(datos.numJuguetes));

    for (int i = 0; i < datos.numNinos; ++i) {
        for (int j = 0; j < datos.numJuguetes; ++j) {
            cin >> datos.satisfacion[i][j];
        }
    }
    bool hayAsignacion = false;
    vector<int> solParcial(datos.numNinos * 2);
    vector<int>juguetesElegidos(datos.numJuguetes, 0);
    papaNoelReparte(datos, solParcial, juguetesElegidos, 0, hayAsignacion);

    if (!hayAsignacion) {
        cout << "SIN SOLUCION" << endl;
    }
    cout << endl;

    return true;
}

int main() {


    while (casoDePrueba());
    return 0;
}