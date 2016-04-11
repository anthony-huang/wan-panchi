#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a *= a;
	b *= b;
	int sum = a + b;
	for (int c = 1; c * c <= sum; ++c)
	{
		if (c * c == sum)
		{
			puts("YES");
			return 0;
		}
	}
	sum = a - b;
	for (int c = 1; c * c <= sum; ++c)
	{
		if (c * c == sum)
		{
			puts("YES");
			return 0;
		}
	}
	sum = b - a;
	for (int c = 1; c * c <= sum; ++c)
	{
		if (c * c == sum)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}