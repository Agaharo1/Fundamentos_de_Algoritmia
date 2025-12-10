

#include <iostream>
#include <vector>
using namespace std;


bool disperso(vector<int>& v, int dispersion, int ini, int final) {
    if (ini == final) {
        return true;
    }
    int diferencia = abs(v[ini] - v[final]);
    if (diferencia < dispersion) {
        return false;
    }
    int mitad = (ini + final) / 2;
    int mitadIzq = disperso(v, dispersion, ini, mitad);
    int mitadDer = disperso(v, dispersion, mitad + 1, final);

    return mitadDer & mitadIzq;
}

bool casoDePrueba() {
    int numTiradas, dispersion;
    cin >> numTiradas >> dispersion;
    if (!cin) {
        return false;
    }
    else {
        vector<int>v(numTiradas);
        for (int i = 0; i < numTiradas; i++) {
            cin >> v[i];
        }
        if (disperso(v, dispersion, 0, numTiradas - 1)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
        return true;
    }
}
int main()
{

    while (casoDePrueba());
    return 0;
}

