
#include <iostream>
using namespace std;

int jugandoDig(int num) {

	if (num < 10) {
		if (num % 2 == 0) return num + 1;
		else              return num - 1;
	}
	else {
		int resAnt = jugandoDig(num / 10);
		int newDig;
		if (num % 2 == 0) {
			newDig =  num % 10 + 1;
		}
		else {
			newDig =  num % 10 - 1;
		}

		return resAnt * 10 + newDig;

	}

}

void cambiandoDig(int num, int& res) {

	if (num == 0) {
		return;
	}
	else {
		cambiandoDig(num / 10, res);
		if (num % 2 == 0) {
			res = res * 10 + num % 10 + 1;
		}
		else {
			res = res * 10 + num % 10 - 1;
		}

	}


}

void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int num;
        cin >> num;
        cout << jugandoDig(num) << "\n";
    }
}

int main()
{
    casoDePrueba();
    return 0;
}

