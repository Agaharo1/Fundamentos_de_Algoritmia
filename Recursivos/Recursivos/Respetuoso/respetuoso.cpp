
#include <iostream>
using namespace std;

int respetuoso(int n,int &cont) {
    if (n < 10) {
        return n;
    }
    else {
        int maxActual = respetuoso(n / 10, cont);

        if (maxActual <= n % 10) {
            cont++;
            return n % 10;
        }
        return maxActual;
    }
}

void casoDePrueba() {
    int n,num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        int cont = 1;
         respetuoso(num,cont);
         cout << cont << "\n";
    }
}
int main()
{
    casoDePrueba();
    return 0;
}

