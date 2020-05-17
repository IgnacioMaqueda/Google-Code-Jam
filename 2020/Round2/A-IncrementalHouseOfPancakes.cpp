#include <bits/stdc++.h>

using namespace std;

int customersServed(int &L, int &R) {
    int customer = 1;
    while (customer <= L or customer <= R) {
        if (L >= R) {
            L -= customer;
        } else {
            R -= customer;
        }
        ++customer;
    }
    return customer - 1;
}

int main() {
    int T, L, R;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> L >> R;
        int res = customersServed(L, R);
        cout << "Case #" << t << ": " << res << " " << L << " " << R << "\n";
    }
}
