#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, g, y, r;
		scanf("%d %d %d %d", &x, &g, &y, &r);
		long long k = 1LL * g + y + r;
		x %= k;
		if (x < g) {
			printf("GREEN\n");
		} else if (x < g + y) {
			printf("YELLOW\n");
		} else printf("RED\n");
	}
	return 0;
}