#include <vector>
#include <iostream>
using namespace std;


int golosi(int N, const vector<int>& C, const vector<int>& V, int U) {

    int i = 0;
    int j = 0;
    int cal_act = 0;
    int nut_act = 0;
    int max_nut = 0;

    while (j < N) {

        cal_act += C[j];
        nut_act += V[j];
        j++;

    
        while (cal_act > U) {
            cal_act -= C[i];
            nut_act -= V[i];
            i++;
        }


        if (nut_act > max_nut) {
            max_nut = nut_act;
        }

 
    }

    return max_nut;
}


bool casoDePrueba() {
    int numValores,umbral;
    cin >> numValores;
    if (numValores == -1) {
        return false;
    }
    else {
        vector<int>v_cal(numValores);
        vector<int>v_nut(numValores);
        for (int i = 0; i < numValores; ++i) {
            cin >> v_cal[i];
        }
        for (int i = 0; i < numValores; ++i) {
            cin >> v_nut[i];
        }
        cin >> umbral;
        cout <<golosi(numValores,v_cal,v_nut,umbral)<< "\n";
        return true;
    }
}

int main()
{
    while (casoDePrueba());
    return 0;
}

