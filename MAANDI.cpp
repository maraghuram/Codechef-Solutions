#include <cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int check(int num)
{
	int flag=0;
	while(num)
	{
		int rem=num%10;
		if(rem==4 || rem==7) {
			flag=1;
			break;
		}
		num=num/10;
	}
	return flag;
}
int overlucky(int x)
{
	int count=0;
	for(int i=1; i*i<=x; ++i)
	{
		int num=i;
		
		if(x%i==0){
			count+=check(i);
			if(i*i!=x)		count+=check(x/i);
		}
		
	}
	return count;
}
int main()
{
	int T;
	scanint(T);
	
	while(T>0)
	{
		int N;
		scanint(N);
		printf("%d\n",overlucky(N));		
		--T;
	}
	return 0;
}
