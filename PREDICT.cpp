#include <cstdio>
const int MAX=10000;
typedef unsigned long long x64;
int main()
{
	x64 T;
	scanf("%llu",&T);
	while(T>0)
	{
		double 	p,res;
		scanf("%lf",&p);
		p=(p>0.5?p:1-p);
		res=(MAX+(MAX*2*(1-p)))*p;
		printf("%f\n",res);
		--T;
	}
	return 0;
}
