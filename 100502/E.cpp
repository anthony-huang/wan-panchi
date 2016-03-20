#include <bits/stdc++.h>

using namespace std;

int n,i,ans,kiri,kanan;
int a[100007];

int main() {
	scanf("%d",&n);
	for (i=1 ; i<=n ; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	kiri = 0;
	kanan = n;
	
	while (kiri < kanan) {
		if (a[kanan] - a[kiri] > kanan - kiri) {
			ans++;
			kanan--;
		} else {
			kiri++;
			ans += a[kiri] - a[kiri-1];
		}
	}
	
	printf("%d\n",ans);
}