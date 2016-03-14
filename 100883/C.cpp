#include <bits/stdc++.h>

using namespace std;

int c, m, x;

int cnt[1000001];

bool cmp(pair<long long, int> a, pair<long long, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &c, &m);
		memset(cnt, 0, sizeof cnt);
		vector<pair<long long, int> > v;
		for (int i = 0; i < c; ++i) {
			scanf("%d", &x);
			cnt[x]++;
		}
		for (int i = 1; i <= 1000000; ++i) {
			if (cnt[i])
				v.push_back({(long long) -cnt[i] * i, i});
		}
		sort(v.begin(), v.end(), cmp);
		vector<int> ans;
		long long sum = 0;
		bool can = false;
		for (int i = 0; !can && i < v.size(); ++i) {
			sum -= v[i].first;
			ans.push_back(v[i].second);
			if (sum >= m) {
				can = true;
			}
		}
		if (can) {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
			}
		} else puts("Impossible");
	}
	return 0;
}