/**
 * https://codeforces.com/contest/1807/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int mihai = 0, bianca = 0;

    while (n--) {
        int i;
        cin >> i;

        if (i & 1) {
            bianca += i;
            continue;
        }

        mihai += i;
    }

    if (mihai > bianca) {
        cout << "YES\n";
        return;
    } 
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}