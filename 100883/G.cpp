#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int f[30030];
int inv[30030];

int C(int n, int k) {
	return ((((long long) f[n] * inv[k]) % MOD) * inv[n - k]) % MOD;
}

int modExp(int b, int p) {
	int x = 1;
	while (p) {
		if (p & 1) x = ((long long) x * b) % MOD;
		b = ((long long) b * b) % MOD;
		p >>= 1;
	}
	return x;
}

int main() {
	f[0] = 1;
	for (int i = 1; i <= 30030; ++i) {
		f[i] = ((long long) f[i - 1] * i) % MOD;
		inv[i] = modExp(f[i], MOD - 2);
	}

	int t, x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", C(x + y, y));
	}
	return 0;
}