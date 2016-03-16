#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,k,x,t,ans;
int mem[107][107][1207];
int a[107][107],b[107][107];

int DP(int x, int y, int sisa) {
	if (x == n-1 && y == m-1) {
		if (sisa == 0) return 0;
		return -999999999;
	}
	if (mem[x][y][sisa] != -1) return mem[x][y][sisa];
	
	int ans = -999999999;
	if (x < n-1 && a[x+1][y] <= sisa) ans = max(ans,b[x+1][y] + DP(x+1,y,sisa-a[x+1][y]));
	if (y < m-1 && a[x][y+1] <= sisa) ans = max(ans,b[x][y+1] + DP(x,y+1,sisa-a[x][y+1]));
	
	return mem[x][y][sisa] = ans;
}

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&m);
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<m ; j++) {
				a[i][j] = 0;
				b[i][j] = 0;
				scanf("%d",&x);
				
				while (x % 3 == 0) {
					x /= 3;
					a[i][j]++;
				}
				while (x % 2 == 0) {
					x /= 2;
					b[i][j]++;
				}
			}
		}
		
		ans = 0;
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<m ; j++) {
				for (k=0 ; k<=1200 ; k++) {
					mem[i][j][k] = -1;
				}
			}
		}
		
		for (i=0 ; i<=1200 ; i++) if (a[0][0] <= i) {
			ans = max(ans,min(i,b[0][0] + DP(0,0,i-a[0][0])));
		}
		printf("%d\n",ans);
	}
}