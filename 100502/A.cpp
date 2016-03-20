#include <bits/stdc++.h>

using namespace std;

int n,m,x,y,z,i,j,lounge,all,ans;
int color[1000007];
vector<int> edge[1000007];
bool valid;
bool visit[1000007];

void DFS(int x) {
	int i;
	for (i=0 ; i<edge[x].size() ; i++) {
		int y = edge[x][i];
		if (color[x] == 0 && color[y] == 0) valid = false;
		if (color[x] == 1 && color[y] == 1) valid = false;
		color[y] = 1 - color[x];
		if (!visit[y]) {
			visit[y] = true;
			DFS(y);
		}
	}
}

void DFS2(int x) {
	int i;
	for (i=0 ; i<edge[x].size() ; i++) {
		int y = edge[x][i];
		if (color[x] == 0 && color[y] == 0) valid = false;
		if (color[x] == 1 && color[y] == 1) valid = false;
		color[y] = 1 - color[x];
		if (!visit[y]) {
			all++;
			lounge += color[y];
			visit[y] = true;
			DFS2(y);
		}
	}
}

int main() {
	valid = true;
	scanf("%d%d",&n,&m);
	
	for (i=0 ; i<n ; i++) color[i] = -1;
	for (i=0 ; i<m ; i++) {
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		if (z == 0) {
			if (color[x] == 1 || color[y] == 1) valid = false;
			color[x] = 0;
			color[y] = 0;
		}
		if (z == 2) {
			if (color[x] == 0 || color[y] == 0) valid = false;
			color[x] = 1;
			color[y] = 1;
		}
		if (z == 1) {
			edge[x].push_back(y);
			edge[y].push_back(x);
			if (color[x] == 1 && color[y] == 1) valid = false;
			if (color[x] == 0 && color[y] == 0) valid = false;
		}
	}
	
	for (i=0 ; i<n ; i++) if (!visit[i] && color[i] != -1) {
		visit[i] = true;
		DFS(i);
	}
	
	for (i=0 ; i<n ; i++) if (color[i] != -1) ans += color[i];
	for (i=0 ; i<n ; i++) if (!visit[i]) {
		assert(color[i] == -1);
		visit[i] = true;
		lounge = 0;
		all = 1;
		color[i] = 0;
		DFS2(i);
		
		ans += min(lounge,all-lounge);
	}
	
	if (!valid) printf("impossible\n"); else printf("%d\n",ans);
}