#include <bits/stdc++.h>

using namespace std;

int a[1111];
vector<pair<int, int> > cyc;
vector<int> adj[1111];
int n, k;
int dist[1111];
bitset<1111> vis;

void rec(int node) {
	vis[node] = 1;
	cyc.back().second += 1;
	for (int i = 0; i < adj[node].size(); ++i)
		if (!vis[adj[node][i]])
			rec(adj[node][i]);
}

void dfs(int node) {
	if (dist[a[node]] != -1) {
		cyc.push_back({dist[node] - dist[a[node]] + 1, -(dist[node] - dist[a[node]] + 1)});
		rec(node);
		return;
	} else {
		dist[a[node]] = dist[node] + 1;
		dfs(a[node]);
	}
}

int dp[1111][1111];

int calc(int c, int l) {
	if (c == cyc.size()) return 0;
	int &ret = dp[c][l];
	if (ret != -1) return ret;
	ret = calc(c + 1, l);
	for (int i = 0; i <= cyc[c].second; ++i) {
		if (l >= cyc[c].first + i) {
			ret = max(ret, calc(c + 1, l - cyc[c].first - i) + cyc[c].first + i);
		}
	}
	return ret;
}

int main() {
	memset(dist, -1, sizeof dist);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		adj[i].push_back(a[i]);
		adj[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dist[i] = 0;
			dfs(i);
		}
	}
	
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(0, k));
	return 0;
}