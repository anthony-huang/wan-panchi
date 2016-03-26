#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		if (x % 4) puts("Impossible");
		else {
			int c = x / 4 * 3;
			if ((c + x) & 1) puts("Impossible");
			else {
				int b = (c + x) >> 1;
				long long k = (x + 2LL * b);
				if (k & 1) puts("Impossible");
				else {
					int a = k / 2;
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
	return 0;
}