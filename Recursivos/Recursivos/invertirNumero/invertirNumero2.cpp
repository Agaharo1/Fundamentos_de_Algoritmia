#include <iostream>
using namespace std;


int invertirNum(int n,int acumulado) {
	if (n ==0) {
		return acumulado ;  
	}
	//Recursion final
	return invertirNum(n / 10, (acumulado * 10) + (n % 10));

	
}

bool casoDePrueba() {
	int num;
	cin >> num;
	if (num != 0) {

		cout<<invertirNum(num,0)<<"\n";
		
		return true;
	}
	else {
		return false;
	}
}
int main()
{

	while (casoDePrueba());
	return 0;
}

