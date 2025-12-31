#include <iostream>
#include <vector>
#include <algorithm> // Para max

using namespace std;


typedef struct {
    int numAnimales;
    int numCamiones;
    int pesoMax;
    vector<int> pesos;
    vector<int> fama;
    vector<int> enemigos;
} tDatos;

typedef struct {
    int famaActual;
    vector<int> pesoCamiones;    
    vector<int> dondeEstaAnimal; 
} tSolucion;




void marcar(const tDatos& datos, tSolucion& sol, int k, int idCamion) {
    sol.pesoCamiones[idCamion] += datos.pesos[k];
    sol.famaActual += datos.fama[k];              
    sol.dondeEstaAnimal[k] = idCamion;            
}

void desmarcar(const tDatos& datos, tSolucion& sol, int k, int idCamion) {
    sol.pesoCamiones[idCamion] -= datos.pesos[k]; 
    sol.famaActual -= datos.fama[k];              
    sol.dondeEstaAnimal[k] = -1;                  
}


bool esValido(const tDatos& datos, const tSolucion& sol, int animalK, int idCamion) {
    if (sol.pesoCamiones[idCamion] + datos.pesos[animalK] > datos.pesoMax) {
        return false;
    }

    int enemigo = datos.enemigos[animalK];
    if (enemigo != -1) { 
        if (sol.dondeEstaAnimal[enemigo] != -1) {
            if (sol.dondeEstaAnimal[enemigo] == idCamion) {
                return false;
            }
        }
    }
    return true; 
}

void buscarFamaMax(const tDatos& datos, tSolucion& sol, int k, int& mejorFamaGlobal) {

    // Caso Base: Ya hemos decidido sobre todos los animales (del 0 al N-1)
    if (k == datos.numAnimales) {
        if (sol.famaActual > mejorFamaGlobal) {
            mejorFamaGlobal = sol.famaActual; 
        }
        return;
    }

    // OPCIÓN 1: Intentar meter al animal 'k' en cada uno de los camiones
    for (int i = 0; i < datos.numCamiones; ++i) {

        if (esValido(datos, sol, k, i)) {

            marcar(datos, sol, k, i);             
            buscarFamaMax(datos, sol, k + 1, mejorFamaGlobal); 
            desmarcar(datos, sol, k, i);    
        }
    }
    // OPCIÓN 2: No llevar al animal 'k' en ningún camión
    buscarFamaMax(datos, sol, k + 1, mejorFamaGlobal);
}



bool casoDePrueba() {
    tDatos datos;
    cin >> datos.numAnimales;
    if (datos.numAnimales == -1) return false;

    cin >> datos.numCamiones >> datos.pesoMax;

    datos.pesos = vector<int>(datos.numAnimales);
    datos.fama = vector<int>(datos.numAnimales);
    datos.enemigos = vector<int>(datos.numAnimales);

    for (int i = 0; i < datos.numAnimales; ++i) cin >> datos.pesos[i];
    for (int i = 0; i < datos.numAnimales; ++i) cin >> datos.fama[i];
    for (int i = 0; i < datos.numAnimales; ++i) cin >> datos.enemigos[i];

    tSolucion sol;
    sol.famaActual = 0;

    sol.pesoCamiones = vector<int>(datos.numCamiones, 0);
    sol.dondeEstaAnimal = vector<int>(datos.numAnimales, -1);

    int mejorFamaGlobal = 0;

    buscarFamaMax(datos, sol, 0, mejorFamaGlobal);

    cout << mejorFamaGlobal << endl;

    return true;
}

int main() {
    while (casoDePrueba());
    return 0;
}