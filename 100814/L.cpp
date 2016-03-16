#include <bits/stdc++.h>

using namespace std;

int t,n,i;
int a[1007];
bool win;

bool iswin(int x) {
	int y = x % (n * (n-1));
	if (1 <= y && y <= n-1) return false;
	return true;
}

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0 ; i<n ; i++) {
			scanf("%d",&a[i]);
		}

		win = false;
		for (i=0 ; i<n ; i++) if (iswin(a[i])) win = true;
		if (win) printf("Alice\n"); else printf("Bob\n");
	}
}