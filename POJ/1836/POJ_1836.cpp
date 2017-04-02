#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	double a[1010];
	int dp_left[1010];
	int dp_right[1010];
	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		scanf("%lf",&a[i]);

	for(int i = 1; i <= n; i++)
	{
		dp_left[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(a[i] > a[j] && dp_left[i] < dp_left[j] +1)
				dp_left[i] = dp_left[j]+1;
		}
	}

	for(int i = n; i >= 1; i--)
	{
		dp_right[i] = 1;
		for(int j = n; j > i; j--)
		{
			if(a[i] > a[j] && dp_right[i] < dp_right[j]+1)
				dp_right[i] = dp_right[j]+1;
		}
	}

	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			if(dp_left[i] + dp_right[j] > ans)
				ans = dp_left[i] + dp_right[j];
		}
	}
	printf("%d\n",n-ans);
}
