#include <bits/stdc++.h>

using namespace std;

string addParentheses(string &S) {
    list<char> listS;
    for (char s : S) {
        listS.push_back(s);
    }

    auto it0 = listS.begin();
    auto it1 = it0;
    while (it0 != listS.end()) {
        ++it1;
        listS.insert(it0, (*it0) - '0', '(');
        listS.insert(it1, (*it0) - '0', ')');
        it0 = it1;
    }

    it0 = listS.begin();
    it1 = it0;
    ++it1;
    while (it1 != listS.end()) {
        if ((*it0) == ')' and (*it1) == '(') {
            it0 = listS.erase(it0);
            --it0;
            it1 = listS.erase(it1);
        } else {
            ++it0;
            ++it1;
        }
    }

    string res;
    for (char &s : listS) {
        res.push_back(s);
    }
    return res;
}

int main() {
    int T;
    string S;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        cout << "Case #" << t << ": " << addParentheses(S) << "\n";
    }
    return 0;
}
