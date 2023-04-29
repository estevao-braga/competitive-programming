/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1194
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e3 + 10;
char A[MAXN];
string pre, inf;

int pai(int i) {
    return i/2;
}

int filho_esquerdo(int i) {
    return 2*i;
}

int filho_direita(int i) {
    return 2*i+1;
}

bool posicao_relativa(char r, char c) {
    int pos_c, pos_r;
    for (int i = 0; i < inf.size(); i++) {
        if (r == inf[i]) pos_r = i;
        else if (c == inf[i]) pos_c = i;
    }
    // true -> esquerda, false -> direita
    return pos_c - pos_r < 0;
}

void adiciona(char c) {
    int r = 1;

    while (true) {
        if (posicao_relativa(A[r], c)){
            if (A[filho_esquerdo(r)] != '0') {
                r = filho_esquerdo(r);
                continue;
            }
            A[filho_esquerdo(r)] = c;
            break;
        } else {
            if (A[filho_direita(r)] != '0') {
                r = filho_direita(r);
                continue;
            }
            A[filho_direita(r)] = c;
            break;
        }
    }
}

void posfixa(int n) {
    if (A[n] == '0') return;
    posfixa(filho_esquerdo(n));
    posfixa(filho_direita(n));
    cout << A[n];
}

void solve() {

    int n;
    pre.clear();
    inf.clear();
    memset(A, '0', MAXN*sizeof(char));

    cin >> n >> pre >> inf;

    for (int i = 0; i < pre.size(); i++) {
        if (i == 0) {
            A[1] = pre[i];
            continue;
        }
        adiciona(pre[i]);
    }
    posfixa(1);
    cout << "\n";
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