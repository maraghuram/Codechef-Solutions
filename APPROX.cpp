#include <stdio.h>
#define SIZE 1000002
char array[SIZE];
void compute(int N)
{
  int num=103993,rem=4687,div=33102;
  for(int i=0;i<N;++i)
 {
   rem=(rem*10);
   num=rem/div;
   array[i]=48+(num);
   rem=rem-(num*div);
 } 
}
int main()
{
  int T,N[2001],max=-1;
  
  scanf("%d",&T);
  
   for(int i=0;i<T;++i)
  {
    scanf("%d",&N[i]);
    if(N[i]>max)
     max=N[i];
  }
  
  compute(max);
  
   for(int i=0;i<T;++i)
  {
    if(N[i]==0)
     printf("3\n");
    else
    {
      char c=array[N[i]];
      array[N[i]]='\0';
      printf("3.%s \n",array);
      array[N[i]]=c;
    } 
  } 
  
  return 0;
}
