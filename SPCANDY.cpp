#include <cstdio>
typedef long long int x64;
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		x64 N,K;
		scanf("%lld %lld",&N,&K);
		if(K==0)
			printf("%d %lld\n",0,N);
		else
			printf("%lld %lld\n",N/K,N%K);
		--T;
	}
	return 0;
}
