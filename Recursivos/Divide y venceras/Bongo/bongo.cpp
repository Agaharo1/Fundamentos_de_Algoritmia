
#include <vector>
#include <iostream>
using namespace std;



int bongo(const vector<int>& v, int ini, int fin,int buscado) {
    if (ini > fin) {
        return -1;
    }
    
    int mitad = (ini + fin) / 2;
    if (v[mitad] == buscado + mitad) {
        return v[mitad];
    }
    if (buscado+mitad < v[mitad]) {
        return bongo(v, ini, mitad-1, buscado);
    }
    else {
        return bongo(v, mitad + 1, fin, buscado);
    }
}

void casoDePrueba() {
    int num, numValores,buscado;
    cin >> num;
   
    for (int i = 0; i < num; ++i) {
        cin >> numValores>>buscado;
        vector<int>v(numValores);
        for (int j = 0; j < numValores; ++j) {
            cin >> v[j];
        }
        int bongoo = bongo(v, 0, numValores - 1, buscado);
        if (bongoo != -1) {
            cout << bongoo << "\n";
        }else{
                cout << "NO\n";
        }
        
        
    }

       

        
   
    
}

int main()
{
    casoDePrueba();
}