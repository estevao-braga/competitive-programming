#include <bits/stdc++.h>
using namespace std;

const int INFINITE = 1000;
const int MAXN = 65;
vector<int> adj[MAXN];
int dist[MAXN], used[MAXN];

void restart() {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INFINITE;
        used[i] = 0;
    }
}

bool compare(int x, int y) {
    return dist[x] > dist[y];
}

void dijkstra(int vertex) {
    restart();
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(compare);

    dist[vertex] = 0;
    pq.push(vertex);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        if (!used[u]) {
            used[u] = 1;
            for (int v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.push(v);
                }
            }
        }
    }
}

int getPos(string str) {
    int line = 7 - (str[1] - '1');
    int column = (int)str[0] - 'a';
    return line * 8 + column;
}

void buildAdj() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pos = i * 8 + j;
            int possiblePos;

            if (i - 2 >= 0) {
                if (j - 1 >= 0) {
                    possiblePos = ((i - 2) * 8) + j - 1;
                    adj[pos].push_back(possiblePos);
                }
                if (j + 1 < 8) {
                    possiblePos = ((i - 2) * 8) + j + 1;
                    adj[pos].push_back(possiblePos);
                }
            }

            if (i - 1 >= 0) {
                if (j - 2 >= 0) {
                    possiblePos = ((i - 1) * 8) + j - 2;
                    adj[pos].push_back(possiblePos);
                }
                if (j + 2 < 8) {
                    possiblePos = ((i - 1) * 8) + j + 2;
                    adj[pos].push_back(possiblePos);
                }
            }

            if (i + 1 < 8) {
                if (j - 2 >= 0) {
                    possiblePos = ((i + 1) * 8) + j - 2;
                    adj[pos].push_back(possiblePos);
                }
                if (j + 2 < 8) {
                    possiblePos = ((i + 1) * 8) + j + 2;
                    adj[pos].push_back(possiblePos);
                }
            }

            if (i + 2 < 8) {
                if (j - 1 >= 0) {
                    possiblePos = ((i + 2) * 8) + j - 1;
                    adj[pos].push_back(possiblePos);
                }
                if (j + 1 < 8) {
                    possiblePos = ((i + 2) * 8) + j + 1;
                    adj[pos].push_back(possiblePos);
                }
            }
        }
    }
}

int main() {
    buildAdj();
    string source, dest;

    while (cin >> source >> dest) {
        dijkstra(getPos(source));
        cout << "To get from " << source << " to " << dest << " takes " << dist[getPos(dest)] << " knight moves.\n";
    }

    return 0;
}