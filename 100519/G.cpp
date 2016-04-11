#include <bits/stdc++.h>

using namespace std;

int n,i,j,x,maxim,pos,answer;
int ans[100007],indeg[100007];
bool flag[100007];
string s1[100007],s2[100007],s3[100007];
map<string,int> mem;
vector<int> edge[100007];
queue<int> q;

int main() {
	scanf("%d",&n);
	for (i=1 ; i<=n ; i++) {
		cin >> s1[i] >> s2[i] >> s3[i] >> s3[i] >> s3[i];
	}
	for (i=1 ; i<=n ; i++) {
		mem[s2[i]] = i;
	}
	for (i=1 ; i<=n ; i++) {
		ans[i] = 1;
		if (mem[s3[i]] > 0) {
			if (s1[i] == s1[mem[s3[i]]]) {
				edge[i].push_back(mem[s3[i]]);
				indeg[mem[s3[i]]]++;
			}
		}
	}
	
	for (i=1 ; i<=n ; i++) if (indeg[i] == 0) {
		q.push(i);
		flag[i] = true;
	}
	
	while (!q.empty()) {
		x = q.front();
		q.pop();
		
		for (i=0 ; i<edge[x].size() ; i++) {
			ans[edge[x][i]] = max(ans[edge[x][i]],ans[x] + 1);
			indeg[edge[x][i]]--;
			if (indeg[edge[x][i]] == 0) {
				q.push(edge[x][i]);
				flag[edge[x][i]] = true;
			}
		}
	}
	
	for (i=1 ; i<=n ; i++) answer = max(answer,ans[i]);
	
	for (i=1 ; i<=n ; i++) if (!flag[i]) {
		maxim = 0;
		x = 0;
		pos = i;
		while (!flag[pos]) {
			flag[pos] = true;
			maxim = max(maxim,ans[pos]);
			x++;
			pos = edge[pos][0];
		}
		answer = max(answer,maxim + x - 1);
	}
	
	printf("%d\n",answer);
}