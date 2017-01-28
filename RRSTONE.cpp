#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
typedef long long int LL;
LL input[NMAX];
int main(){
	LL N,K,best;
	scanf("%lld %lld",&N,&K);
	for(int i=0;i<N;++i){
		scanf("%lld",&input[i]);
		if(i>0) best=max(best,input[i]);
		else best=input[i];
	}
	if(K>0){
		LL val;
		for(int i=0;i<N;++i){
			input[i]=best-input[i];
			if(i>0) val=max(val,input[i]);
			else val=input[i];
		}
		if(K%2==0){
			for(int i=0;i<N;++i) input[i]=val-input[i];
		}
	}
	for(int i=0;i<N;++i) printf("%lld ",input[i]);
	return 0;
}
