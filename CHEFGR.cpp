#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int m,n,bst=-1;
    scanf("%d %d",&n,&m);
    vector<int> a(n);
    for(int i=0;i<n;++i){
      scanf("%d",&a[i]);
      bst=max(a[i],bst);
    }
    int res=0;
    for(int i=0;i<n;++i) res += (bst-a[i]);
    if(m==res) printf("Yes\n");
    else if(m>res && (res-m)%n==0) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
