#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, A, B, N, i, guess;
    string answer;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> A >> B;
        A++;
        B++;
        cin >> N;
        answer = "";
        while (answer != "CORRECT") {
            guess = (A + B) / 2;
            cout << guess << endl;
            cin >> answer;
            if (answer == "TOO_SMALL") {
                A = guess;
            } else if (answer == "TOO_BIG") {
                B = guess;
            }
        }
    }
    return 0;
}
