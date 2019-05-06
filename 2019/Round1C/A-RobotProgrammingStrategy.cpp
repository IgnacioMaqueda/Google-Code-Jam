#include <bits/stdc++.h>

using namespace std;

bool esPosibleGanar(set<string> &rivales, string &mio) {
    set<char> aparecieron;
    int i = 0;
    while (true) {
        aparecieron.clear();
        for (string rival : rivales) {
            aparecieron.insert(rival[i % rival.size()]);
        }
        if (aparecieron.size() == 3) {
            return false;
        } else if (aparecieron.size() == 2) {
            if (aparecieron.count('R') == 0) {
                mio.push_back('S');
                for (string rival : rivales) {
                    if (rival[i % rival.size()] == 'P') {
                        rivales.erase(rival);
                    }
                }
            } else if (aparecieron.count('P') == 0) {
                mio.push_back('R');
                for (string rival : rivales) {
                    if (rival[i % rival.size()] == 'S') {
                        rivales.erase(rival);
                    }
                }
            } else {
                mio.push_back('P');
                for (string rival : rivales) {
                    if (rival[i % rival.size()] == 'R') {
                        rivales.erase(rival);
                    }
                }
            }
        } else {
            if (aparecieron.count('R') == 1) {
                mio.push_back('P');
            } else if (aparecieron.count('P') == 1) {
                mio.push_back('S');
            } else {
                mio.push_back('R');
            }
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int T, A;
    string Ci, mio;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> A;
        set<string> rivales;
        for (int j = 0; j < A; ++j) {
            cin >> Ci;
            rivales.insert(Ci);
        }
        mio = "";
        if (esPosibleGanar(rivales, mio)) {
            cout << "Case #" << i << ": " << mio << "\n";
        } else {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        }
    }
    return 0;
}
