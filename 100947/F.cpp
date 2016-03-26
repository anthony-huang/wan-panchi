#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, b, w;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &b, &w);
		if (n == 2) puts("Mikael");
		else {
			int k = abs(b - w);
			if (k & 1) puts("Mikael");
			else puts("Steven");
		}
	}
	return 0;
}