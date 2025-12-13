#include <iostream>
#include <vector>
using namespace std;

int ultimoRepetido(const vector<int>& v, int ini, int fin) {
    if (ini >= fin) {
        return -1;
    }
    if (ini + 1 == fin) {
        if (v[ini] == v[fin]) {
            return v[ini];
        }
        return -1;
    }
    int mitad = (ini + fin) / 2;
    int numValoresDer = fin - mitad;
    int diferenciaDeValores = v[fin] - v[mitad];

    if (diferenciaDeValores < numValoresDer) {
        return ultimoRepetido(v, mitad, fin);
    }
    else {
        // La derecha no tiene valores repes.
        // ANTES de ir a la izquierda, miro si la frontera es el repetido.
        if (v[mitad] == v[mitad - 1]) {
            return v[mitad];
        }
        return ultimoRepetido(v, ini, mitad - 1);
    }
}

bool resuelveCaso() {

    int n;
    cin >> n;
    if (n == 0) {
        return false;
    }
    else {
        vector<int>v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int repetido = ultimoRepetido(v, 0, n - 1);
        if (repetido == -1) {
            cout <<"NINGUNO\n";
        }
        else {
            cout <<repetido << "\n";
        }
        

        return true;
    }
}

int main()
{
    while (resuelveCaso());
}
