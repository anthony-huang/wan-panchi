#include <bits/stdc++.h>

using namespace std;

int n,i,ans,x,t,j,k;
int a[2000007];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0 ; i<n ; i++) {
			scanf("%d",&a[i]);
		}
		
		ans = 0;
		for (i=0 ; i<n ; i++) {
			for (j=i+1 ; j<n ; j++) {
				x = 0;
				for (k=0 ; k<30 ; k++) {
					if (((1 << k) & a[i]) != ((1 << k) & a[j])) x++;
				}
				ans = max(ans,x);
			}
		}
		
		printf("%d\n",ans);
	}
}