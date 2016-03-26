#include <bits/stdc++.h>

using namespace std;

int a[111][111];

int dx[] = {0, 1, 1, -1};
int dy[] = {1, -1, 0, 1};

bool vis[111][111];

int main() {
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				vis[i][j] = false;
			}
		}
		int r = 1, c = 1, d = 0;
		for (int i = 1, k = n * n; i <= k; ++i) {
			vis[r][c] = true;
			printf("%d%c", a[r][c], " \n"[i % n == 0]);
			
			for (int l = 0; l < 4; ++l) {
				int f = (d + l) % 4;
				int nx = r + dx[f], ny = c + dy[f];
					if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
				r = nx, c = ny;
				d = f;
				if (d == 0) ++d;
				if (d == 2) ++d;
				break;
			}
			
		}
	}
	return 0;
}