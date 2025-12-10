#include <iostream>
#include <vector>

using namespace std;


int buscarIz(const vector<int>& v, int altura, int low, int high) {
    if (low > high) return -1; // Caso base: no encontrado

    int mid = low + (high - low) / 2;

    if (v[mid] == altura) {
        // Encontrado, pero podría haber otro igual a la izquierda.
        int resIzq = buscarIz(v, altura, low, mid - 1);

        // Si la llamada recursiva devolvió una posición válida, esa es la primera.
        // Si devolvió -1, entonces 'mid' es la primera aparición.
        if (resIzq != -1) return resIzq;
        else return mid;
    }
    else if (altura < v[mid]) {
        
        return buscarIz(v, altura, low, mid - 1);
    }
    else {
        
        return buscarIz(v, altura, mid + 1, high);
    }
}


int buscarDr(const vector<int>& v, int altura, int low, int high) {
    if (low > high) return -1; 

    int mid = low + (high - low) / 2;

    if (v[mid] == altura) {
     
        int resDer = buscarDr(v, altura, mid + 1, high);

      
        if (resDer != -1) return resDer;
        else return mid;
    }
    else if (altura < v[mid]) {
        
        return buscarDr(v, altura, low, mid - 1);
    }
    else {
       
        return buscarDr(v, altura, mid + 1, high);
    }
}

bool resuelveCaso() {
    int numSospechosos, alturaBandido;
   
    cin >> numSospechosos >> alturaBandido;
    if (!cin) {
        return false;
    }
    else {

        vector<int> sospechosos(numSospechosos);
        for (int i = 0; i < numSospechosos; ++i) {
            cin >> sospechosos[i];
        }


        int posIz = buscarIz(sospechosos, alturaBandido, 0, numSospechosos - 1);
        int posDr = buscarDr(sospechosos, alturaBandido, 0, numSospechosos - 1);

        
        if (posIz == -1) {
            cout << "NO EXISTE" << endl;
        }
        else if (posIz == posDr) {
        
            cout << posIz << endl;
        }
        else {
      
            cout << posIz << " " << posDr << endl;
        }
        return true;
    }
}

int main() {
    
    while (resuelveCaso());
    

    return 0;
}