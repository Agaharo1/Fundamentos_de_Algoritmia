
#include <iostream>
#include <vector>
using namespace std;


pair<int, int> maxLong(const vector<int>& v, int n, int altura) {
    int i = 0;
    int ini = 0;
    int fin = 0;
    int indA = 0;
    int indB = 0;
    int segMax = 0;
    int segMaxAux = 0;
    while (i < n) {
        if (v[i] <= altura) {
            ++fin;
            ini = fin;
        }
        else {
            ++fin;
            segMaxAux = fin - ini;

            if (segMaxAux > segMax) {
                segMax = segMaxAux;
                indA = ini;
                indB = fin - 1;
            }
        }
        ++i;
    }

    return pair<int, int>(indA, indB);
}
void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int n, altura;
        cin >> n >> altura;
        if (n != 0) {
            vector<int>v(n);
            for (int j = 0; j < n; ++j) {
                cin >> v[j];
            }
            pair<int, int>  data = maxLong(v, n , altura);
            cout << data.first << " " << data.second << "\n";
        }
        else {
            cout << 0 << "\n";
        }

    }
}


int main()
{
    casoDePrueba();
}