#include <bits/stdc++.h>

using namespace std;

int numberOfMinutes(int X, int Y, string &M) {
    int minutes = 0;
    while (minutes < M.size()) {
        if (M[minutes] == 'S') {
            Y--;
        } else if (M[minutes] == 'N') {
            Y++;
        } else if (M[minutes] == 'E') {
            X++;
        } else {
            X--;
        }
        minutes++;
        if (abs(X) + abs(Y) <= minutes) {
            return minutes;
        }
    }
    return 0;
}

int main() {
    int T, X, Y, result;
    string M;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
    		cin >> X >> Y;
    		cin >> M;
    		result = numberOfMinutes(X, Y, M);
    		if (result > 0) {
            cout << "Case #" << t << ": " << result << "\n";
    		} else {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
    		}
    }
}
