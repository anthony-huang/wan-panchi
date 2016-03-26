#include <bits/stdc++.h>

using namespace std;

long long t,n,i,x,ans;
long long sum[2000007];

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d",&n);
		for (i=1 ; i<=n ; i++) sum[i] = 0;
		for (i=1 ; i<=n ; i++) {
			scanf("%I64d",&x);
			sum[i] = x;
			if (i-2 >= 0) sum[i] += sum[i-2];
		}
		
		if (n % 2 == 0) {
			printf("%I64d\n",max(sum[n],sum[n-1]));
		} else {
			ans = sum[n];
			for (i=2 ; i<=n ; i++) {
				if (i % 2 == 1) {
					//printf("%I64d\n",sum[n]-sum[i-2] + sum[i-1]);
					ans = max(ans,sum[n]-sum[i-2] + sum[i-1]);
				} else {
					//printf("%I64d\n",sum[n-1]-sum[i-2] + sum[i-1]);
					ans = max(ans,sum[n-1]-sum[i-2] + sum[i-1]);
				}
			}
		}
		printf("%I64d\n",ans);
	}
}
