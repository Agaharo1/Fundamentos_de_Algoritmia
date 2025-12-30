#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    vector<bool> fila_ocupada;
    vector<bool> oc_diagonal;
    vector<bool> oc_antidiagonal;
} tMarcacion;


void marcar(int col, int fila, int N, tMarcacion& marcadores) {
    marcadores.fila_ocupada[fila] = true;
    marcadores.oc_diagonal[fila + col] = true;
    marcadores.oc_antidiagonal[(fila - col) + (N - 1)] = true;
}

void desmarcar(int col, int fila, int N, tMarcacion& marcadores) {
    marcadores.fila_ocupada[fila] = false;
    marcadores.oc_diagonal[fila + col] = false;
    marcadores.oc_antidiagonal[(fila - col) + (N - 1)] = false;
}

bool amenaza(int col, int fila, int N, const tMarcacion& marcadores) {
    return marcadores.fila_ocupada[fila] ||
        marcadores.oc_diagonal[fila + col] ||
        marcadores.oc_antidiagonal[(fila - col) + (N - 1)];
}


void contar_n_reinas(int col, int N, tMarcacion& marcadores, int& contador) {
    if (col < N) {
        for (int fila = 0; fila < N; fila++) {
            if (!amenaza(col, fila, N, marcadores)) { 

                marcar(col, fila, N, marcadores); 
                contar_n_reinas(col + 1, N, marcadores, contador);
                desmarcar(col, fila, N, marcadores);
            }
        }
    }
    else {
        contador++;
    }
}

int main() {
    int N;
    int contador = 0;

 
    cout << "Introduce el tamano del tablero (N): ";
    cin >> N;

    if (N < 1) {
        cout << "El tamano debe ser al menos 1." << endl;
        return 0;
    }

    tMarcacion marcadores;

    marcadores.fila_ocupada = vector<bool>(N, false);
    marcadores.oc_diagonal = vector<bool>(2 * N - 1, false);
    marcadores.oc_antidiagonal = vector<bool>(2 * N - 1, false);

 
    contar_n_reinas(0, N, marcadores, contador);

    cout << "El numero total de soluciones viables para N=" << N << " es: " << contador << endl;

    return 0;
}