#include <bits/stdc++.h>

using namespace std;

int n, k;
int p[1000000];

bool can(long long m) {
	int x = k;
	int cnt = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		++cnt;
		mx = max(mx, p[i]);
		if ((long long) mx * cnt > m) {
			--x;
			cnt = 1;
			mx = p[i];
		}
	}
	return x > 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			mx = max(mx, p[i]);
		}
		long long l = mx, r = (long long) n * mx, ans;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (can(mid)) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}