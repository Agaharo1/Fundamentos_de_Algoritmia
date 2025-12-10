#include <iostream>
using namespace std;


long long eliminarPares(long long num) {

	if(num < 10) {
		if (num % 2 == 0) {
			return 0;
		}
		else {
			return num;
		}
	}
	else {
		long long res = eliminarPares(num / 10);
		
		if ((num%10) % 2 != 0) {
			return res*10+num%10;
		}
		return res;
	}
}//Solo hecho con recursion no final :)

bool casoDePrueba() {


		long long num;
		cin >> num;

		if (!cin) {
			return false;
		}
		else {
			cout << eliminarPares(num) <<" "<< eliminarPares(num) << "\n";
			return true;
		}
		
	
}

int main()
{
	while(casoDePrueba());
	return 0;
}