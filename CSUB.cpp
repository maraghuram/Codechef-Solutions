#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    int cnt=0;
    scanf("%d\n",&N);
    for(int i=0;i<N;++i){
      char c;
      scanf("%c",&c);
      if(c=='1') cnt++;
    }
    long long int res= (long long int)cnt;
    res = (res * (res-1))/2;
    res = res + cnt;
    printf("%lld\n",res);
  }
  return 0;
}
