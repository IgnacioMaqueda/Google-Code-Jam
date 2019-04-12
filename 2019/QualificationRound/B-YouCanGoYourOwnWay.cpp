#include <iostream>

using namespace std;

void obtenerCamino(string &P, string &C) {
    string res = P;
    for (unsigned int i = 0; i < P.size(); ++i) {
        if (P[i] == 'E') {
            C[i] = 'S';
        } else {
            C[i] = 'E';
        }
    }
}

int main() {
    int T, N;
    string P, C;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> P;
        C = P;
        obtenerCamino(P, C);
        cout << "Case #" << i << ": " << C << "\n";
    }
    return 0;
}
