using namespace std;
#include <iostream>


bool dividir(int v[], int pos, int n) {

    int i = 0;
    int mayorDentroRg= v[0];
    while (i <= pos) {
        if (v[i] > mayorDentroRg) {
            mayorDentroRg = v[i];
        }
        ++i;
    }
    
    while ((i <= n) && (mayorDentroRg < v[i])) {
        ++i;
    }
    return i <= n;
}





void casoDePrueba() {

    int numValores, pos;
    int v[200003];
    cin >> numValores;
    cin >> pos;
   
    for (int i = 0; i < numValores; i++) {
        cin >> v[i];
    }

    dividir(v, pos, numValores-1) ? printf("NO\n") : printf("SI\n");


}

int main() {
    int totalCasos;
    cin >> totalCasos; // Leer la cantidad total de casos de prueba
    int i = 0;

    while (i < totalCasos) {
        casoDePrueba();
        i++;
    }


    return 0;

}