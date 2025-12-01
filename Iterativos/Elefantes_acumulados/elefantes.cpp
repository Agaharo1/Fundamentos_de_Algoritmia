#include <iostream>
#include <vector>
using namespace std;

long long numNacimientos(const vector<long long>& acum, int ini, int fin) {
    return acum[fin + 1] - acum[ini];
}

bool casosDePrueba() {
    int ini, fin;

    cin >> ini >> fin;

 
    if (!cin || (ini == 0 && fin == 0)) {
        return false; 
    }


    int numAnos = fin - ini + 1;
    vector<int> v(numAnos);

    for (int i = 0; i < numAnos; ++i) {
        cin >> v[i];
    }

    vector<long long> acum(numAnos + 1, 0);
    for (int i = 1; i <= numAnos; ++i) {
        acum[i] = acum[i - 1] + v[i - 1];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int rgIni, rgFin;
        cin >> rgIni >> rgFin;

        int idxIni = rgIni - ini;
        int idxFin = rgFin - ini;

        cout << numNacimientos(acum, idxIni, idxFin) << "\n";
    }

    cout << "---\n";
    return true;
}

int main() {


    while (casosDePrueba());
    return 0;
}