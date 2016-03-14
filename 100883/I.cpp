#include <bits/stdc++.h>

using namespace std;

long long t,n,i,j,k;
long long x[107],y[107],z[107],dist[107][107];

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d",&n);
		for (i=0 ; i<n ; i++) scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
		scanf("%I64d%I64d%I64d%I64d",&x[n],&y[n],&x[n+1],&y[n+1]);
		z[n] = 0;
		z[n+1] = 0;
		
		for (i=0 ; i<n+2 ; i++) {
			for (j=0 ; j<n+2 ; j++) {
				dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
				if ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= z[i]*z[i] && j < n && i < n) {
					dist[i][j] = min(dist[i][j],2LL);
				}
			}
			dist[i][i] = 0;
		}
		
		for (k=0 ; k<n+2 ; k++) {
			for (i=0 ; i<n+2 ; i++) {
				for (j=0 ; j<n+2 ; j++) {
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
				}
			}
		}
		
		printf("%I64d\n",dist[n][n+1]);
	}
}