#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int casillas ;
	int filas;
	vector<vector<int>> monedas;
}tTablero;

typedef struct {
	vector<bool>fila_ocupada;
	vector<vector<bool>> posicionOcupada;
	int monedasAcumuladas;

}tOcupadas;

void marcar(int fila, int col, tOcupadas& tableroActual, tTablero& datos) {
	tableroActual.fila_ocupada[fila] = true;
	tableroActual.monedasAcumuladas += datos.monedas[fila][col];
	tableroActual.posicionOcupada[fila][col] = true;

}

void desMarcar(int fila, int col, tOcupadas& tableroActual, tTablero& datos) {
	tableroActual.fila_ocupada[fila] = false;
	tableroActual.monedasAcumuladas -= datos.monedas[fila][col];
	tableroActual.posicionOcupada[fila][col] = false;
}

void contarMonedas(tTablero& datos, tOcupadas& tableroActual, int k, tOcupadas& mejorTablero) {

	if (k < datos.filas) {
		for (int fila = 0; fila < datos.filas; fila++) {
			if (!tableroActual.fila_ocupada[fila]) {
				marcar(fila, k, tableroActual, datos);
				contarMonedas(datos, tableroActual, k + 1, mejorTablero);
				desMarcar(fila, k, tableroActual, datos);
			}
		}
	}
	else {
		if (tableroActual.monedasAcumuladas > mejorTablero.monedasAcumuladas) {
			mejorTablero.monedasAcumuladas = tableroActual.monedasAcumuladas;
		}
	}

}

bool casoDePrueba() {
	int n;

	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		tTablero tablero;
		tOcupadas ocupadas;
		tablero.monedas = vector<vector<int>>(n, vector<int>(n, 0));
		tablero.casillas = n * n;
		tablero.filas = n;
		ocupadas.fila_ocupada = vector<bool>(n, false);
		ocupadas.posicionOcupada = vector<vector<bool>>(n, vector<bool>(n, false));
		ocupadas.monedasAcumuladas = 0;


		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> tablero.monedas[i][j];
			}
		}
		tOcupadas mejorSolucion;
		mejorSolucion.monedasAcumuladas = 0;
		contarMonedas(tablero, ocupadas, 0, mejorSolucion);

		cout << mejorSolucion.monedasAcumuladas << "\n";

		return true;
	}
}

int main()
{
	while (casoDePrueba());
	return 0;
}
