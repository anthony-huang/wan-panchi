#include <bits/stdc++.h>

using namespace std;

int n,i;
vector<long long> a,b;
int c[1000007];
long long x,y,MOD;
bool valid;

long long poer(long long x, long long y) {
	if (y == 0) return 1;
	if (y == 1) return x % MOD;
	if (y % 2 == 1) return (x % MOD * poer(x,y-1)) % MOD;
	long long tmp = poer(x,y/2);
	return (tmp*tmp) % MOD;
}

int main() {
	MOD = 1000000007LL;
	scanf("%d",&n);
	
	for (i=0 ; i<n ; i++) scanf("%d",&c[i]);
	sort(c,c+n);
	for (i=1 ; i<n ; i++) a.push_back(c[i] - c[i-1]);
	a.push_back(c[0] - c[n-1] + 360000);
	
	for (i=0 ; i<n ; i++) scanf("%d",&c[i]);
	sort(c,c+n);
	for (i=1 ; i<n ; i++) b.push_back(c[i] - c[i-1]);
	b.push_back(c[0] - c[n-1] + 360000);
	
	for (i=0 ; i<n ; i++) x = ((360000 * x) % MOD + a[i]) % MOD;
	for (i=0 ; i<n ; i++) y = ((360000 * y) % MOD + b[i]) % MOD;
	if (x == y) valid = true;
	for (i=0 ; i<n ; i++) {
		y = ((y - b[i]*poer(360000,n-1)%MOD) % MOD + MOD) % MOD;
		y = ((360000 * y) % MOD + b[i]) % MOD;
		if (x == y) valid = true;
	}
	
	if (!valid) printf("im");
	printf("possible\n");
}