/**
 * https://codeforces.com/contest/1714/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n, h, m;
		cin >> n >> h >> m;
		int x = h*60 + m;
		vector<pair<int, int>> horarios;

		while (n--) {
			int hi, mi;
			cin >> hi >> mi;
			int xi = hi*60 + mi;
			if (xi < x) xi += 24*60;
			xi -= x;
			horarios.push_back({xi/60, xi%60});
		}
		sort(horarios.begin(), horarios.end());
		cout << horarios[0].first << ' ' << horarios[0].second << endl;
	}

	return 0;
}
