#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull T, W, R;
    cin >> T >> W;
    vector<ull> respuestas(W);
    vector<ull> Ris(6);
    for (ull i = 0; i < T; ++i) {
        for (ull j = 0; j < W; ++j) {
            cout << j + 24 << endl;
            cin >> R;
            respuestas[j] = R;
        }
        Ris[0] = (respuestas[5] - respuestas[4]) / 268435456;
        Ris[4] = (respuestas[1] - respuestas[0] - 16777216 * Ris[0]) / 16;
        Ris[1] = (respuestas[2] - respuestas[1] - 33554432 * Ris[0]) / 4096;
        Ris[2] = (respuestas[3] - respuestas[2] - 67108864 * Ris[0]) / 256;
        Ris[3] = (respuestas[4] - respuestas[3] - 134217728 * Ris[0] - 8192 * Ris[1]) / 64;
        Ris[5] = (respuestas[0] - 16777216 * Ris[0] - 4096 * Ris[1] - 256 * Ris[2] - 64 * Ris[3] - 16 * Ris[4]) / 16;
        cout << Ris[0] << " " << Ris[1] << " "  << Ris[2] << " "  << Ris[3] << " "  << Ris[4] << " "  << Ris[5] << endl;
        cin >> R;
    }
    return 0;
}
