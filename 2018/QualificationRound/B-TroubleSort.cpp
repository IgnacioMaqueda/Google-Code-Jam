#include <iostream>
#include <vector>
using namespace std;

void troubleSort(vector<int> &v) {
    bool swapMade = true;
    int aux;
    while (swapMade) {
        swapMade = false;
        for (int i = 0; i < v.size() - 2; i++) {
            if (v[i] > v[i + 2]) {
                aux = v[i];
                v[i] = v[i + 2];
                v[i + 2] = aux;
                swapMade = true;
            }
        }
    }
}

int firstWrong(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    int n;
    vector<int> v;
    int aux;
    int res;

    for (int i = 0; i < numberOfTestCases; i++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            v.push_back(aux);
        }
        cout << "Case #" << i + 1 << ": ";
        troubleSort(v);
        res = firstWrong(v);
        if (res == -1) {
            cout << "OK";
        } else {
            cout << res;
        }
        cout << endl;
        v.clear();
    }
    return 0;
}
