#include <bits/stdc++.h>
#define DIGITS 10
#define NMAX 111111
using namespace std;
int counter[DIGITS];
int dp[NMAX];
int main(){
	memset(counter,0,sizeof(counter));
	int N,M;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<N;++i){
		int a,res=0;
		char x;
		scanf("%c",&x);		
		a=x-'0';
		for(int j=0;j<DIGITS;++j) 
			res=res+(counter[j]*abs(a-j));
		dp[i]=res;
		counter[a]++;
	}
	for(int i=0;i<M;++i){
		int x;
		scanf("%d",&x);
		printf("%d\n",dp[x-1]);
	}
}
