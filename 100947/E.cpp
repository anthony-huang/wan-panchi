#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int modExp(int b, int p) {
	int x = 1;
	while (p) {
		if (p & 1) x = ((long long) x * b) % MOD;
		b = ((long long) b * b) % MOD;
		p >>= 1;
	}
	return x;
}

int fact[300000] = {1};
int inv[300000] = {1};

int C(int n, int k) {
	return ((((long long) fact[n] * inv[k]) % MOD) * inv[n - k]) % MOD;
}

int main() {
	for (int i = 1; i < 300000; ++i) {
		fact[i] = ((long long) i * fact[i - 1]) % MOD;
		inv[i] = modExp(fact[i], MOD - 2);
	}

	int t, n, m, r, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		scanf("%d %d", &r, &c);
		int ans = C(n + m - 2, m - 1);
		long long tmp = (long long) C(r + c - 2, c - 1);
		tmp *= C(n - r + m - c, m - c);
		tmp %= MOD;
		ans -= tmp;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		printf("%d\n", ans);
	}
	return 0;
}