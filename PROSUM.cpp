#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
typedef long long int LL;
LL input[NMAX];
int main(){
	LL T;
	scanf("%lld",&T);
	while(T--){
		LL N,zeroes,ones,twos;
		LL res=0;
		scanf("%lld",&N);
		zeroes=ones=twos=0;
		for(LL i=0;i<N;++i){
			scanf("%lld",&input[i]);
			if(input[i]==0) ++zeroes;
			else if(input[i]==1) ++ones;
			else if(input[i]==2) ++twos;
		}
		res=N*(N-1)>>1;
		for(LL i=0;i<zeroes;++i) res-=(N-i-1);
		N=N-zeroes;
		for(LL i=0;i<ones;++i) res-=(N-i-1);
		res-=(twos*(twos-1)>>1);
		printf("%lld\n",res);
	}
	return 0;
}
