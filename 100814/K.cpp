#include <bits/stdc++.h>

using namespace std;

long long a, b;
int n, p;

int arr[1000100];
int dp[2][200];

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> a >> b >> n >> p;
		a *= 10;
		memset(dp, 0, sizeof dp);
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			arr[i] = a / b;
			a %= b;
			a *= 10;
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int cur = i & 1, nxt = (i + 1) & 1;
			dp[cur][arr[i] % p] += 1;
			for (int j = 0; j < p; ++j) {
				dp[nxt][(j * 10 + arr[i + 1]) % p] += dp[cur][j];
			}
			ans += dp[cur][0];
			for (int j = 0; j < p; ++j) {
				dp[cur][j] = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}