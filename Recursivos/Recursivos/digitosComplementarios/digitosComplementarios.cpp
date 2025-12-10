#include <iostream>
using namespace std;

int jugandoDig(int num) {

	if (num < 10) {
		return 9 - (num % 10);
	}
	else {
		int resAnt = jugandoDig(num / 10);
		int newDig = 9-(num % 10);
		

		return resAnt * 10 + newDig;

	}

}


int jugandoDigInv(int num,int acumulado) {

	if (num < 10) {
		return acumulado * 10 + 9 - (num % 10);
	}
	else {

		return jugandoDigInv(num / 10, acumulado *10+ 9 - (num % 10));

	}

}


void casoDePrueba() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		int num;
		cin >> num;
		cout << jugandoDig(num) << " "<< jugandoDigInv(num,0) <<" \n";
	}
}

int main()
{
	casoDePrueba();
	return 0;
}