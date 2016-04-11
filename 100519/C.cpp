#include <bits/stdc++.h>

using namespace std;

long long a,b,c,x,y,base,top,mid,persatuan,sisa;

int main() {
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if (b < a) a = b;
	x = (c+a-1)/a;
	base = 1;
	top = x;
	while (base != top) {
		mid = (base + top) / 2;
		y = 0;
		persatuan = b / a;
		sisa = max(0LL,x - persatuan * mid);
		y += (x-sisa) * a;
		y += min(sisa,mid) * (b - persatuan * a);
		if (y >= c) top = mid; else base = mid + 1;
	}
	printf("%I64d %I64d\n",x,top);
}