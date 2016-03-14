#include <bits/stdc++.h>

using namespace std;

int n1, n2, c1, c2;

long long x, y, d;

void gcd(int a, int b) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
		return;
	}
	gcd(b, a % b);
	int q = a / b;
	long long y1 = x - q * y;
	long long x1 = y;
	x = x1;
	y = y1;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		scanf("%d %d", &c1, &n1);
		scanf("%d %d", &c2, &n2);
		gcd(n1, n2);
		if (n % d) {
			puts("failed");
		} else {
			x = x * (n / d);
			y = y * (n / d);
			// cout << ":::: " << n1 << " " << x << " + " << n2 << " " << y << "\n";
			long long ans = 1e18, a = -1, b = -1;
			long long k1 = n2 / d, k2 = n1 / d;
			long long y1 = y / k2;
			long long y2 = y - y1 * k2;
			if (y2 < 0) {
				y2 += k2;
				--y1;
			}
			long long tmpx = x + k1 * y1;
			// cout << ":'( " << k1 << " " << y1 << " " << y2 << " " << tmpx << "\n";
			if (tmpx >= 0 && y2 >= 0) {
				if (ans > tmpx * c1 + y2 * c2) {
					a = tmpx, b = y2;
					ans = tmpx * c1 + y2 * c2;
				}
			}
			long long x1 = x / k1;
			long long x2 = x - x1 * k1;
			if (x2 < 0) {
				x2 += k1;
				--x1;
			}
			long long tmpy = y + k2 * x1;
			if (x2 >= 0 && tmpy >= 0) {
				if (ans > x2 * c1 + tmpy * c2) {
					a = x2, b = tmpy;
					ans = x2 * c1 + tmpy * c2;
				}
			}
			// cout << ":'( " << k2 << " " << x1 << " " << x2 << " " << tmpy << "\n";
			if (a == -1) {
				puts("failed");
			}
			else cout << a << " " << b << "\n";
		}
	}
	return 0;
}