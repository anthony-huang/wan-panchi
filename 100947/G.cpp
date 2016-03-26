#include <bits/stdc++.h>

using namespace std;

long long t,n,m,x,y,k,ans;

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d%I64d",&n,&m);
		if (n == 0 && m == 0) printf("0\n"); else {
			k = max(abs(n),abs(m));
			ans = (2*k-1) * (2*k-1);
			
			x = k;
			y = -(k-1);
			
			if (n > m && abs(n) == abs(m)) {
				printf("%I64d\n",(2*k+1) * (2*k+1)-1);
			} else if (x == n) {
				ans += m - y;
				printf("%I64d\n",ans);
			} else {
				ans += 2*k-1;
				y = k;
				if (y == m) {
					ans += x - n;
					printf("%I64d\n",ans);
				} else {
					ans += 2*k;
					x = -k;
					if (x == n) {
						ans += y - m;
						printf("%I64d\n",ans);
					} else {
						ans += 2*k;
						y = -k;
						ans += n - x;
						printf("%I64d\n",ans);
					}
				}
			}
		}
	}
}
