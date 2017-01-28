#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
inline LL find_depth(LL x){
	LL res=0;
	while(x>1) x=x>>1,res++;
	return res;
}
inline LL lca(LL x,LL y){
	LL res=0;
	while(x!=y){
		if(find_depth(x)<find_depth(y)) y=y>>1;
		else x=x>>1;
		++res;
	}
	return res;
}
int main()
{	
	int N;
	scanf("%d",&N);
	while(N--){
		int i,j;
		scanf("%d %d",&i,&j);
		printf("%lld\n",lca(i,j));
	}
	
	return 0;
}
