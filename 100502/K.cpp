#include <bits/stdc++.h>

using namespace std;

long long t,n,c,i,x,y,z,ans;
bool valid;

int main() {
	scanf("%I64d%I64d",&c,&n);
	ans = 0;
	valid = true;
	for (i=0 ; i<n ; i++) {
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		if (i == n-1 && z != 0) valid = false;
		ans -= x;
		if (ans < 0) valid = false;
		ans += y;
		if (ans > c) valid = false;
		if (z > 0 && ans != c) valid = false;
	}
	if (ans != 0) valid = false;
	if (!valid) printf("im");
	printf("possible\n");
}