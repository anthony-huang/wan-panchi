#include <bits/stdc++.h>

using namespace std;

long long t,n,i,j,x,y,base,top,mid,m,q;
long long minim[1000007],bobot[1000007];
vector<long long> a,edge[1000007];

void DFS(long long pos, long long depth) {
	if (edge[pos].size() == 0) {
		a.push_back(depth);
		return;
	}
	
	int i;
	for (i=0 ; i<edge[pos].size() ; i++) {
		if (minim[pos] == edge[pos][i]) {
			DFS(edge[pos][i],depth + bobot[edge[pos][i]]);
		} else {
			DFS(edge[pos][i],depth + bobot[minim[pos]] + 2*(bobot[edge[pos][i]] - bobot[minim[pos]]));
		}
	}
}

int main() {
	scanf("%I64d",&t);
	while (t--) {
		scanf("%I64d",&n);
		for (i=1 ; i<=n ; i++) {
			edge[i].clear();
			minim[i] = -1;
		}
		for (i=2 ; i<=n ; i++) {
			scanf("%I64d%I64d",&x,&y);
			edge[x].push_back(i);
			bobot[i] = y;
			if (minim[x] == -1 || y < bobot[minim[x]]) minim[x] = i;
		}
		
		m = 0;
		for (i=1 ; i<=n ; i++) if (edge[i].size() == 0) m++; 
		
		a.clear();
		DFS(1,0);
		sort(a.begin(),a.end());
		//for (i=0 ; i<a.size() ; i++) printf("-- %I64d\n",a[i]);
		
		scanf("%I64d",&q);
		while(q--) {
			scanf("%I64d",&x);
			base = 0;
			top = m;
			while (base != top) {
				mid = (base + top) / 2 + 1;
				if (a[mid-1] > x) top = mid - 1; else base = mid;
			}
			printf("%I64d\n",top);
		}
	}
}