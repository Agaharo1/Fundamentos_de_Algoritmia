

#include <iostream>
#include <vector>
using namespace std;




bool caucasico(const vector<int>& v, int ini, int fin, int& numPares) {

	if (ini == fin) {
		if (v[ini] % 2 == 0) numPares = 1;
		else numPares = 0;
		return true;
	}


	int mitad = (ini + fin) / 2;
	int paresIzq = 0, paresDer = 0;


	bool esIzq = caucasico(v, ini, mitad, paresIzq);
	bool esDer = caucasico(v, mitad + 1, fin, paresDer);

	numPares = paresIzq + paresDer;

	if (abs(paresIzq - paresDer) > 2) return false;

	return esIzq && esDer;
}


bool casoDePrueba() {
	int n;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	else {
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int numPares = 0;

		if (caucasico(v, 0, n - 1, numPares)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
		return true;
	}
}


int main()
{
	while (casoDePrueba());
	return 0;
}

