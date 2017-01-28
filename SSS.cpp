#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL pow(LL a, LL b, LL MOD) {
LL x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
LL modInverse(LL a, LL m) {
    return pow(a,m-2,m);
}
int main(){
	LL T;
	scanf("%lld",&T);
	while(T--)	{
		LL n,p,res;
		scanf("%lld %lld",&n,&p);
		if(n>=p) res=0;
		else if(n==p-1) res=-1;
		else{
			res=1;
			for(int i=p-2;i>n;--i)	res=(res*modInverse(i,p)%p);
		}
		printf("%lld\n",res);
	}
	return 0;
}
