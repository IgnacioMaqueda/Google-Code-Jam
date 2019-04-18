#include <bits/stdc++.h>

using namespace std;

int obtenerResultado(vector<int> &intentos, vector<int> &congruencias, vector<int> &productos) {
    int i = 6;
    int actual = congruencias[6];
    while (i > 0) {
        while (actual % intentos[i - 1] != congruencias[i - 1]) {
            actual += productos[i];
        }
        i--;
    }
    return actual;
}

int main() {
    int T, N, M, congruencia, aux;
    vector<int> intentos = {3, 4, 5, 7, 11, 13, 17};
    vector<int> productos = {1021020, 340340, 85085, 17017, 2431, 221, 17};
    vector<int> congruencias(7);
    cin >> T >> N >> M;
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 18; ++k) {
                cout << intentos[j] << " ";
            }
            cout << endl;
            congruencia = 0;
            for (int k = 0; k < 18; ++k) {
                cin >> aux;
                congruencia += aux;
            }
            congruencias[j] = congruencia % intentos[j];
        }
        cout << obtenerResultado(intentos, congruencias, productos) << endl;
        cin >> aux;
        if (aux == -1) {
            return -1;
        }
    }
    return 0;
}
