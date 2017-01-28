#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,ll> pil;
int main(){
  ll N,M,H;
  scanf("%lld %lld %lld",&N,&M,&H);
  ll res=0;
  ll sqrs = N*M;
  vector<pil> paint(H);
  for(int i=0;i<H;++i) scanf("%lld %d",&paint[i].second,&paint[i].first);
  sort(paint.begin(),paint.end());
  
  for(int i=0;i<H;++i){
    ll get = min( sqrs, paint[i].second );
    res = res + (get*(ll) paint[i].first);
    sqrs = sqrs - get;
    if( sqrs == 0 ) break;
  }
  if( sqrs != 0 ) printf("Impossible\n");
  else printf("%lld\n",res);
  return 0;
}
