#include <cstdio>
#define NMAX 111
using namespace std;
int input[NMAX];
int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		int N,K,count=0;
		scanf("%d",&N);
		for(int i=0;i<N;++i) scanf("%d",&input[i]);
		scanf("%d",&K);
		for(int i=0;i<N;++i) if(input[i]<input[K-1]) ++count;
		printf("%d\n",count+1);
		--T;
	}
	return 0;
}
