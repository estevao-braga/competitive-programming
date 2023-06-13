#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int father[MAXN], level[MAXN], wins[MAXN];

void build(int n) {
    for (int i = 1; i <= n; father[i] = i, level[i] = 0, wins[i] = 0, i++);
}

int _find(int x) {
    if (x == father[x]) return x;
    return father[x] = _find(father[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if (x == y) return;

    father[y] = x;
    level[x] += level[y];
    wins[x] += wins[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        build(n);
        for (int i = 1; i <= n; cin >> level[i++]);
        int q, a, b, ans = 0;
        while (m--) {
            cin >> q >> a >> b;
            if (q == 1) _union(a, b);
            else {
                a = _find(a);
                b = _find(b);
                if (level[a] > level[b]) {
                    wins[a]++;
                    if (a == _find(1)) ans++;
                }
                else if (level[a] < level[b]) {
                    wins[b]++; 
                    if (b == _find(1)) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}