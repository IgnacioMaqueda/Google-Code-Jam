#include <bits/stdc++.h>

using namespace std;

void split(vector<string> &P, vector<string> &prefixes, vector<string> &postfixes, const int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P[i].size(); ++j) {
            if (P[i][j] == '*') {
                prefixes[i] = P[i].substr(0, j);
                postfixes[i] = P[i].substr(j + 1, P[i].size() - j - 1);
                break;
            }
        }
    }
}

bool isLonger(const string& P1, const string& P2) {
    return P1.size() > P2.size();
}

bool isPrefix(string &P, string &P0) {
    for (int i = 0; i < P.size(); ++i) {
        if (P[i] != P0[i]) {
            return false;
        }
    }
    return true;
}

bool existsNamePrefix(vector<string> &P, const int N) {
    for (int i = 1; i < N; ++i) {
        if (not isPrefix(P[i], P[0])) {
            return false;
        }
    }
    return true;
}

bool isPostfix(string &P, string &P0) {
    for (int i = 0; i < P.size(); ++i) {
        if (P[P.size() - 1 - i] != P0[P0.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool existsNamePostfix(vector<string> &P, const int N) {
    for (int i = 1; i < N; ++i) {
        if (not isPostfix(P[i], P[0])) {
            return false;
        }
    }
    return true;
}

int main() {
    int T, N;
    string Pi;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<string> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> Pi;
            P[i] = Pi;
        }
        vector<string> prefixes(N);
        vector<string> postfixes(N);
        split(P, prefixes, postfixes, N);
        sort(prefixes.begin(), prefixes.end(), isLonger);
        sort(postfixes.begin(), postfixes.end(), isLonger);
        if (existsNamePrefix(prefixes, N) and existsNamePostfix(postfixes, N)) {
            cout << "Case #" << t << ": " << prefixes[0] << postfixes[0] << "\n";
        } else {
            cout << "Case #" << t << ": *\n";
        }
    }
}
