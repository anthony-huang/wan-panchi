#include <bits/stdc++.h>

using namespace std;

long long x,n,i,j,k;
bool valid;
bitset<4500007> prime;
char s[107];
int ans[107],answer[4500007];

int main() {
	for (i=2 ; i<=4500003 ; i++) prime[i] = true;
	for (i=2 ; i<=4500003 ; i++) if (prime[i]) {
		x = i*i;
		//printf("%I64d\n",x);
		while (x <= 4500003) {
			prime[x] = false;
			x += i;
		}
	}

	for (i=4500003 ; i>=0 ; i--) if (prime[i]) {
		x = i;
		k = 0;
		while (x != 0) {
			ans[k++] = x % 2;
			x /= 2;
		}
		
		valid = true;
		for (j=0 ; j<k ; j++) if (ans[j] != ans[k-1-j]) valid = false;
		if (valid) answer[i] = i; else answer[i] = answer[i+1];
	} else {
		answer[i] = answer[i+1];
	}
	
	//printf("---\n");

	while (scanf("%s",&s) > 0) {
		n = strlen(s);
		x = 0;
		
		for (i=0 ; i<n ; i++) {
			x = 2*x + s[i] - '0';
		}
		//printf("X = %I64d\n",x);
		x = answer[x];
		//printf("X = %I64d\n",x);
		k = 0;
		while (x != 0) {
			ans[k++] = x % 2;
			x /= 2;
		}
		for (i=k-1 ; i>=0 ; i--) printf("%d",ans[i]);
		printf("\n");
	}
}