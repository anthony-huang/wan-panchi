#include <bits/stdc++.h>

using namespace std;

int num['9' + 1];
char s[100], t[100];
int f[100];

int main() {
	f[0] = 1;
	for (int i = 1; i <= 10; ++i) 
		f[i] = i * f[i - 1];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		int l = strlen(s);
		for (int j = 0; s[j]; ++j) {
			t[j] = s[j];
		}
		sort(t, t + l);
		for (int j = 0; s[j]; ++j) {
			num[t[j]] = j;
		}
		int cnt = 0;
		for (int j = 0; s[j]; ++j) {
			int p = num[s[j]];
			cnt += p * f[l - j - 1];
			for (int k = s[j] + 1; k <= '9'; ++k)
				num[k]--;
		}
		int step = f[l];
		int tmp = step - 1 - cnt;
		double ans = 0.0, z = 1. / step;
		for (int i = 0; i < tmp && z > 1e-12; ++i) {
			ans += z;
			z = z * (tmp - i - 1) / (i + 1) / step;
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}