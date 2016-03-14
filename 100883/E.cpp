#include <bits/stdc++.h>

using namespace std;

long long t,n,q,x,y,z,i,j,base,top,mid;
pair<long long,long long> a[1000007];

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d%I64d",&n,&q);
		for (i=0 ; i<n ; i++) {
			scanf("%I64d",&a[i].first);
			a[i].second = i+1;
		}
		sort(a,a+n);
		for (i=0 ; i<q ; i++) {
			scanf("%I64d",&x);
			y = 0;
			z = n-1;
			for (j=35 ; j>=0 ; j--) {
				base = y;
				top = z+1;
				while (base != top) {
					mid = (base + top) / 2;
					if ((1LL << j) & a[mid].first) top = mid; else base = mid + 1;
				}
				if (top != z+1 && top != y) {
					if ((1LL << j) & x) z = top - 1; else y = top;
				}
			}
			printf("%I64d\n",a[y].second);
		}
		printf("\n");
	}
}