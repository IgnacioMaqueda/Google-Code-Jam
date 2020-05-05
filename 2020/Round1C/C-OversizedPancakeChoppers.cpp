#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int solveCase2(ull N, ull D, vector<ull> &A) {
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] == A[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int solveCase3(ull N, ull D, vector<ull> &A) {
    for (int i = 2; i < A.size(); ++i) {
        if (A[i] == A[i - 1] and A[i] == A[i - 2]) {
            return 0;
        }
    }
    for (int i = 0; i < A.size() - 1; ++i) {
        ull doubleAi = 2 * A[i];
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[j] == doubleAi) {
                return 1;
            }
        }
    }
    for (int i = 1; i < A.size() - 1; ++i) {
        if (A[i] == A[i - 1]) {
            return 1;
        }
    }
    return 2;
}

int main() {
    int T, result;
    ull N, D;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> D;
        vector<ull> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        if (D == 2) {
            result = solveCase2(N, D, A);
        } else {
            result = solveCase3(N, D, A);
        }
        cout << "Case #" << t << ": " << result << "\n";
    }
}
