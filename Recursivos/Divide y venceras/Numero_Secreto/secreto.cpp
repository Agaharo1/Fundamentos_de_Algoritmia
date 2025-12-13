#include <iostream>
#include <vector>
using namespace std;


int secreto(const vector<int>& v, int ini, int fin,int num) {
	if (ini > fin){
		return num ;
	}
	else {
		int mitad = (ini + fin) / 2;
		int numerin = num * 10 + v[mitad];
		if (v[mitad] % 2 == 0) {
			return secreto(v, ini, mitad-1, numerin);
		}
		else {
			return secreto(v, mitad+1, fin, numerin);
		}
	}
}


bool casoDePrueba() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int numero=0;
		cout << secreto(v, 0, n-1, numero) << "\n";
	}
}

int main()
{
	while (casoDePrueba());
}
