#include <iostream>
using namespace std;

bool interesante(int num,int sumaIzq,int sumaDer) {
	if (num < 10) {
	
		if (num == 0) return false;
		
		if (sumaDer % num != 0) return false;

		return true;
	}
	else {
		
		int digito = num % 10;

		int sumaPrecedentes = sumaIzq - digito;
		int nuevaSumaDer = sumaDer + digito;
	

		bool res = interesante(num / 10, sumaPrecedentes, nuevaSumaDer);

		bool dividePrecedentes = (digito != 0) && (sumaPrecedentes % digito == 0);
		bool divideSucesores = (digito != 0) && (sumaDer % digito == 0);
		
		return res && dividePrecedentes && divideSucesores;

		

		
	}
}


void casoDePrueba() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		int num;
		cin >> num;
		int sumaTotal = 0;
		int c = num;
		while(c!=0) {
			sumaTotal += c % 10;
			c/= 10;
		}
		if (interesante(num,sumaTotal,0)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}

	}
}

int main()
{
	casoDePrueba();
	return 0;
}