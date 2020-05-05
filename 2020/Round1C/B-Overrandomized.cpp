#include <bits/stdc++.h>

using namespace std;
using ull = long long;

int numberOfDigits(ull n) {
    int res = 0;
    while (n > 0) {
        n /= 10;
        res++;
    }
    return res;
}

ull mostSignificativeDigit(ull n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int main() {
    int T, U;
    ull Qi;
    string Ri;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> U;
        cin >> Qi >> Ri;
        if (Qi == -1) {
            set<char> allLetters;
            map<char, int> countLetters;
            for (int i = 1; i < 10000; ++i) {
                cin >> Qi >> Ri;
                if (allLetters.size() < 10) {
                    for (char r : Ri) {
                        allLetters.insert(r);
                    }
                }
                if (Ri.size() == 16) {
                    if (countLetters.count(Ri[0])) {
                        countLetters[Ri[0]]++;
                    } else {
                        countLetters[Ri[0]] = 1;
                    }
                }
            }
            map<int, char> countLettersReverse;
            for (pair<char, int> letra : countLetters) {
                countLettersReverse[letra.second] = letra.first;
            }
            int i = 9;
            string result = "0123456789";
            for (pair<int, char> letra : countLettersReverse) {
                result[i] = letra.second;
                --i;
            }
            bool isZero;
            for (char c : allLetters) {
                isZero = true;
                for (int i = 1; i <= 9; ++i) {
                    if (result[i] == c) {
                        isZero = false;
                    }
                }
                if (isZero) {
                    result[0] = c;
                }
            }
            cout << "Case #" << t << ": " << result << "\n";
        } else if (U == 2) {
            map<char, int> countLetters;
            for (int i = 1; i < 10000; ++i) {
                cin >> Qi >> Ri;
                for (char r : Ri) {
                    if (countLetters.count(r)) {
                        countLetters[r]++;
                    } else {
                        countLetters[r] = 1;
                    }
                }
            }
            map<int, char> countLettersReverse;
            for (pair<char, int> letra : countLetters) {
                countLettersReverse[letra.second] = letra.first;
            }
            int i = 10;
            string result = "0123456789";
            for (pair<int, char> letra : countLettersReverse) {
                result[i % 10] = letra.second;
                --i;
            }
            cout << "Case #" << t << ": " << result << "\n";
        } else {
            set<char> allLetters;
            vector<set<char> > mostSignificativeDigits(10);
            for (int i = 1; i < 10000; ++i) {
                cin >> Qi >> Ri;
                if (allLetters.size() < 10) {
                    for (char r : Ri) {
                        allLetters.insert(r);
                    }
                }
                if (numberOfDigits(Qi) == Ri.size()) {
                    mostSignificativeDigits[mostSignificativeDigit(Qi)].insert(Ri[0]);
                }
            }
            string result = "0123456789";
            bool alreadyInResult;
            for (int i = 1; i <= 9; ++i) {
                for (char c : mostSignificativeDigits[i]) {
                    alreadyInResult = false;
                    for (int j = 1; j < i; ++j) {
                        if (result[j] == c) {
                            alreadyInResult = true;
                        }
                    }
                    if (not alreadyInResult) {
                        result[i] = c;
                    }
                }
            }
            for (char c : allLetters) {
                alreadyInResult = false;
                for (int j = 1; j <= 9; ++j) {
                    if (result[j] == c) {
                        alreadyInResult = true;
                    }
                }
                if (not alreadyInResult) {
                    result[0] = c;
                }
            }
            cout << "Case #" << t << ": " << result << "\n";
        }
    }
}
