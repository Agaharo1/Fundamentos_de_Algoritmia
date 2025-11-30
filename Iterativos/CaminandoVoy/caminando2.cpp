using namespace std;
#include <iostream>
#include <vector>





bool caminandoVoy(int v[], int dixMax, int n) {
    int i = 0;
    int acumulado = 0;


    while ((i < n) && (acumulado <= dixMax)) {
        if (v[i] < v[i + 1]) {
            acumulado += (v[i + 1] - v[i]);
        }
        else {
            acumulado = 0;
        }
        ++i;
    }


    return (i < n) || (acumulado > dixMax);
}





bool casoDePrueba() {

    int numValores, disMax;
    int v[200002];
    cin >> disMax;
    cin >> numValores;

    if (!cin)
        return false;
    else {
        for (int i = 0; i < numValores; i++) {
            cin >> v[i];
        }

        caminandoVoy(v, disMax, numValores - 1) ? printf("NO APTA\n") : printf("APTA\n");



        return true;
    }
}

int main() {

    while (casoDePrueba());

    return 0;

}