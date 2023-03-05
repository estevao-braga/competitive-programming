/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1152
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 * 2 + 10;
int pai[MAXN], qtd[MAXN];

void _build(int n) {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        qtd[i] = 1;
    }
}

int _find(int x) {
    if(x == pai[x]) return x;
    return pai[x] = _find(pai[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
 
    if (x == y) return;
        
    if (qtd[x] > qtd[y]) {
        qtd[x] += qtd[y];
        pai[y] = x;
    } else {
        qtd[y] += qtd[x];
        pai[x] = y;
    }
}

int main() {
    while (true) { 

        int m, n, tot = 0;
        cin >> m >> n;

        if(m == 0 && n == m) break;

        _build(m);

        vector<pair<int, pair<int, int>>> estradas;

        int x,y,z;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            tot += z;
            estradas.push_back({z, {x,y}});
        }

        int iluminada = 0;
    
        sort(estradas.begin(), estradas.end());

        for (int i = 0; i  < estradas.size(); i++) {
            x = estradas[i].second.first;
            y = estradas[i].second.second;

            if (_find(x) != _find(y)) {
                _union(x,y);
                iluminada += estradas[i].first;
            }
        }

        cout << tot - iluminada << endl;
    }
    return 0;
}