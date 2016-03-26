#include <bits/stdc++.h>

using namespace std;

long long t,n,i,x,ans;
long long a[1000007];

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d",&n);
		for (i=0 ; i<=1000000 ; i++) a[i] = 0;
		for (i=0 ; i<n ; i++) {
			scanf("%I64d",&x);
			a[x]++;
		}
		ans = 0;
		for (i=1000000 ; i>=1 ; i--) if (a[i] != 0) {
			ans += a[i] * (a[i]-1) / 2;
			x = 2*i;
			while (x <= 1000000) {
				ans += a[i] * a[x];
				x += i;
			}
		}
		
		printf("%I64d\n",ans);
	}
}
