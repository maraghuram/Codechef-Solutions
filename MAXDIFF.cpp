#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> weights;
int solve(int n,int k)
{
	int chefSum,kidSum,mid;
	sort (weights.begin(), weights.end());
	chefSum=kidSum=0;
	mid=k<n-k?k:n-k;
	for(int i=0;i<n;++i)
		if(i<mid)
			kidSum+=weights[i];
		else
			chefSum+=weights[i];
	return chefSum-kidSum;
}
int main()
{
	int T,N,K,R[102];
	scanf("%d",&T);
	for(int i=0;i<T;++i)
	{
		scanf("%d %d",&N,&K);
		weights.resize(N,0);
		for(int j=0;j<N;++j)
		{
			int temp;
			scanf("%d",&temp);
			weights[j]=temp;
		}
		R[i]=solve(N,K);
	}
	for(int i=0;i<T;++i)
	{
		printf("%d\n",R[i]);
	}
	return 0;
}
