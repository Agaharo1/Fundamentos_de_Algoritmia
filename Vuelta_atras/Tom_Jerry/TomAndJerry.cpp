#include <vector>
#include <iostream>
#include <cmath>     

using namespace std;

typedef struct {
    int numTeclas;
    int numPulsaciones;
    int castigoMax;
    vector<vector<int>> v;
} tDatos;

typedef struct {
    int castigoAcumulado;
    int recompensa;
    vector<int> teclasPulsadas; 
} tJaula;


void tomYjerry(const tDatos& datos, tJaula& jaulaActual, tJaula& mejorJaula, bool& solucion, int k) {

  
    if (k == datos.numPulsaciones) {
     
        if (!solucion || jaulaActual.recompensa > mejorJaula.recompensa) {
            solucion = true;
            mejorJaula.recompensa = jaulaActual.recompensa;
            
        }
        return;
    }

  
    for (int i = 0; i < datos.numTeclas; ++i) {

        
        int costeCastigo = 0;
        int costeRecompensa = 0;

        
        if (k > 0) {
            int ultTecla = jaulaActual.teclasPulsadas[k - 1];
            int valor = datos.v[ultTecla][i];

            costeRecompensa = valor;
            if (valor < 0) {
                costeCastigo = abs(valor);
            }
        }
        if (jaulaActual.castigoAcumulado + costeCastigo <= datos.castigoMax) {

            jaulaActual.teclasPulsadas[k] = i;       
            jaulaActual.castigoAcumulado += costeCastigo;
            jaulaActual.recompensa += costeRecompensa;

            tomYjerry(datos, jaulaActual, mejorJaula, solucion, k + 1);

            
            jaulaActual.castigoAcumulado -= costeCastigo;
            jaulaActual.recompensa -= costeRecompensa;
            
        }
    }
}

void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int z = 0; z < numCasos; ++z) {
        tDatos datos;
        cin >> datos.numTeclas >> datos.numPulsaciones >> datos.castigoMax;

        datos.v.resize(datos.numTeclas, vector<int>(datos.numTeclas));
        for (int i = 0; i < datos.numTeclas; ++i) {
            for (int j = 0; j < datos.numTeclas; ++j) {
                cin >> datos.v[i][j];
            }
        }

       
        tJaula jaulaActual;
        jaulaActual.castigoAcumulado = 0;
        jaulaActual.recompensa = 0;
        jaulaActual.teclasPulsadas.resize(datos.numPulsaciones);

        tJaula mejorJaula;
        mejorJaula.recompensa = 0;
 
        mejorJaula.teclasPulsadas.resize(datos.numPulsaciones);

        bool solucion = false;

        tomYjerry(datos, jaulaActual, mejorJaula, solucion, 0);

        if (solucion) {
            cout << mejorJaula.recompensa << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    casoDePrueba();
    return 0;
}