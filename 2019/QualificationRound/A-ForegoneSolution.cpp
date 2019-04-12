#include <iostream>

using namespace std;

void sacarCuatros(string &N, string &O) {
    string res = N;
    for (unsigned int i = 0; i < N.size(); ++i) {
        if (N[i] == '4') {
            N[i] = '3';
            O[i] = '1';
        } else {
            O[i] = '0';
        }
    }
}

int main() {
    int T;
    string N, O;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        O = N;
        sacarCuatros(N, O);
        cout << "Case #" << i << ": " << N << " " << O << "\n";
    }
    return 0;
}
