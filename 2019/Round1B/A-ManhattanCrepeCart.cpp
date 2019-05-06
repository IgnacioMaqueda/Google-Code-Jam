#include <bits/stdc++.h>

using namespace std;

void acumularAizq(vector<int> &v) {
    int acumulador = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        acumulador += v[i];
        v[i] = acumulador;
    }
}

void acumularAder(vector<int> &v) {
    int acumulador = 0;
    for (int i = 0; i < v.size(); ++i) {
        acumulador += v[i];
        v[i] = acumulador;
    }
}

void sumar(vector<int> &v1, vector<int> &v2) {
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] += v2[i];
    }
}

int lugarMax(vector<int> &v) {
    int res;
    int maximo = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > maximo) {
            maximo = v[i];
            res = i;
        }
    }
    return res;
}

int main() {
    int T, P, Q, Xi, Yi, resX, resY;
    char Di;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> P >> Q;
        vector<int> colsL(Q + 1);
        vector<int> colsR(Q + 1);
        vector<int> rowsU(Q + 1);
        vector<int> rowsD(Q + 1);
        for (int j = 0; j < P; ++j) {
            cin >> Xi >> Yi >> Di;
            if (Di == 'N') {
                rowsU[Yi + 1]++;
            } else if (Di == 'S') {
                rowsD[Yi - 1]++;
            } else if (Di == 'E') {
                colsR[Xi + 1]++;
            } else {
                colsL[Xi - 1]++;
            }
        }
        acumularAizq(colsL);
        acumularAizq(rowsD);
        acumularAder(colsR);
        acumularAder(rowsU);
        sumar(rowsD, rowsU);
        sumar(colsL, colsR);
        resX = lugarMax(colsL);
        resY = lugarMax(rowsD);
        cout << "Case #" << i << ": " << resX << " " << resY << "\n";
    }
    return 0;
}
