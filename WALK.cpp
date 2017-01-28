#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
int input[NMAX];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		int diff=0,res=-1;
		scanf("%d",&N);
		for(int i=0;i<N;++i){ scanf("%d",&input[i]); res=max(res,input[i]+i); }
		printf("%d\n",res);
	}
	return 0;
}
