#include <bits/stdc++.h>

using namespace std;

string assignActivities(const vector<pair<pair<int, int>, int> > &activities, const int N) {
    string resAux;
    int freeC = 0;
    int freeJ = 0;
    for (int i = 0; i < N; ++i) {
        if (freeC <= activities[i].first.first) {
            freeC = activities[i].first.second;
            resAux.push_back('C');
        } else if (freeJ <= activities[i].first.first) {
            freeJ = activities[i].first.second;
            resAux.push_back('J');
        } else {
            return "IMPOSSIBLE";
        }
    }
    string res = resAux;
    for (int i = 0; i < N; ++i) {
        res[activities[i].second] = resAux[i];
    }
    return res;
}

int main() {
    int T, N, Si, Ei;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<pair<pair<int, int>, int> > activities(N);
        for (int i = 0; i < N; ++i) {
            cin >> Si >> Ei;
            activities[i] = {{Si, Ei}, i};
        }
        sort(activities.begin(), activities.end());
        cout << "Case #" << t << ": " << assignActivities(activities, N) << "\n";
    }
    return 0;
}
