#include <iostream>
#include <cstdio>
#include <climits>
#define NMAX 111111
using namespace std;
typedef long long int LL;
int N,K;
int input[NMAX];
LL forward[NMAX],backward[NMAX];
int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;++i) scanf("%d",&input[i]);
	LL sumF,sumB;
	LL bestF,bestB;
	sumF=sumB=0;
	bestF=bestB=LLONG_MIN;
	for(int i=0,j=N-1;i<N && j>=0;++i,--j){
		sumF+=input[i];
		sumB+=input[j];
		bestF=max(bestF,sumF);
		bestB=max(bestB,sumB);
		if(sumF<0) sumF=0;
		if(sumB<0) sumB=0;
		forward[i]=bestF;
		backward[j]=bestB;
	}
	LL bestSplit=LLONG_MIN;
	for(int i=0;i<N-K-1;++i)	bestSplit=max(bestSplit,forward[i]+backward[i+K+1]);
	printf("%lld\n",bestSplit);
	--T;
	}
	return 0;
}
