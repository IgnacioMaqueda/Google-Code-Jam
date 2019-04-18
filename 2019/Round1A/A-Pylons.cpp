#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<vector<int> > > > recorridos(5, vector<vector<vector<int> > >(10));

void imprimirVector(int fi, int co, int desplazamientoV, int desplazamientoH, bool invertir) {
    bool otro = not invertir;
    if (invertir) {
        swap(desplazamientoH, desplazamientoV);
    }
    for (auto & lugar : recorridos[fi][co]) {
        cout << lugar[invertir] + desplazamientoV << " " << lugar[otro] + desplazamientoH << "\n";
    }
}

void imprimirSolucion(int R, int C) {
    bool invertir = false;
    int r = 0;
    int c, resto, cantIg;
    if (R == 4 and C == 4) {
        imprimirVector(R, C, 0, 0, invertir);
    } else {
        if (R > C) {
            invertir = true;
            swap(R, C);
        }
        while (r < R - 3) {
            c = 0;
            resto = (C % 5) + 5;
            cantIg = C - resto;
            while (c < cantIg) {
                imprimirVector(2, 5, r, c, invertir);
                c += 5;
            }
            imprimirVector(2, resto, r, c, invertir);
            r += 2;
        }
        if (r == R - 3) {
            c = 0;
            resto = (C % 4) + 4;
            cantIg = C - resto;
            while (c < cantIg) {
                imprimirVector(3, 4, r, c, invertir);
                c += 4;
            }
            imprimirVector(3, resto, r, c, invertir);
        } else {
            c = 0;
            resto = (C % 5) + 5;
            cantIg = C - resto;
            while (c < cantIg) {
                imprimirVector(2, 5, r, c, invertir);
                c += 5;
            }
            imprimirVector(2, resto, r, c, invertir);
        }
    }
}

int main() {
    recorridos[2][5] = {{1,1},{2,4},{1,2},{2,5},{1,3},{2,1},{1,4},{2,2},{1,5},{2,3}};
    recorridos[2][6] = {{1,1},{2,4},{1,6},{2,2},{1,4},{2,6},{1,2},{2,5},{1,3},{2,1},{1,5},{2,3}};
    recorridos[2][7] = {{1,1},{2,3},{1,5},{2,7},{1,4},{2,1},{1,3},{2,5},{1,7},{2,2},{1,6},{2,4},{1,2},{2,6}};
    recorridos[2][8] = {{1,1},{2,3},{1,5},{2,7},{1,4},{2,1},{1,8},{2,5},{1,3},{2,8},{1,6},{2,2},{1,7},{2,4},{1,2},{2,6}};
    recorridos[2][9] = {{1,1},{2,4},{1,2},{2,6},{1,4},{2,1},{1,5},{2,8},{1,6},{2,9},{1,7},{2,3},{1,8},{2,2},{1,9},{2,7},{1,3},{2,5}};
    recorridos[3][4] = {{1,1},{3,2},{1,3},{2,1},{3,4},{2,2},{1,4},{3,3},{1,2},{2,4},{3,1},{2,3}};
    recorridos[3][5] = {{1,1},{2,4},{3,2},{1,3},{3,4},{1,5},{2,2},{3,5},{1,4},{2,1},{3,3},{1,2},{2,5},{3,1},{2,3}};
    recorridos[3][6] = {{1,1},{2,5},{3,2},{1,3},{2,6},{3,3},{2,1},{1,4},{2,2},{3,4},{1,5},{3,6},{2,4},{1,6},{3,5},{1,2},{3,1},{2,3}};
    recorridos[3][7] = {{1,1},{2,6},{3,2},{1,3},{3,4},{1,5},{2,1},{3,6},{2,2},{1,7},{3,1},{2,5},{3,7},{1,6},{2,3},{3,5},{1,4},{3,3},{2,7},{1,2},{2,4}};
    recorridos[4][4] = {{1,1},{2,3},{3,1},{1,4},{4,3},{2,2},{4,1},{3,3},{2,1},{4,2},{3,4},{1,3},{4,4},{3,2},{2,4},{1,2}};
    int T, R, C;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> R >> C;
        if (R + C > 6) {
            cout << "Case #" << i << ": POSSIBLE\n";
            imprimirSolucion(R, C);
        } else {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        }
    }
    return 0;
}
