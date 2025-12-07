#include <iostream>
using namespace std;


string binario(int num) {

	if (num == 1) {
		return "1";
	}
	else if (num == 0) {
		return "0";
	}
	else {
		string res = binario(num / 2);
		string newRes;
		if (num % 2 == 0) {
			newRes = "0";
		}
		else {
			newRes = "1";
		}
		return res+newRes;
		
	}

}

void casoDePrueba() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		int num;
		cin >> num;
		cout << binario(num) <<  " \n";
	}
}

int main()
{
	casoDePrueba();
	return 0;
}