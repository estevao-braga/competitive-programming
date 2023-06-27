#include <bits/stdc++.h>
using namespace std;

int h(string& input, int j) {
    int hash = 0;
    for (int i = 0; i < input.length(); ++i) {
        hash += (input[i] - 'A') + j + i;
    }
    return hash;
}

int main() {

    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        int numLines;
        cin >> numLines;

        int totalHash = 0;

        for (int j = 0; j < numLines; ++j) {
            string input;
            cin >> input;
            totalHash += h(input, j);
        }

        cout << totalHash << endl;
    }

    return 0;
}