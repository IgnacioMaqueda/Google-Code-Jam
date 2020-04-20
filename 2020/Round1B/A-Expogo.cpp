#include <bits/stdc++.h>

using namespace std;

void flipX(string &jumps) {
    for (char &jump : jumps) {
        if (jump == 'E') {
            jump = 'W';
        } else if (jump == 'W') {
            jump = 'E';
        }
    }
}

void flipY(string &jumps) {
    for (char &jump : jumps) {
        if (jump == 'N') {
            jump = 'S';
        } else if (jump == 'S') {
            jump = 'N';
        }
    }
}

bool canReachGoal(int X, int Y, string &jumps) {
    string binX = bitset<32>(X).to_string();
    string binY = bitset<32>(Y).to_string();
    int j;
    int totalOnes = 0;
    for (int i = 0; i < 32; ++i) {
        totalOnes += binX[i] - '0';
        totalOnes += binY[i] - '0';
    }
    int i = 31;
    while (totalOnes > 0) {
        if (binX[i] == binY[i]) {
            return false;
        } else if (totalOnes == 1) {
            if (binX[i] == '1') {
                binX[i] = '0';
                totalOnes--;
                jumps.push_back('E');
            } else {
                binY[i] = '0';
                totalOnes--;
                jumps.push_back('N');
            }
        } else if (binX[i - 1] == binY[i - 1]) {
            if (binX[i] == '1') {
                j = i;
                while (binX[j] == '1') {
                    binX[j] = '0';
                    totalOnes--;
                    j--;
                }
                binX[j] = '1';
                totalOnes++;
                jumps.push_back('W');
            } else {
                j = i;
                while (binY[j] == '1') {
                    binY[j] = '0';
                    totalOnes--;
                    j--;
                }
                binY[j] = '1';
                totalOnes++;
                jumps.push_back('S');
            }
        } else {
            if (binX[i] == '1') {
                binX[i] = '0';
                totalOnes--;
                jumps.push_back('E');
            } else {
                binY[i] = '0';
                totalOnes--;
                jumps.push_back('N');
            }
        }
        i--;
    }

    return true;
}

int main() {
    int T, X, Y;
    bool flippedY, flippedX;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> X >> Y;
        string jumps;
        if (X < 0) {
            flippedX = true;
            X = -X;
        } else {
            flippedX = false;
        }
        if (Y < 0) {
            flippedY = true;
            Y = -Y;
        } else {
            flippedY = false;
        }
        if (canReachGoal(X, Y, jumps)) {
            if (flippedX) {
                flipX(jumps);
            }
            if (flippedY) {
                flipY(jumps);
            }
            cout << "Case #" << t << ": " << jumps << "\n";
        } else {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        }
    }
}
