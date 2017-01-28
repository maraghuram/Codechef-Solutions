#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long int x64;
x64 array[1001][11];
void initialize()
{
	x64 runSq;
	for(int k=1;k<=10;++k)
		array[1][k]=k;
	for(int i=1;i<=10;++i)
	{
		runSq=i*i;
		for(int n=2;n<=1000;++n)
		{
			array[n][i]=(runSq-array[n-1][i])%MOD;
			if(array[n][i]<0)
				array[n][i]+=MOD;
			runSq=runSq*i%MOD;
		}
	}
}
int main()
{
	initialize();
	int T,N,K;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d %d",&N,&K);
		printf("%lld\n",array[N-1][K]);
		--T;
	}
	return 0;
}
