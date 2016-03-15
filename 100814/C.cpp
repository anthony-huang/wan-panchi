#include <bits/stdc++.h>

using namespace std;

int n, m;
int par[100010];
vector<pair<int, int> > adj[100010];

int find(int i) { return par[i] == i ? i : par[i] = find(par[i]); }

bitset<100010> vis;
int ans[100010];
int q[100010], u[100010], v[100010];
int lvl[100010];
int p[100010][20], mx[100010][20];

void dfs(int node, int from, int l) {
	vis[node] = 1;
	lvl[node] = l;
	for (pair<int, int> v : adj[node]) {
		if (v.first != from && !vis[v.first]) {
			p[v.first][0] = node;
			mx[v.first][0] = v.second;
			dfs(v.first, node, l + 1);
		}
	}
}

void preprocess() {
	for (int k = 1; k < 20; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (p[i][k - 1] != -1) {
				p[i][k] = p[p[i][k - 1]][k - 1];
				mx[i][k] = max(mx[i][k - 1], mx[p[i][k - 1]][k - 1]);
			}
		}
	}
}

int lca(int u, int v) {
	if (lvl[u] < lvl[v]) {
		swap(u, v);
	}
	int ans = 0;
	int lg;
	for (lg = 1; 1 << lg <= lvl[u]; ++lg);
	--lg;
	for (int i = lg; i >= 0; --i) {
		if (lvl[u] - (1 << i) >= lvl[v]) {
			ans = max(ans, mx[u][i]);
			u = p[u][i];
		}
	}
	if (u == v) return ans;
	for (int i = lg; i >= 0; --i)
		if (p[u][i] != -1 && p[u][i] != p[v][i]) {
			ans = max(ans, max(mx[u][i], mx[v][i]));
			u = p[u][i], v = p[v][i];
		}
	if (p[u][0] == -1 || p[v][0] == -1) return -1;
	return max(ans, max(mx[u][0], mx[v][0]));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(p, -1, sizeof p);
		memset(mx, -1, sizeof mx);
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			par[i] = i;
			vis[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d %d", &q[i], &u[i], &v[i]);
			if (q[i] == 1 && find(u[i]) != find(v[i])) {
				adj[u[i]].push_back({v[i], i});
				adj[v[i]].push_back({u[i], i});
				par[find(u[i])] = find(v[i]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				dfs(i, 0, 0);
			}
		}
		preprocess();
		for (int i = m; i >= 1; --i) {
			if (q[i] == 2) {
				if (find(u[i]) == find(v[i])) {
					ans[i] = lca(u[i], v[i]);
					if (ans[i] > i)
						ans[i] = -1;
				}
				else ans[i] = -1;
			}
		}
		for (int i = 1; i <= m; ++i) {
			if (q[i] == 2) {
				printf("%d\n", ans[i]);
			}
		}
	}
	return 0;
}