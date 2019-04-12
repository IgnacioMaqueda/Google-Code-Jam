#include <bits/stdc++.h>

using namespace std;

void caso20() {
    int I, J;
    for (int i = 0; i < 1000; ++i) {
        printf("%d %d\n", 2, (i % 5) + 2);
        fflush(stdout);
        scanf("%d %d", &I, &J);
        if (I == 0) {
            break;
        }
    }
}

void caso200() {
    int I, J;
    for (int i = 0; i < 1000; ++i) {
        printf("%d %d\n", 2, (i % 67) + 2);
        fflush(stdout);
        scanf("%d %d", &I, &J);
        if (I == 0) {
            break;
        }
    }
}

int main() {
    int T, A;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A;
        if (A == 20) {
            caso20();
        } else {
            caso200();
        }
    }
    return 0;
}
