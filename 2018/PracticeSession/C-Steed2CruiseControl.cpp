#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void maximumCruiseSpeed(int destination, vector<pair<double , double> > horses) {
    double maxTime = 0;
    double timeHorseN;
    for (int i = 0; i < horses.size(); i++) {
        timeHorseN = (destination - horses[i].first) / horses[i].second;
        if (timeHorseN > maxTime) {
            maxTime = timeHorseN;
        }
    }
    double maxSpeed = destination / maxTime;
    cout << fixed;
    cout << setprecision(6);
    cout << maxSpeed;
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    double destination;
    int numberOfHorses;
    vector<pair<double, double> > horses;
    double initialPosition;
    double maximumSpeed;

    for (int i = 0; i < numberOfTestCases; i++) {
        cin >> destination;
        cin >> numberOfHorses;
        for (int j = 0; j < numberOfHorses; j++) {
            cin >> initialPosition;
            cin >> maximumSpeed;
            horses.push_back(make_pair(initialPosition,maximumSpeed));
        }
        cout << "Case #" << i + 1 << ": ";
        maximumCruiseSpeed(destination, horses);
        cout << endl;
        horses.clear();
    }
    return 0;
}
