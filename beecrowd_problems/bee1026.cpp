#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int n1, n2;
    while (cin >> n1 >> n2) {
        unsigned int c = n1^n2;
        cout << c << endl;
    }

    return 0;
}