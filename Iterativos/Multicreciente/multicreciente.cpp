#include <vector>
#include <iostream>
using namespace std;



bool multicreciente(const vector<int>& v, int n) {
	int i = 0;
	int j = 1;
	int segMax = 0;
	int segMaxAnterior = -1;
	
	while ((j <= n) && (segMaxAnterior < segMax)) {

		if (v[j] <= v[j-1]) {
			int nuevaLongitud = j - i;

			if (nuevaLongitud >= segMax) {
				segMaxAnterior = segMax;
				segMax = nuevaLongitud;
			}
			
			i = j;	
		}
		++j;		
	}
	bool cumple = (j > n) && (segMaxAnterior < segMax);

	if (cumple) {
		if ((j - i) <= segMax) {
			return false;
		}
		else return true;
	}
	else {
		return false;
	}
}


bool casoDePrueba() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {

		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		if (multicreciente(v, n - 1)) {
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
}

