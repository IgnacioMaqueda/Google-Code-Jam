#include <bits/stdc++.h>

using namespace std;

void calcularTodos(set<string> &todos) {
    todos.insert("ABCD");
    todos.insert("ABCE");
    todos.insert("ABDC");
    todos.insert("ABDE");
    todos.insert("ABEC");
    todos.insert("ABED");
    todos.insert("ACBD");
    todos.insert("ACBE");
    todos.insert("ACDB");
    todos.insert("ACDE");
    todos.insert("ACEB");
    todos.insert("ACED");
    todos.insert("ADBC");
    todos.insert("ADBE");
    todos.insert("ADCB");
    todos.insert("ADCE");
    todos.insert("ADEB");
    todos.insert("ADEC");
    todos.insert("AEBC");
    todos.insert("AEBD");
    todos.insert("AECB");
    todos.insert("AECD");
    todos.insert("AEDB");
    todos.insert("AEDC");
    todos.insert("BACD");
    todos.insert("BACE");
    todos.insert("BADC");
    todos.insert("BADE");
    todos.insert("BAEC");
    todos.insert("BAED");
    todos.insert("BCAD");
    todos.insert("BCAE");
    todos.insert("BCDA");
    todos.insert("BCDE");
    todos.insert("BCEA");
    todos.insert("BCED");
    todos.insert("BDAC");
    todos.insert("BDAE");
    todos.insert("BDCA");
    todos.insert("BDCE");
    todos.insert("BDEA");
    todos.insert("BDEC");
    todos.insert("BEAC");
    todos.insert("BEAD");
    todos.insert("BECA");
    todos.insert("BECD");
    todos.insert("BEDA");
    todos.insert("BEDC");
    todos.insert("CABD");
    todos.insert("CABE");
    todos.insert("CADB");
    todos.insert("CADE");
    todos.insert("CAEB");
    todos.insert("CAED");
    todos.insert("CBAD");
    todos.insert("CBAE");
    todos.insert("CBDA");
    todos.insert("CBDE");
    todos.insert("CBEA");
    todos.insert("CBED");
    todos.insert("CDAB");
    todos.insert("CDAE");
    todos.insert("CDBA");
    todos.insert("CDBE");
    todos.insert("CDEA");
    todos.insert("CDEB");
    todos.insert("CEAB");
    todos.insert("CEAD");
    todos.insert("CEBA");
    todos.insert("CEBD");
    todos.insert("CEDA");
    todos.insert("CEDB");
    todos.insert("DABC");
    todos.insert("DABE");
    todos.insert("DACB");
    todos.insert("DACE");
    todos.insert("DAEB");
    todos.insert("DAEC");
    todos.insert("DBAC");
    todos.insert("DBAE");
    todos.insert("DBCA");
    todos.insert("DBCE");
    todos.insert("DBEA");
    todos.insert("DBEC");
    todos.insert("DCAB");
    todos.insert("DCAE");
    todos.insert("DCBA");
    todos.insert("DCBE");
    todos.insert("DCEA");
    todos.insert("DCEB");
    todos.insert("DEAB");
    todos.insert("DEAC");
    todos.insert("DEBA");
    todos.insert("DEBC");
    todos.insert("DECA");
    todos.insert("DECB");
    todos.insert("EABC");
    todos.insert("EABD");
    todos.insert("EACB");
    todos.insert("EACD");
    todos.insert("EADB");
    todos.insert("EADC");
    todos.insert("EBAC");
    todos.insert("EBAD");
    todos.insert("EBCA");
    todos.insert("EBCD");
    todos.insert("EBDA");
    todos.insert("EBDC");
    todos.insert("ECAB");
    todos.insert("ECAD");
    todos.insert("ECBA");
    todos.insert("ECBD");
    todos.insert("ECDA");
    todos.insert("ECDB");
    todos.insert("EDAB");
    todos.insert("EDAC");
    todos.insert("EDBA");
    todos.insert("EDBC");
    todos.insert("EDCA");
    todos.insert("EDCB");
}

void agregarUltima(string &s) {
    vector<int> apariciones(5);
    for (char c : s) {
        apariciones[c - 'A']++;
    }
    for (int i = 0; i < apariciones.size(); ++i) {
        if (apariciones[i] == 0) {
            s.push_back('A' + i);
        }
    }
}

void borrarEmpiezaCon(set<string> &todos, char letra) {
    for (auto palabra : todos) {
        if (palabra[0] == letra) {
            todos.erase(palabra);
        }
    }
}

int main() {
    int T, F;
    char letra;
    cin >> T >> F;
    for (int i = 0; i < T; ++i) {
        set<string> todos;
        calcularTodos(todos);
        vector<int> comienzos(5);
        for (int j = 0; j < 119; ++j) {
            string actual;
            cout << j * 5 + 1 << endl;
            cin >> letra;
            actual.push_back(letra);
            comienzos[letra - 'A']++;
            if (comienzos[letra - 'A'] == 24) {
                borrarEmpiezaCon(todos, letra);
            } else {
                for (int k = 1; k < 4; ++k) {
                    cout << j * 5 + k + 1 << endl;
                    cin >> letra;
                    actual.push_back(letra);
                }
                todos.erase(actual);
            }
        }
        string s = *todos.begin();
        agregarUltima(s);
        cout << s << endl;
        cin >> letra;
    }
    return 0;
}
