#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> point;
typedef long long ll;

point p[1111];
int n;
double cost[1111][1111];
double dp[1111][1111];

ll cross(point o, point a, point b) {
	return (ll) (a.x - o.x) * (b.y - o.y) - (ll) (a.y - o.y) * (b.x - o.x);
}

double calc(int l, int r) {
	if (l == n) return 0.0;
	if (r == n) return 1e15;
	double &ret = dp[l][r];
	if (ret == ret) return ret;
	ret = calc(l, r + 1);
	if (r - l > 0) ret = min(ret, calc(r + 1, r + 1) + cost[l][r]);
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		for (int i = 0; i < n; ++i) {
			vector<int> v;
			v.push_back(i);
			int k = 1;
			double c = 0.0;
			for (int j = i + 1; j < n; ++j) {
				while (k > 1 && cross(p[v[k - 2]], p[v[k - 1]], p[j]) > 0) {
					c -= hypot(p[v[k - 2]].x - p[v[k - 1]].x, p[v[k - 2]].y - p[v[k - 1]].y);
					v.pop_back();
					--k;
				}
				cost[i][j] = c += hypot(p[v.back()].x - p[j].x, p[v.back()].y - p[j].y);
				v.push_back(j);
				++k;
			}
		}
		memset(dp, -1, sizeof dp);
		printf("%.6lf\n", calc(0, 0));
	}
	return 0;
}