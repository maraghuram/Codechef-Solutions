#include <bits/stdc++.h>
#define NMAX 3333333
#define MOD 1000000
using namespace std;
typedef long long int LL;
int strengths[MOD];
LL readLL()
{
   LL cc = getc(stdin);
   for (;cc < '0' || cc > '9';)  cc = getc(stdin);
   LL ret = 0;
   for (;cc >= '0' && cc <= '9';)
   {
      ret = ret * 10 + cc - '0';
      cc = getc(stdin);
   }
  return ret;
}
int main(){
	LL T;
	//scanf("%lld",&T);
	T=readLL();
	while(T--){
		LL N,a,b,c,d,prev,maxval;
		//scanf("%lld %lld %lld %lld %lld",&N,&a,&b,&c,&d);
		N=readLL();
		a=readLL();
		b=readLL();
		c=readLL();
		d=readLL();
		memset(strengths,0,sizeof(strengths));
		maxval=prev=d;
		strengths[prev]=1;
		for(LL i=1;i<N;++i){
			LL curr;
			curr=(a*prev*prev)+(b*prev)+c;
			if(curr>=MOD) curr=curr%MOD;
			strengths[curr]+=1;
			maxval=max(maxval,curr);
			prev=curr;
		}
		LL l,r;
		l=r=0;
		int flag=0;
		for(LL i=0;i<=maxval;++i){
			if(strengths[i]){
				for(LL j=0;j<strengths[i];++j){
					if(flag==0){
						l+=i;
						flag=1;
					}
					else{
						r+=i;
						flag=0;
					}
				}
			}
		}
		printf("%lld\n",abs(l-r));
	}
	return 0;
}
