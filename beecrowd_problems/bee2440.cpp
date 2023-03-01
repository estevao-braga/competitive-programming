/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/2440
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> relatives[N];
int visiteds[N];
int n;

int dfs(int d){
    visiteds[d] = 1;
    for(int i = 0; i < relatives[d].size(); i++){
        if(visiteds[relatives[d][i]] == 0){
            dfs(relatives[d][i]);
        }
    }
}

int notVisited(){
    for(int i = 1; i <= n; i++){
        if(visiteds[i] == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        relatives[a].push_back(b);
        relatives[b].push_back(a);
    }

    int f = 1;
    dfs(1);
    int v = notVisited();
    while(v != -1){
        dfs(v);
        v = notVisited();
        f++;
    }

    cout << f << endl;

    return 0;
}
