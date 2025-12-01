
#include <iostream>
#include <vector>
using namespace std;


int maxLong(const vector<int>& v, int n) {
    int i = 0;
    int longMax=1;
    int longAux=1;
    while (i < n) {
        if (v[i] >= v[i + 1]){
            ++longAux;
        }
        else if (v[i] < v[i + 1]) {
            longAux = 1;
        }
        if (longAux > longMax) {
            longMax = longAux;
            
        }
        ++i;
    }
    return longMax;
}
void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int n;
        cin >> n;
        if (n != 0) {
            vector<int>v(n);
            for (int j = 0; j < n; ++j) {
                cin >> v[j];
            }
            cout << maxLong(v, n - 1) << "\n";
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


