#include <bits/stdc++.h>

using namespace std;

char a[10], b[10];
vector<string> v;
char s[20];

void rec(int l, int r) {
	if (!a[l] && !b[r]) {
		v.push_back(s);
		return;
	}
	if (a[l]) {
		s[l + r] = a[l];
		rec(l + 1, r);
	}
	if (b[r]) {
		s[l + r] = b[r];
		rec(l, r + 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		memset(s, 0, sizeof s);
		scanf("%s %s", a, b);
		rec(0, 0);
		sort(v.begin(), v.end());
		printf("%s\n", v[0].c_str());
		for (int i = 1; i < v.size(); ++i) {
			if (v[i - 1] != v[i]) {
				printf("%s\n", v[i].c_str());
			}
		}
		puts("");
	}
	return 0;
}