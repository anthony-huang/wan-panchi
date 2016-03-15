#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > adj[100010];
int n, m, k;
int dist[100010];
const int MX = 2e9 + 1e5;

bool can(int w) {
	for (int i = 2; i <= n; ++i)
		dist[i] = MX;
	priority_queue<pair<int, int> > pq;
	pq.push({0, 1});

	while (!pq.empty()) {
		pair<int, int> u = pq.top();
		pq.pop();
		if (dist[u.second] == -u.first) {
			for (pair<int, pair<int, int> > v : adj[u.second]) {
				int tmp = -u.first + v.second.first;
				if (v.second.second <= w && dist[v.first] > tmp && tmp < k) {
					dist[v.first] = tmp;
					pq.push({-dist[v.first], v.first});
				}
			}
		}
	}

	return dist[n] != MX;
}

int main() {
	int t, c, w, s1, s2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		int r = 0;
		while (m--) {
			scanf("%d %d %d %d", &s1, &s2, &c, &w);
			adj[s1].push_back({s2, {c, w}});
			adj[s2].push_back({s1, {c, w}});
			r = max(r, w);
		}
		int l = 1;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (can(mid)) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}