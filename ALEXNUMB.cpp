#include <cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		long long int N,x;
		scanf("%lld",&N);
		for(int i=0;i<N;++i) scanf("%lld",&x);
		printf("%lld\n",(N*(N-1))>>1);
		--T;
	}
	return 0;
}
