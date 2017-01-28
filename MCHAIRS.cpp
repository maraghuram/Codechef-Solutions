#include <cstdio>
#define NMAX	100000005
#define MOD		1000000007
using namespace std;
typedef long long int x64;
x64 compute(int exp){
	x64 res=1;
	x64 base=2;
	while(exp>0){
		if(exp%2)
			res=(res*base)%MOD;
		exp=exp>>1;
		base=(base*base)%MOD;
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		int N;
		scanf("%d",&N);
		printf("%lld\n",compute(N)-1);
		--T;
	}
	return 0;
}
