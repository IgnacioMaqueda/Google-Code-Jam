#include <bits/stdc++.h>

using namespace std;

int trace(vector<vector<int> > &M, int N) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += M[i][i];
    }
    return res;
}

int repRows(vector<vector<int> > &M, int N) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        vector<int> rowValues(N + 1);
        for (int j = 0; j < N; ++j) {
            rowValues[M[i][j]]++;
            if (rowValues[M[i][j]] > 1) {
                res++;
                break;
            }
        }
    }
    return res;
}

int repCols(vector<vector<int> > &M, int N) {
    int res = 0;
    for (int j = 0; j < N; ++j) {
        vector<int> colValues(N + 1);
        for (int i = 0; i < N; ++i) {
            colValues[M[i][j]]++;
            if (colValues[M[i][j]] > 1) {
                res++;
                break;
            }
        }
    }
    return res;
}

int main() {
    int T, N, Mij, k, r, c;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<vector<int> > M(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> Mij;
                M[i][j] = Mij;
            }
        }
        cout << "Case #" << t << ": " << trace(M, N) << " " << repRows(M, N) << " " << repCols(M, N) << "\n";
    }
    return 0;
}
