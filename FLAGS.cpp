#include <bits/stdc++.h>
#define NMAX 11111
using namespace std;
typedef long long int ll;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    ll N;
    scanf("%lld",&N);
    if(N==1) printf("0\n");
    else if(N==2) printf("4\n");
    else if(N==3) printf("42\n");
    else{
      ll res = N*(N-1)*2 + (5*N*(N-1)*(N-2)) + (2*N*(N-1)*(N-2)*(N-3));
      printf("%lld\n",res);
    }
  }
  return 0;
}
