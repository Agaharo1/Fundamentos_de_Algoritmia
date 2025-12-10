#include <iostream>
using namespace std;

int duplicar(int num) {

	if (num < 10) {
		return num * 10 + (num % 10);
	}
	else {
		int res = duplicar(num / 10);
		int newRes = (num % 10) * 10 + num % 10;

		return res * 100 + newRes;
	}
	//Solo recursion no final
}


void casoDePrueba() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		int num;
		cin >> num;
		cout << duplicar(num) << " " << duplicar(num) << "\n";

	}
}

int main()
{
	casoDePrueba();
	return 0;
}