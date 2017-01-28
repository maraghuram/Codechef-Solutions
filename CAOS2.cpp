#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
using namespace std;
const int MAX=502;
char array[MAX][MAX];
int dp[MAX][MAX],prime[MAX];
int R,C;
void solve()
{
	int counter=0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			dp[i][j]=INT_MAX;
	for(int i=0;i<R;++i)
	{
		counter=0;
		for(int j=0;j<C;++j)
		{
			if(array[i][j]=='#')
			{
				counter=0;
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=min(dp[i][j],counter);
			++counter;
		}
	}
	for(int i=0;i<R;++i)
	{
		counter=0;
		for(int j=C-1;j>=0;--j)
		{
			if(array[i][j]=='#')
			{
				counter=0;
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=min(dp[i][j],counter);
			++counter;
		}
	}
	for(int j=0;j<C;++j)
	{
		counter=0;
		for(int i=R-1;i>=0;--i)
		{
			if(array[i][j]=='#')
			{
				counter=0;
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=min(dp[i][j],counter);
			++counter;
		}
	}
	for(int j=0;j<C;++j)
	{
		counter=0;
		for(int i=0;i<R;++i)
		{
			if(array[i][j]=='#')
			{
				counter=0;
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=min(dp[i][j],counter);
			++counter;
		}
	}
	int result=0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			result+=prime[dp[i][j]];
	printf("%d\n",result);
}
int main()
{
	int T;
	for(int i = 2; i <= 500; i++) prime[i] = 1;
	for(int i = 2; i <= 500; i++)
		if(prime[i])
		{
			for(int j = i + i; j <= 500; j += i)
				prime[j] = 0;
		}
	for(int i = 2; i <= 500; i++) prime[i] += prime[i - 1];
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d %d",&R,&C);
		for(int i=0;i<R;++i)
			scanf("%s",array[i]);
		//printf("%d\n",solve());
		solve();
		--T;
	}
	return 0;
}
