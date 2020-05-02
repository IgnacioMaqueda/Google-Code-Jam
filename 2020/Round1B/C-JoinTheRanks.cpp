#include <bits/stdc++.h>

using namespace std;

void printVector(vector<pair<int, int> > &solutionRS) {
    for (auto & op : solutionRS) {
        cout << op.first << " " << op.second << "\n";
    }
}

int main() {
    int T, R, S;
    vector<vector<vector<pair<int, int> > > > solution(6, vector<vector<pair<int, int> > >(8));
    solution[2][2] = {{2, 1}};
    solution[2][3] = {{4, 1}, {3, 1}};
    solution[2][4] = {{6, 1}, {5, 1}, {4, 1}};
    solution[2][5] = {{8, 1}, {7, 1}, {6, 1}, {5, 1}};
    solution[2][6] = {{10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}};
    solution[2][7] = {{12, 1}, {11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}};
    solution[3][2] = {{3, 2}, {2, 1}};
    solution[3][3] = {{2, 2}, {3, 3}, {4, 4}};
    solution[3][4] = {{2, 2}, {3, 3}, {4, 4}, {6, 4}, {3, 8}};
    solution[4][2] = {{2, 3}, {2, 5}};
    solution[4][3] = {{2, 3}, {2, 5}, {4, 5}, {4, 7}};
    solution[5][2] = {{2, 4}, {2, 6}, {1, 8}};
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> S;
        cout << "Case #" << t << ": " << solution[R][S].size() << "\n";
        printVector(solution[R][S]);
    }
}
