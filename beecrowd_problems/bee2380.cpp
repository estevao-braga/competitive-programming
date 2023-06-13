#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int father[MAXN], qnt[MAXN];

void build(int n) {
    for (int i = 1; i <= n; father[i] = i, qnt[i] = 1, i++);
}

int _find(int x) {
    if (x == father[x]) return x;
    return father[x] = _find(father[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if (qnt[x] > qnt[y]) {
        father[y] = x;
        qnt[x] += qnt[y];
        return;
    }
    father[x] = y;
    qnt[y] += qnt[x]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    build(n);
    char op;
    int b1, b2;

    while (k--) {
        cin >> op >> b1 >> b2;

        if (op == 'C') {
            if (_find(b1) == _find(b2)) cout << "S\n";
            else cout << "N\n";
            continue;
        }

        _union(b1, b2);
    }

    return 0;
}