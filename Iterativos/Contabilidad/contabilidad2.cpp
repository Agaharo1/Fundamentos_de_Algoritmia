
// Esquema de la entrada: caso de prueba que marca el final
using namespace std;
#include <iostream>
#include <vector>



//{Pre: 1<=n<=longitud(v)}
bool contabilidad(int v[], int numValores) {

    //El invariante es en este caso
    //para cuando no se ha encontrado todavia la propiedad
    
    //{I: -1 <= i <= n-1 ^ ParaTodo k : i < k < n : v[k] != Sum }
    //{C:i + 1}
    int i = numValores - 1;
    int suma = 0;
    while ((i >=0) && (v[i] != suma)) {
        suma += v[i];
        --i;
    }
    return i < 0;
    
}
//{Pos: ret = Ex. k: 0 <= k < n : v[k]==suma }
//{suma = Sum.  k < j < n : v[j]}



bool casoDePrueba() {
    int numValores;
    int v[100000];

    cin >> numValores;

    if (numValores == 0)
        return false;
    else {

        for (int i = 0; i < numValores; i++) {
            cin >> v[i];
        }

        if (!contabilidad(v, numValores)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

        return true;
    }

} 

int main() {

    while (casoDePrueba());

    return 0;

} // main