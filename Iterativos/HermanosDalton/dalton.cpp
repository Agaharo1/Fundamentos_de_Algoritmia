

#include <iostream>
#include <vector>
using namespace std;

//{Pre: 1 <= n < longitud(v)  } 
bool dalton(vector<int>& v, int n) {
    int i = 0;
  
    //{I : (0<=i<=n)^ (ret = P.t. 0 <= j <=n : v[j] < v[j+1] ∨ v[j] > v[j+1])}
    //{cota: n-i}
    if (v[i] < v[i + 1]) {
        while (i < n && v[i] < v[i + 1]) {
            ++i;
        }
    }
    else {
        while (i < n && v[i] > v[i + 1]) {
            ++i;
        }
    }
    
    return i<n;
}
//{ Post: ret = P.t. 0 <= j <=n : v[j] < v[j+1] ∨ v[j] > v[j+1] }

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n != 0) {
        vector<int>v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (!dalton(v, n-1)) {
            cout << "DALTON\n";
        }
        else {
            cout << "DESCONOCIDOS\n";
        }
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    while (resuelveCaso());
    return 0;
}

