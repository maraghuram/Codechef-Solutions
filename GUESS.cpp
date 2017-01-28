#include <bits/stdc++.h>
using namespace std;
typedef long long int S64;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    S64 N,M;
    S64 num,denom;
    scanf("%lld %lld",&N,&M);
    if(N%2==0 || M%2==0) num=1,denom=2;
    else{
      denom=M*N;
      num=denom>>1;
    }
    printf("%lld/%lld\n",num,denom);
  } 
}
