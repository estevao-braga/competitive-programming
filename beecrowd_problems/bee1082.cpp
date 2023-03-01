/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1082
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 27;
vector<int> adj[MAXN];
bool used[MAXN];
vector<char> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(static_cast<char>(v + 'a'));
    for (int vertex: adj[v]) {
        if (!used[vertex]) {
            dfs(vertex);
        }
    }
}

void solve(int n) {
    for (size_t i = 0; i < MAXN; used[i] = false, i++);
    int comps = 0;
    for (size_t i = 0;i < n; i++) {
        if (!used[i]) {
            comps++;
            comp.clear();
            dfs(i);
            sort(comp.begin(), comp.end());
            for (char v: comp) {
                cout << v << ',';
            }
            cout << '\n';
        }
    }
    cout << comps << ' ' << "connected components\n" << '\n';
}

void build() {
    for (int i = 0; i < MAXN; adj[i++].clear());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int v, e;
        cin >> v >> e;
        build();
        for (int i = 0; i < e; i++) {
            char p, q;
            cin >> p >> q;
            adj[p-'a'].push_back(q-'a');
            adj[q-'a'].push_back(p-'a');
        }
        cout << "Case #" << k << ":" << '\n';
        solve(v);
    }

    return 0;
}