#include <bits/stdc++.h>

using namespace std;

int t,i,j,n,tes;
double a[107][107];
double mem[4000007];

double DP(int bit) {
	//printf("%d\n",bit);

	if (bit == (1 << n) - 1) return 1;
	if (mem[bit] > -0.5) return mem[bit];
	
	int i;
	double ans = 0;
	for (i=0 ; i<n ; i++) if (((1 << i) & bit) == 0) {
		double tmp = 0;
		int j;
		for (j=0 ; j<n ; j++) if (((1 << j) & bit) != 0) {
			tmp += a[j][i];
			//printf("%dx%d\n",j,i);	
		}
		int nyan = __builtin_popcount(bit);
		int semua = nyan * (nyan + 1) / 2;
		tmp = tmp * DP(bit | (1 << i)) * (1.0/semua);
		ans += tmp;
	}
	
	//printf("\n%d : %.6lf\n",bit,ans);
	return mem[bit] = ans;
}

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%d",&n);
		for (i=0 ; i<n ; i++) {
			for (j=0 ; j<n ; j++) {
				scanf("%lf",&a[i][j]);
			}
		}
		for (i=0 ; i<(1<<n) ; i++) mem[i] = -1;
		printf("Case %d:",tes);
		for (i=0 ; i<n ; i++) printf(" %.6lf",DP(1 << i));
		printf("\n");
	}
}