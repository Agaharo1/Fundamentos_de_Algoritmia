#include <iostream>
using namespace std;


const int MAXOBJS = 100;

typedef struct {
    int tamanio[MAXOBJS];
    int valor[MAXOBJS];   
    int nobjs;
} tAlmacen; 

typedef struct {
    int capacidad;
    int ocupacion;
    int objs[MAXOBJS];
    int nobjs;
    int valor;            
} tMochila; 


void marcar(tMochila& mochila, const tAlmacen& almacen, int indice) {
    mochila.objs[mochila.nobjs] = indice;
    mochila.nobjs++;
    mochila.valor += almacen.valor[indice];      
    mochila.ocupacion += almacen.tamanio[indice];
}


void desmarcar(tMochila& mochila, const tAlmacen& almacen, int indice) {
    mochila.nobjs--;
    mochila.valor -= almacen.valor[indice];      
    mochila.ocupacion -= almacen.tamanio[indice];
}


void copiar_mochila(const tMochila& mochila, tMochila& copia) {
    copia.capacidad = mochila.capacidad;
    copia.ocupacion = mochila.ocupacion;
    copia.nobjs = mochila.nobjs;
    copia.valor = mochila.valor;                 
    for (int i = 0; i < mochila.nobjs; i++) {
        copia.objs[i] = mochila.objs[i];
    }
} 



void montar_mochila(const tAlmacen& almacen, tMochila& mochila_actual,
    int obj, bool& hay_mejor, tMochila& mejor_mochila) {

    if (obj == almacen.nobjs) {
        if (!hay_mejor || mochila_actual.valor > mejor_mochila.valor) {
            copiar_mochila(mochila_actual, mejor_mochila);
            hay_mejor = true;
        }
    }

    else {

        // si cabe en la mochila
        if (almacen.tamanio[obj] + mochila_actual.ocupacion <= mochila_actual.capacidad) {

            marcar(mochila_actual, almacen, obj); 

        
            montar_mochila(almacen, mochila_actual, obj + 1, hay_mejor, mejor_mochila);

            desmarcar(mochila_actual, almacen, obj); 
        }

    
        montar_mochila(almacen, mochila_actual, obj + 1, hay_mejor, mejor_mochila);
    }
} 


void hacer_mochila(const tAlmacen& almacen, int capacidad, tMochila& mejor_mochila) {
    tMochila mochila_inicial;
    mochila_inicial.valor = 0;        
    mochila_inicial.capacidad = capacidad;
    mochila_inicial.ocupacion = 0;
    mochila_inicial.nobjs = 0;

    bool hay_mejor = false;
    montar_mochila(almacen, mochila_inicial, 0, hay_mejor, mejor_mochila);
}

int main() {
    tAlmacen almacen;
    int capacidad_mochila;

 
    cin >> almacen.nobjs;
    if (almacen.nobjs > MAXOBJS) return 1;

   
    for (int i = 0; i < almacen.nobjs; i++) {
        cin >> almacen.tamanio[i];
        cin >> almacen.valor[i]; 
    }

    cin >> capacidad_mochila;

  
    tMochila mejor_solucion;
    hacer_mochila(almacen, capacidad_mochila, mejor_solucion);

    cout << "--- RESULTADO OPTIMO ---\n" ;
    cout << "Capacidad limite: " << capacidad_mochila << "\n";
    cout << "Peso final ocupado: " << mejor_solucion.ocupacion << "\n";
    cout << "Valor total conseguido: " << mejor_solucion.valor << "\n";

    if (mejor_solucion.nobjs > 0) {
        cout << "Objetos seleccionados (por indice): ";
        for (int i = 0; i < mejor_solucion.nobjs; i++) {
            cout << mejor_solucion.objs[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "No se selecciono ningun objeto\n";
    }

    return 0;
}