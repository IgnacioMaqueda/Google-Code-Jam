#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void evacuationPlan(vector<pair<int, char> > senators) {
    int evacuateds = 0;
    int toEvacuate = 0;
    for (int i = 0; i < senators.size(); i++) {
        toEvacuate += senators[i].first;
    }
    while (evacuateds < toEvacuate - 3) {
        sort(senators.begin(), senators.end());
        if (senators[senators.size() - 1].first == senators[senators.size() - 2].first) {
            cout << " " << senators[senators.size() - 2].second << senators[senators.size() - 1].second;
            senators[senators.size() - 1].first--;
            senators[senators.size() - 2].first--;
            evacuateds += 2;
        } else {
            cout << " " << senators[senators.size() - 1].second;
            senators[senators.size() - 1].first--;
            evacuateds++;
        }
    }
    if (evacuateds == toEvacuate - 3) {
        sort(senators.begin(), senators.end());
        cout << " " << senators[senators.size() - 3].second << " " << senators[senators.size() - 2].second << senators[senators.size() - 1].second;
    } else {
        sort(senators.begin(), senators.end());
        cout << " " << senators[senators.size() - 2].second << senators[senators.size() - 1].second;
    }
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    int numberOfParties;
    vector<pair<int, char> > senators;
    int senatorsPartyN;
    char party;
    pair<int, char> senatorsAndParty;

    for (int i = 0; i < numberOfTestCases; i++) {
        cin >> numberOfParties;
        party = 'A';
        for (int j = 0; j < numberOfParties; j++) {
            cin >> senatorsPartyN;
            senators.push_back(make_pair(senatorsPartyN,party));
            party++;
        }
        cout << "Case #" << i + 1 << ":";
        evacuationPlan(senators);
        cout << endl;
        senators.clear();
    }
    return 0;
}
