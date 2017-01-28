#include <stdio.h>
int alpha[52];
void setZero();
main()
{
 int T,i,j,cost=0;
 char str[101][201] ;
 scanf("%d",&T);
  for(i=0;i<T;++i)
   scanf("%s",str[i]);
  for(i=0;i<T;++i)
 {
   setZero();
   cost=0;
   for( j=0;str[i][j]!='\0';++j)
   {
     if(str[i][j]<91)
      ++alpha[str[i][j]-65];
     else
      ++alpha[str[i][j]-71];
   }
   for( j=0;j<52;++j)
 {    cost+=(alpha[j]/2+alpha[j]%2);
  }
  printf("\n%d",cost);
 }
 return 0;
}
void setZero()
{
  int i;
  for(i=0;i<52;++i)
   alpha[i]=0;
}
