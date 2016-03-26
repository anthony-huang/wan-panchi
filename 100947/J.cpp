#include <bits/stdc++.h>

using namespace std;

int n, p, q;
int a[2020];
int np[2020], nq[2020];
int dp[2000][2000];

int calc(int i, int p) {
	if (i == n) return 0;
	int &ret = dp[i][p];
	if (ret != -1) return ret;
	ret = calc(nq[i], p) + 1;
	if (p > 0) ret = min(ret, calc(np[i], p - 1));
	return ret;
}

int calc(int w) {
	np[n - 1] = nq[n - 1] = n;
	for (int i = n - 2, k = n - 1; i >= 0; --i) {
		while (a[k] - a[i] + 1 > w) {
			--k;
		}
		++k;
		np[i] = k;
	}
	for (int i = n - 2, k = n - 1; i >= 0; --i) {
		while (a[k] - a[i] + 1 > (w << 1)) {
			--k;
		}
		++k;
		nq[i] = k;
	}
	memset(dp, -1, sizeof dp);
	return calc(0, min(n, p));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &p, &q);
		a[n] = 2e9;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int lo = 1, hi = 1e9, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int used = calc(mid);
			if (used > q) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
				ans = mid;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}