#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, w, h;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &w, &h);
		if (w == h) puts("Square");
		else puts("Rectangle");
	}
	return 0;
}