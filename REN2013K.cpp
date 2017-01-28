#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    LL x,y,r,res;
    scanf("%lld %lld",&x,&y);
    r=(max(x,y)-min(x,y))+1;
    if(r%2==0){
      res=r-1;
      r=r/2;
      res=res*r;
    }
    else {
      res=r;
      res=res*((r-1)/2);
    }
    printf("%lld\n",res);
    
  }
}
