#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
inline ll abs_(ll x){
  if( x>0 ) return x;
  return -x;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    ll x,y,res=0;
    scanf("%lld %lld",&x,&y);
    x=abs_(x);
    y=abs_(y);
    if( x==y )res=x+y;
    else if(x>y){
      res = y+y;
      res += (((x-y-1)/2)*4)+1-((x-y)%2)+3;
      }
    else{
      res = x+x;
      res += (((y-x)/2)*4)+(y-x)%2;
    }
    printf("%lld\n",res);
  }
  return 0;
}
