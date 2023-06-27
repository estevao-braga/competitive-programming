#include <bits/stdc++.h>
using namespace std;

int hashFunction(int key, int t) {
    return key % t;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;

        vector<list<int>> hashTable(t);

        // Inserção das chaves na tabela hash
        for (int j = 0; j < c; ++j) {
            int key;
            cin >> key;
            int index = hashFunction(key, t);
            hashTable[index].push_back(key);
        }

        // Impressão dos resultados
        for (int j = 0; j < t; ++j) {
            cout << j << " -> ";
            for (int key : hashTable[j]) {
                cout << key << " -> ";
            }
            cout << "\\" << endl;
        }

        if (i < n - 1) {
            cout << endl;
        }
    }

    return 0;
}