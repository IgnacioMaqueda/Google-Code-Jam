#include <bits/stdc++.h>

using namespace std;

const int S = 1000000000;

int main() {
    int T, A, B;
    string answer;
    cin >> T >> A >> B;
    if (A == S - 5) {
        for (int t = 0; t < T; ++t) {
            for (int x = -5; x <= 5; ++x) {
                for (int y = -5; y <= 5; ++y) {
                    cout << x << " " << y << "\n";
                    cin >> answer;
                    if (answer == "CENTER") {
                        break;
                    }
                }
                if (answer == "CENTER") {
                    break;
                }
            }
        }
    } else if (A == S - 50) {
        for (int t = 0; t < T; ++t) {
            int x = S;
            while (true) {
                cout << x << " " << 0 << "\n";
                cin >> answer;
                if (answer == "HIT") {
                    break;
                }
                x--;
            }
            int y = S;
            while (true) {
                cout << 0 << " " << y << "\n";
                cin >> answer;
                if (answer == "HIT") {
                    break;
                }
                y--;
            }
            x -= A;
            y -= A;
            for (int i = x - 5; i <= x + 5; ++i) {
                for (int j = y - 5; j <= y + 5; ++j) {
                    cout << i << " " << j << "\n";
                    cin >> answer;
                    if (answer == "CENTER") {
                        break;
                    }
                }
                if (answer == "CENTER") {
                    break;
                }
            }
        }
    } else {

    }
}
