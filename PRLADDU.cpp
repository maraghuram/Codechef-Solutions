#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
inline int _abs(int x){
  return (x>=0?x:(-x));
}
int a[NMAX];
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    int x,y;
    x=y=0;
    long long res=0;
    while(1){
      while(x<n && a[x]<=0) ++x;
      while(y<n && a[y]>=0) ++y;
      if(x>=n || y>=n ) break;
      int tmp=min(a[x],_abs(a[y]));
      res += (_abs(x-y)*tmp);
      a[x]-=tmp;
      a[y]+=tmp;
      //cout << x << " " << y <<endl;
    }
    printf("%lld\n",res);
  }
  return 0;
}
