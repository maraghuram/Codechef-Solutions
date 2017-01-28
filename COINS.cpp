#include <map>
#include <algorithm>
#include <iostream>
#include <stdio.h>
typedef unsigned long long ull;
using namespace std;
map<ull,ull> bytelandCoins;
void preCompute()
{
	for(int i=0;i<12;++i)
		bytelandCoins.insert(pair<ull,ull>(i,i));
}
ull solve(ull x)
{
	ull ans;
	if(bytelandCoins.find(x)!=bytelandCoins.end())
	{
		ans=bytelandCoins[x];
		return ans;
	}
	ans= solve(x>>1)+solve(x>>2)+solve(x/3);
	ans= ans>x? ans:x;
	bytelandCoins.insert(pair<ull,ull>(x,ans));
	return ans;
}
int main()
{
	ull num,N[10];
	int i=0;
	preCompute();
	while(scanf("%llu",&num)!=EOF)
	{
		N[i]=solve(num);
		++i;
	}
	for(int j=0;j<i;++j)
	{
		printf("%llu\n",N[j]);
	}
	return 0;
}
