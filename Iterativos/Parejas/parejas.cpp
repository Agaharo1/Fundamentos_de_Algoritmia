
#include <iostream>
#include <vector>
using namespace std;

int parejas(const vector<int>& v, int n) {

    int count = 0;
    int impares = 0;
    int i = 0;
    while(i<=n) {
        if (v[i] % 2 != 0) {        
            ++impares;
        }
        else {                     
            count += impares;       
        }
        ++i;
    }

    return count;
}

void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        cout << parejas(v, n - 1) << "\n";
    }
}

int main()
{
    casoDePrueba();
}
