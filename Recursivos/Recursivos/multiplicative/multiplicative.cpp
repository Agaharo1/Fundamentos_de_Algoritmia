
#include <iostream>

using namespace std;


int multiplicative(int num, int& mult) {
    if (num < 10) {
        int count = 0;
        if (num % 10 == 1) {
            ++count;
        }
        mult = num;

        return count ;
    }
    else {
        int co = multiplicative(num / 10, mult);

        int dig = num % 10;

        if (mult % 10 == dig) {
            co++;
        }
        mult *= dig;

        return co;

    }
}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (!cin) {
        return false;
    }
    else {
        int mult = 0;
        cout << multiplicative(num, mult) << "\n";
    }
}


int main()
{
    while (resuelveCaso());
}
