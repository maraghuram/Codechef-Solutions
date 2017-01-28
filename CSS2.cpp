#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;
typedef pair<ll,pi> pp;
map<ll,pi> dict;
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int id,attr,val,pri;
  for(int i=0;i<n;++i){
    scanf("%d %d %d %d",&id,&attr,&val,&pri);
    ll key=(ll(id)*1000000)+ll(attr);
    if(dict.find(key)==dict.end())
      dict.insert(pp(key,pi(val,pri)));
    else
      dict[key]=dict[key].second>pri?dict[key]:pi(val,pri);
  }
  for(int i=0;i<m;++i){
    scanf("%d %d",&id,&attr);
    ll key=(ll(id)*1000000)+ll(attr);
    printf("%d\n",dict[key].first);
  }
  return 0;
}
