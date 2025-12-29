#include <vector>
#include <iostream>
using namespace std;


int elementoPerdido(const vector<int>& v, const vector<int>& c, int ini, int fin) {
    if (ini == fin) {
        return v[ini];;
    }

    int mitad = (ini + fin) / 2;
  

    if (v[mitad] == c[mitad]) {//buscar a la der
        return elementoPerdido(v, c, mitad + 1, fin);
    }
    else {
        return elementoPerdido(v, c,ini, mitad);
    }
}


void casoDePrueba() {
    int num, numValores;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        cin >> numValores ;
        vector<int>v(numValores);
        vector<int>c(numValores-1);

        for (int j = 0; j < numValores; ++j) {
            cin >> v[j];
        }
        for (int j = 0; j < numValores-1; ++j) {
            cin >> c[j];
        }

        cout << elementoPerdido(v, c, 0, numValores - 1)<<"\n";
       


    }




}

int main()
{
    casoDePrueba();
    return 0;
}