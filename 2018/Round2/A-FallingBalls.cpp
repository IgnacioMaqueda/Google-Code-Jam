#include <bits/stdc++.h>

using namespace std;

int numberOfRows(int C, vector<int> &B, vector<int> &landingColumns) {
    int j = 0;
    int res = 0;
    for (int i = 0; i < C; ++i) {
        while (B[j] == 0) {
            ++j;
        }
        B[j]--;
        landingColumns[i] = j;
        res = max(res, abs(i - j));
    }
    return res + 1;
}

void addLeftRamp(int from, int to, vector<string> &toyLayout) {
    for (int i = from; i > to; --i) {
        toyLayout[from - i][i] = '/';
    }
}

void addRightRamp(int from, int to, vector<string> &toyLayout) {
    for (int i = from; i < to; ++i) {
        toyLayout[i - from][i] = '\\';
    }
}

void addRamps(int C, vector<int> &landingColumns, vector<string> &toyLayout) {
    for (int i = 0; i < C; ++i) {
        if (landingColumns[i] < i) {
            addLeftRamp(i, landingColumns[i], toyLayout);
        } else if (landingColumns[i] > i) {
            addRightRamp(i, landingColumns[i], toyLayout);
        }
    }
}

int main() {
    int T, C, R;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> C;
        vector<int> B(C);
        vector<int> landingColumns(C);
        for (int i = 0; i < C; ++i) {
            cin >> B[i];
        }
        if (B[0] == 0 or B[C - 1] == 0) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        } else {
            R = numberOfRows(C, B, landingColumns);
            vector<string> toyLayout(R, string(C, '.'));
            addRamps(C, landingColumns, toyLayout);
            cout << "Case #" << t << ": " << R << "\n";
            for (int i = 0; i < R; ++i) {
                cout << toyLayout[i] << "\n";
            }
        }
    }
}
