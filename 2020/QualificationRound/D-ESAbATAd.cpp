#include <bits/stdc++.h>

using namespace std;

void solveCase10(const int T) {
    vector<int> bits(11);
    char answer;
    for (int t = 0; t < T; ++t) {
        for (int i = 1; i <= 10; ++i) {
            cout << i << endl;
            cin >> bits[i];
        }
        for (int i = 1; i <= 10; ++i) {
            cout << bits[i];
        }
        cout << endl;
        cin >> answer;
        if (answer == 'N') {
            break;
        }
    }
}

void solveCase20(const int T) {
    vector<int> bits(21);
    int bit, bitE, bitD;
    char answer;
    for (int t = 0; t < T; ++t) {
        vector<int> equal(2, -1);
        vector<int> different(2, -1);
        vector<int> complemented(2);
        vector<int> reversed(2);
        for (int p = 0; p < 2; ++p) {
            for (int i = 5 * p + 1; i <= 5 * p + 5; ++i) {
                cout << i << endl;
                cin >> bits[i];
                cout << 21 - i << endl;
                cin >> bits[21 - i];
                if (bits[i] == bits[21 - i]) {
                    equal[p] = i;
                } else {
                    different[p] = i;
                }
            }
        }
        for (int p = 0; p < 2; ++ p) {
            if (equal[p] == -1 or different[p] == -1) {
                cout << 5 * p + 1 << endl;
                cin >> bit;
                if (bit != bits[5 * p + 1]) {
                    complemented[p] = 1;
                }
            } else {
                cout << equal[p] << endl;
                cin >> bitE;
                cout << different[p] << endl;
                cin >> bitD;
                if (bitE != bits[equal[p]] and bitD == bits[different[p]]) {
                    complemented[p] = 1;
                    reversed[p] = 1;
                } else if (bitE == bits[equal[p]] and bitD != bits[different[p]]) {
                    reversed[p] = 1;
                } else if (bitE != bits[equal[p]] and bitD != bits[different[p]]) {
                    complemented[p] = 1;
                }
            }
        }

        for (int p = 0; p < 2; ++p) {
            if (complemented[p] == 1) {
                for (int i = 5 * p + 1; i <= 5 * p + 5; ++i) {
                    bits[i] = 1 - bits[i];
                    bits[21 - i] = 1 - bits[21 - i];
                }
            }
            if (reversed[p] == 1) {
                for (int i = 5 * p + 1; i <= 5 * p + 5; ++i) {
                    bit = bits[i];
                    bits[i] = bits[21 - i];
                    bits[21 - i] = bit;
                }
            }
        }

        for (int i = 1; i <= 20; ++i) {
            cout << bits[i];
        }
        cout << endl;
        cin >> answer;
        if (answer == 'N') {
            break;
        }
    }
}

void solveCase100(const int T) {
    for (int t = 0; t < T; ++t) {

    }
}

int main() {
    int T, B;
    cin >> T >> B;
    if (B == 10) {
        solveCase10(T);
    } else if (B == 20) {
        solveCase20(T);
    } else if (B == 100) {
        solveCase100(T);
    }
    return 0;
}
