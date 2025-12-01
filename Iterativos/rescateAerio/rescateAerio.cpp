
#include <iostream>
#include <vector>
using namespace std;


pair<int,int> maxLong(const vector<int>& v, int n,int altura) {
    int i = 0;
    int ini = 0;
    int fin = 0;
    while (i < n) {
        if (v[i] >= altura) {
            ++fin;
        }
        else if (v[i] < altura) {

        }
        ++i;
    }
   
    return pair<int, int> (ini,fin);
}
void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int n,altura;
        cin >> n>>altura;
        if (n != 0) {
            vector<int>v(n);
            for (int j = 0; j < n; ++j) {
                cin >> v[j];
            }
            pair<int,int>  data = maxLong(v, n - 1, altura);
            cout << data.first<<" "<<data.second << "\n";
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