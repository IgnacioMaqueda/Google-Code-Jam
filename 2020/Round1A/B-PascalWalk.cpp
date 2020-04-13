#include <bits/stdc++.h>

using namespace std;

void findPascalWalk(const int N, vector<pair<int, int> > &pascalWalk) {
    for (int i = 2; i <= (N + 1) / 2; ++i) {
        pascalWalk.emplace_back(i, 1);
    }
    pascalWalk.emplace_back(N / 2 + 1, 2);
}

void findSpecialPascalWalk(const int N, vector<pair<int, int> > &pascalWalk) {
    pascalWalk.emplace_back(2, 1);
    pascalWalk.emplace_back(3, 1);
    pascalWalk.emplace_back(4, 1);
    pascalWalk.emplace_back(5, 2);
    for (int i = 5; i <= (N + 1) / 2; ++i) {
        pascalWalk.emplace_back(i, 1);
    }
    pascalWalk.emplace_back(N / 2 + 1, 2);
}

void printPascalWalk(vector<pair<int, int> > &pascalWalk) {
    for (auto & pos : pascalWalk) {
        cout << pos.first << " " << pos.second << "\n";
    }
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "Case #" << t << ": \n";
        vector<pair<int, int> > pascalWalk = {{1, 1}};
        if (N > 1 and N < 999) {
            findPascalWalk(N, pascalWalk);
        } else if (N >= 999) {
            findSpecialPascalWalk(N - 4, pascalWalk);
        }
        printPascalWalk(pascalWalk);
    }
}
