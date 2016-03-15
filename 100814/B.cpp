#include <bits/stdc++.h>

using namespace std;

char ans[111], a[111], b[111];
bool used[111][4];

int main() {
	int t, q, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &q, &m);
		memset(ans, '?', sizeof ans);
		memset(used, false, sizeof used);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < q; ++j) {
				scanf("%s%s", a, b);
				if (b[0] == 'T') {
					ans[j] = a[0];
				}
				used[j][a[0] - 'A'] = true;
			}
		}
		for (int i = 0; i < q; ++i) {
			if (ans[i] == '?') {
				int cnt = 0;
				for (int j = 'A'; j <= 'D'; ++j) {
					if (used[i][j - 'A']) {
						++cnt;
					} else ans[i] = j;
				}
				if (cnt != 3) {
					ans[i] = '?';
				}
			}
			printf("%c%c", ans[i], " \n"[i == q - 1]);
		}
	}
	return 0;
}