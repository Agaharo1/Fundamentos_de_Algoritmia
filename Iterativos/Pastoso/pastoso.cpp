#include <iostream>
#include <vector>
using namespace std;


pair<bool,int> pastoso(vector<int>& v, int n) {

    int i = n-1;
    int suma = 0;
    while ((i >= 0)&&(suma!=v[i])) {
        suma+=v[i];
        --i;
    }
    return pair<bool, int>(i >= 0,i);
}



void casoDePrueba() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        pair<bool,int> past = pastoso(v, n);
        if (past.first) {
            cout <<"SI " <<past.second<< "\n";
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

