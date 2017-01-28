#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
int N;
int main(){
  int res,count;
  
  scanf("%d",&N);
  res=count=0;
  
  for(int i=0;i<N;++i){
    int x;
    scanf("%d",&x);
    if(x==0) res=max(res,count),count=0;
    else ++count;
  }
  res=max(res,count);
  printf("%d\n",res);
  
  return 0;
}
