#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, y, mnx = 10000, mxx = -mnx, mny = mnx, mxy = mxx;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 4; ++j) {
				scanf("%d %d", &x, &y);
				mnx = min(mnx, x);
				mxx = max(mxx, x);
				mny = min(mny, y);
				mxy = max(mxy, y);
			}
		}
		cout << (mxx - mnx) * (mxy - mny) << endl;
	}
	return 0;
}