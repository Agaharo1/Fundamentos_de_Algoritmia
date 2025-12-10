#include <iostream>
using namespace std;



bool sumaDivisible(int num,int &numDig,int &suma) {
    if (num < 10) {
        suma = num;
        numDig++;
        return true;
    }
    else {
      
        bool res = sumaDivisible(num / 10, numDig,suma);
        numDig++;
        suma += num % 10;
        bool divisible = suma%numDig==0;
        return res && divisible;
    }
}

bool casoDePrueba() {
    int num;
    cin >> num;
    if (num == 0) {
        return false;
    }
    else {
        int numDig = 0;
        int suma = 0;
        if (sumaDivisible(num,numDig,suma)) {
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

