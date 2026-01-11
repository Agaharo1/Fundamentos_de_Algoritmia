#include <vector>
#include <iostream>
using namespace std;


int segmemtoMasLargoCons(const vector<int>& v, int n) {
    int i = 0;
    int j = 0;
    int segMax=1;

    while (j < n) {
        if (abs(v[j] - v[j + 1]) == 1) {
            ++j;
            if (j - i + 1 > segMax) {
                segMax = j - i + 1;
            }
        }
        else {
            ++j;
            i = j;
        }

    }
    return segMax;
}


void casoDePrueba() {
 
    int numCasos,n;
    cin >> numCasos;
    for (int j = 0; j < numCasos; ++j) {
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (n == 0 ) {
            cout << 0 << "\n";
        }
        else {
            cout << segmemtoMasLargoCons(v, n - 1) << "\n";
        }
    }
      
    
}

int main()
{
    casoDePrueba();
    return 0;

}
