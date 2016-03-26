#include <bits/stdc++.h>

using namespace std;

int n, m;
char g[111][111];

bool vis[111][111];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		queue<pair<int, int> > q;
		memset(vis, 0, sizeof vis);
		int sally = 0, co = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", g[i]);
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '*') {
					vis[i][j] = 1;
					++co;
					q.push(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == 'S') {
					vis[i][j] = 1;
					++sally;
					q.push(make_pair(i, j));
				} else if (g[i][j] == '#') {
					vis[i][j] = 1;
				}
			}
		}
		bool can = false;
		while (sally > 0) {
			vector<pair<int, int> > v;
			vector<pair<int, int> > cock;
			for (int i = 0; i < co; ++i) {
				pair<int, int> u = q.front();
				q.pop();
				cock.push_back(u);
			}
			if (can) break;
			for (int i = 0; i < sally; ++i) {
				pair<int, int> u = q.front();
				if (g[u.first][u.second] == 'X') {
					can = true;
					break;
				}
				q.pop();
				v.push_back(u);
			}
			co = sally = 0;
			for (int i = 0; i < cock.size(); ++i) {
				int x = cock[i].first, y = cock[i].second;
				for (int j = 0; j < 4; ++j) {
					int r = x + dx[j], c = y + dy[j];
					if (r < 0 || r == n || c < 0 || c == m || vis[r][c]) continue;
					vis[r][c] = 1;
					q.push(make_pair(r, c));
					++co;
				}
			}
			for (int i = 0; i < v.size(); ++i) {
				int x = v[i].first, y = v[i].second;
				for (int j = 0; j < 4; ++j) {
					int r = x + dx[j], c = y + dy[j];
					if (r < 0 || r == n || c < 0 || c == m || vis[r][c]) continue;
					vis[r][c] = 1;
					q.push(make_pair(r, c));
					++sally;
				}
			}
		}
		if (can) puts("yes");
		else puts("no");
	}
	return 0;
}