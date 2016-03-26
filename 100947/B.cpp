#include <bits/stdc++.h>

using namespace std;

char s[110];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int r[8];
		memset(r, -1, sizeof r);
		bool valid = true;
		for (int i = 0; i < 8; ++i) {
			scanf("%s", s);
			if (r[s[0] - 'A'] != -1) {
				valid = false;
			}
			else {
				r[s[0] - 'A'] = s[1] - '1';
			}
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = i + 1; j < 8; ++j) {
				if (r[i] == r[j] || (abs(i - j) == abs(r[i] - r[j]))) {
					valid = false;
				}
			}
		}

		if (valid) puts("Valid");
		else puts("Invalid");
	}
	return 0;
}