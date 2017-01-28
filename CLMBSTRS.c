#include <stdio.h>
#define MAX 1000001
 
unsigned long array[MAX];
unsigned long mod=1000000007;
 
main()
{
	unsigned int T,G[100000],i,j;
	unsigned long n[100000];
	#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
        #endif
 
	array[0]=1;
	array[1]=1;
 
	scanf("%u",&T);
 
	for(i=2;i<MAX;++i)
	{
		array[i]=array[i-1]+array[i-2];
		if(array[i]>mod)
			array[i]=array[i]%mod;
 
	}
 
 
	for(i=0;i<T;++i)
	{
		scanf("%lu %u",&n[i],&G[i]);
	}
 
	for(j=0;j<T;++j)
	{
 
      if(countOnes(array[n[j]])==G[j])
    	  printf("\nCORRECT");
      else
    	  printf("\nINCORRECT");
 
	}
	return 0;
}
 
 int countOnes(unsigned long int n)
 {
	 unsigned long temp=n;
	 int count=0;
 
	 while(temp>0)
	 {
		 if(temp%2)
			 ++count;
		 temp=temp/2;
	 }
	 return count;
 }
