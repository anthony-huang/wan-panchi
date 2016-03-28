#include <bits/stdc++.h>

using namespace std;

int a[11][11], b[11][11];
int p1, p2;

int main() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			scanf("%d %d", &a[i][j], &b[i][j]);
		}
	}

	for (int i = a[0][0]; i <= b[0][0]; ++i) {
		for (int j = a[0][1]; j <= b[0][1]; ++j) {
			int sum = i + j;
			for (int k = a[1][0]; k <= b[1][0]; ++k) {
				for (int l = a[1][1]; l <= b[1][1]; ++l) {
					int sum2 = k + l;
					if (sum < sum2) {
						p2++;
					} else if (sum > sum2) ++p1;
				}
			}
		}
	}

	if (p1 > p2) puts("Gunnar");
	else if (p2 > p1) puts("Emma");
	else puts("Tie");

	return 0;
}