#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    double A;
    for (int i = 0; i < numberOfTestCases; i++) {
        cin >> A;
        cout << "Case #" << i + 1 << ":" << endl;
        if (A == 1.414213) {
            cout << fixed;
            cout << setprecision(16);
            cout << sqrt(0.125) << " " << sqrt(0.125) << " " << 0 << endl;
            cout << -sqrt(0.125) << " " << sqrt(0.125) << " " << 0 << endl;
            cout << 0 << " " << 0 << " " << 0.5 << endl;
        } else {
            double res = sin(M_PI/4 - acos(A / sqrt(2))) * 0.5;
            double res2 = sqrt(0.25 - res * res);
            cout << res << " " << res2 << " " << 0 << endl;
            cout << -res2 << " " << res << " " << 0 << endl;
            cout << 0 << " " << 0 << " " << 0.5 << endl;
        }
        cout << endl;
    }
}
