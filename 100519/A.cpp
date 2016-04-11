#include <bits/stdc++.h>

using namespace std;

int n, k;
long long a[111][111];

int main()
{
	memset(a, -1, sizeof a);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[y][z] = x;
	}
	int l;
	scanf("%d", &l);
	long long ans = 0;
	while (l--)
	{
		char s[10];
		int x, y, z;
		scanf("%s %d %d %d", s, &x, &y, &z);
		if (s[0] == 'L')
		{
			for (int i = 1; i <= n; ++i)
			{
				int k = 0;
				bool united = false;
				for (int j = 1; j <= n; ++j)
				{
					if (a[i][j])
					{
						if (a[i][k] == a[i][j] && !united)
						{
							ans += (a[i][k] <<= 1);
							united = true;
						}
						else
						{
							a[i][++k] = a[i][j];
							united = false;
						}
						if (k != j) a[i][j] = 0;
					}
				}
			}
		}
		else
		if (s[0] == 'U')
		{
			for (int i = 1; i <= n; ++i)
			{
				int k = 0;
				bool united = false;
				for (int j = 1; j <= n; ++j)
				{
					if (a[j][i])
					{
						if (a[k][i] == a[j][i] && !united)
						{
							ans += (a[k][i] <<= 1);
							united = true;
						}
						else
						{
							a[++k][i] = a[j][i];
							united = false;
						}
						if (k != j) a[j][i] = 0;
					}
				}
			}
		}
		else
		if (s[0] == 'R')
		{
			for (int i = 1; i <= n; ++i)
			{
				int k = n + 1;
				bool united = false;
				for (int j = n; j >= 1; --j)
				{
					if (a[i][j])
					{
						if (a[i][k] == a[i][j] && !united)
						{
							ans += (a[i][k] <<= 1);
							united = true;
						}
						else
						{
							a[i][--k] = a[i][j];
							united = false;
						}
						if (k != j) a[i][j] = 0;
					}
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; ++i)
			{
				int k = n + 1;
				bool united = false;
				for (int j = n; j >= 1; --j)
				{
					if (a[j][i])
					{
						if (a[k][i] == a[j][i] && !united)
						{
							ans += (a[k][i] <<= 1);
							united = true;
						}
						else
						{
							a[--k][i] = a[j][i];
							united = false;
						}
						if (k != j) a[j][i] = 0;
					}
				}
			}
		}
		a[y][z] = x;
	}
	cout << ans << endl;
	return 0;
}