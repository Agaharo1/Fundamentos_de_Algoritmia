#include <vector>
#include <iostream>
using namespace std;

int escalonMasLargo(const vector<int>& v, int ini, int fin, int& longIzq, int& longDer) {
    if (ini == fin) {
        longIzq = 1;
        longDer = 1;
        return 1;
    }

    int mitad = (ini + fin) / 2;

    int izq_longIzq, izq_longDer; 
    int der_longIzq, der_longDer; 

    int maxIzq = escalonMasLargo(v, ini, mitad, izq_longIzq, izq_longDer);
    int maxDer = escalonMasLargo(v, mitad + 1, fin, der_longIzq, der_longDer);

    int maxGlobal = max(maxIzq, maxDer);

    longIzq = izq_longIzq;
    longDer = der_longDer;

    if (v[mitad] == v[mitad + 1]) {
        int longitudCruce = izq_longDer + der_longIzq;
        if (longitudCruce > maxGlobal) {
            maxGlobal = longitudCruce;
        }

        if (izq_longIzq == (mitad - ini + 1)) {
            longIzq = izq_longIzq + der_longIzq;
        }

        if (der_longDer == (fin - mitad)) {
            longDer = der_longDer + izq_longDer;
        }
    }

    return maxGlobal;
}

bool casoDePrueba() {
    int num;
    cin >> num;
    if (num != 0) {
        vector<int>v(num);
        for (int i = 0; i < num; ++i) {
            cin >> v[i];
        }
      
        int longIzq = 0;
        int longDer = 0;
        cout << escalonMasLargo(v, 0, num - 1,  longIzq, longDer)<<"\n";

        return true;
    }
    else {
        return false;
    }
}

int main()
{
    while (casoDePrueba());
}
