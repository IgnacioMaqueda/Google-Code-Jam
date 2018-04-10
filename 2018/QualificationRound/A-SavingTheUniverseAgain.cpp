#include <iostream>
#include <vector>
using namespace std;

int calculateDamage(string &instructions) {
    int result = 0;
    int strength = 1;
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i] == 'S') {
            result += strength;
        } else {
            strength *= 2;
        }
    }
    return result;
}

void minHacksRecursive(string &instructions, int damage, int currentDamage, int hacks, vector<int> &possibleHacks) {
    string instsModified;
    int strength = 1;
    if (currentDamage <= damage) {
        possibleHacks.push_back(hacks);
    } else {
        for (int i = 0; i < instructions.size() - 1; i++) {
            if (instructions[i] == 'C') {
                strength *= 2;
            }
            if (instructions[i] == 'C' and instructions[i + 1] == 'S') {
                instsModified = instructions;
                instsModified[i] = 'S';
                instsModified[i + 1] = 'C';
                minHacksRecursive(instsModified, damage, currentDamage - (strength / 2), hacks + 1, possibleHacks);
            }
        }
    }
}

int numberOfShots(string &instructions) {
    int res = 0;
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i] == 'S') {
            res++;
        }
    }
    return res;
}

int minimum(vector<int> &v) {
    int res = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < res) {
            res = v[i];
        }
    }
    return res;
}

void minimumHacks(string &instructions, int damage) {
    vector<int> possibleHacks;
    if (numberOfShots(instructions) > damage) {
        cout << "IMPOSSIBLE";
    } else {
        int currentDamage = calculateDamage(instructions);
        minHacksRecursive(instructions, damage, currentDamage, 0, possibleHacks);
        int minHacks = minimum(possibleHacks);
        cout << minHacks;
    }
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    string instructions;
    int damage;

    for (int i = 0; i < numberOfTestCases; i++) {
        cin >> damage;
        cin >> instructions;
        cout << "Case #" << i + 1 << ": ";
        minimumHacks(instructions, damage);
        cout << endl;
        instructions.clear();
    }
    return 0;
}
