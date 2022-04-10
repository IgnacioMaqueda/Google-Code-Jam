#include <bits/stdc++.h>

using namespace std;

void printDrawing(int R, int C) {
    cout << "..+";
    for (int i = 1; i < C; ++i) {
        cout << "-+";
    }
    cout << "\n..|";
    for (int i = 1; i < C; ++i) {
        cout << ".|";
    }
    cout << "\n+";
    for (int i = 0; i < C; ++i) {
        cout << "-+";
    }
    cout << "\n";
    for (int i = 1; i < R; ++i) {
        cout << "|";
        for (int j = 0; j < C; ++j) {
            cout << ".|";
        }
        cout << "\n+";
        for (int j = 0; j < C; ++j) {
            cout << "-+";
        }
        cout << "\n";
    }
}

int main() {
    int T, R, C;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> R >> C;
        cout << "Case #" << i << ":\n";
        printDrawing(R, C);
    }
    return 0;
}
