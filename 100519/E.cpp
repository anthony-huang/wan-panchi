#include <bits/stdc++.h>

using namespace std;

long long n;
long long d;

long long check(long long n, long long k)
{
	long long len = 0;
	while (n)
	{
		if (n % k == d)
		{
			++len;
			n /= k;
		}
		else
			break;
	}
	return len;
}

int main()
{
	cin >> n >> d;

	if (n == 0 && d == 0)
	{
		cout << "2 1\n";
		return 0;
	}

	n -= d;
	if (n < 0)
	{
		cout << "2 0\n";
		return 0;
	}

	if (n == 0)
	{
		cout << (d + 1) << " " << 1 << endl;
		return 0;
	}

	if (n == 1)
	{
		cout << "2 0\n";
		return 0;
	}

	vector<long long> v;
	for (long long i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			if (i > d)
				v.push_back(i);
			if (n / i != i && n / i > d)
				v.push_back(n / i);
		}
	}

	v.push_back(n);


	sort(v.begin(), v.end());

	long long base = 2, len = 0;
	for (long long x : v)
	{
		long long l = check(n + d, x);
		if (l > len)
		{
			base = x;
			len = l;
		}
	}

	cout << base << " " << len << endl;
	return 0;
}