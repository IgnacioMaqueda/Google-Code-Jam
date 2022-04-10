#include <bits/stdc++.h>

using namespace std;

string firstString(string &S) {
    vector<bool> repeat(S.size(), false);
    int i = S.size() - 2;
    while (i >= 0 and S[i] == S[i + 1]) {
        --i;
    }
    bool repeatI;
    while (i >= 0) {
        if (S[i] != S[i + 1]) {
            repeatI = S[i] < S[i + 1];
        }
        if (repeatI) {
            repeat[i] = true;
        }
        --i;
    }
    string res;
    for (int j = 0; j < S.size(); ++j) {
        res.push_back(S[j]);
        if (repeat[j]) {
            res.push_back(S[j]);
        }
    }
    return res;
}

int main() {
    int T;
    string S;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        cout << "Case #" << t << ": " << firstString(S) << "\n";
    }
    return 0;
}
