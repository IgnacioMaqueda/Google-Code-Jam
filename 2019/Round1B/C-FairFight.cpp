#include <bits/stdc++.h>

using namespace std;

int maximo(vector<int> &v, int L, int R) {
    int res = -1;
    for (int i = L; i <= R; ++i) {
        res = max(v[i], res);
    }
    return res;
}

int main() {
    int T, N, K, Ci, Di, res;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K;
        vector<int> Charles(N);
        vector<int> Delila(N);
        for (int j = 0; j < N; ++j) {
            cin >> Ci;
            Charles[j] = Ci;
        }
        for (int j = 0; j < N; ++j) {
            cin >> Di;
            Delila[j] = Di;
        }
        res = 0;
        for (int L = 0; L < N; ++L) {
            for (int R = L; R < N; ++R) {
                if (abs(maximo(Charles, L, R) - maximo(Delila, L, R)) <= K) {
                    res++;
                }
            }
        }
        cout << "Case #" << i << ": " << res << "\n";
    }
    return 0;
}
