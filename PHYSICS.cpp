#include <bits/stdc++.h>
#define NMAX 11111
using namespace std;
typedef long long int ll;
typedef pair<int,int> pi;
ll f,s,l;
int n;
vector<ll> a;
int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;++t){
    ll res=0;
    l=0;
    scanf("%d %lld",&n,&f);
    a=vector<ll>(n);
    for(int i=0;i<n;++i){
      scanf("%lld",&a[i]);
      l=max(l,a[i]);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i){
      ll val=a[i]; ll cnt=0;
      while(val<=l){
	cnt = upper_bound(a.begin(),a.end(),val)-a.begin();
	cnt -= lower_bound(a.begin(),a.end(),val)-a.begin();
	res += cnt;
	val *= f;
      }
      ll _f=f;
      val=a[i];
      while(val/_f>=1){
	if(val%_f==0){
	  cnt = upper_bound(a.begin(),a.end(),val/_f)-a.begin();
	  cnt -= lower_bound(a.begin(),a.end(),val/_f)-a.begin();
	  res += cnt;
	}
	_f=_f*f;
      }
    }
    printf("%lld\n",(res-n)/2);
  }
  return 0;
}
