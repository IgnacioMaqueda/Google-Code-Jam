#include <bits/stdc++.h>

using namespace std;

struct letter {
    int tower;
    bool isAll;
    bool isLeft;
    bool isRight;
};

bool isImpossible(vector<string> &S, int i) {
    set<char> past_letters;
    int j = 1;
    while (j < S[i].size()) {
        if (past_letters.count(S[i][j])) {
            return true;
        }
        if (S[i][j] != S[i][j - 1]) {
            past_letters.insert(S[i][j - 1]);
        }
        j++;
    }
    return false;
}

bool isAppendable(vector<vector<int> > &restrictions, int i, int j) {
    if (restrictions[i].empty() or restrictions[j].empty()) {
        return false;
    }
    return restrictions[i][restrictions[i].size() - 1] == restrictions[j][0];
}

string megatower(int N, vector<string> &S) {
    for (int i = 0; i < N; ++i) {
        if (isImpossible(S, i)) {
            return "IMPOSSIBLE";
        }
    }
    vector<vector<letter> > letters(26);
    for (int i = 0; i < N; ++i) {
        set<char> current_letters;
        for (char c: S[i]) {
            current_letters.insert(c);
        }
        if (current_letters.size() == 1) {
            letters[S[i][0] - 'A'].push_back({i, true, false, false});
        } else {
            letters[S[i][0] - 'A'].push_back({i, false, true, false});
            letters[S[i][S[i].size() - 1] - 'A'].push_back({i, false, false, true});
            int j = 1;
            while(S[i][j] == S[i][0]) {
                j++;
            }
            while(S[i][j] != S[i][S[i].size() - 1]) {
                if (S[i][j] != S[i][j - 1]) {
                    letters[S[i][j] - 'A'].push_back({i, false, false, false});
                }
                j++;
            }
        }
    }
    vector<vector<int> > restrictions;
    for (int i = 0; i < 26; ++i) {
        int ammount = letters[i].size();
        if (ammount > 1) {
            vector<int> restriction;
            int lefts = 0;
            int leftOne = -1;
            int rights = 0;
            int rightOne = -1;
            for (int j = 0; j < ammount; ++j) {
                if (not letters[i][j].isAll and not letters[i][j].isLeft and not letters[i][j].isRight) {
                    return "IMPOSSIBLE";
                } else if (letters[i][j].isLeft) {
                    leftOne = j;
                    lefts++;
                } else if (letters[i][j].isRight) {
                    rightOne = j;
                    rights++;
                }
            }
            if (lefts > 1 or rights > 1) {
                return "IMPOSSIBLE";
            }
            if (rightOne >= 0) {
                restriction.push_back(letters[i][rightOne].tower);
            }
            for (int j = 0; j < ammount; ++j) {
                if (j != leftOne and j != rightOne) {
                    restriction.push_back(letters[i][j].tower);
                }
            }
            if (leftOne >= 0) {
                restriction.push_back(letters[i][leftOne].tower);
            }
            restrictions.push_back(restriction);
        }
    }
    bool modifications = true;
    while (modifications) {
        modifications = false;
        for (int i = 0; i < restrictions.size(); ++i) {
            for (int j = i + 1; j < restrictions.size(); ++j) {
                if (isAppendable(restrictions, i, j) and isAppendable(restrictions, j, i)) {
                    return "IMPOSSIBLE";
                }
                if (isAppendable(restrictions, i, j)) {
                    for (int k = 1; k < restrictions[j].size(); ++k) {
                        restrictions[i].push_back(restrictions[j][k]);
                    }
                    restrictions[j] = {};
                    modifications = true;
                } else if (isAppendable(restrictions, j, i)) {
                    for (int k = 1; k < restrictions[i].size(); ++k) {
                        restrictions[j].push_back(restrictions[i][k]);
                    }
                    restrictions[i] = {};
                    modifications = true;
                }
            }
        }
    }
    vector<bool> used(N, false);
    string res;
    for (auto & restriction : restrictions) {
        for(int j : restriction) {
            res.append(S[j]);
            used[j] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (not used[i]) {
            res.append(S[i]);
        }
    }
    return res;
}

int main() {
    int T, N;
    string Si;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<string> S;
        for (int i = 0; i < N; ++i) {
            cin >> Si;
            S.push_back(Si);
        }
        cout << "Case #" << t << ": " << megatower(N, S) << "\n";
    }
    return 0;
}
