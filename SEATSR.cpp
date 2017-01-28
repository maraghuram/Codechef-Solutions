#include <bits/stdc++.h>
#define NMAX 111111
#define inf 1111111
using namespace std;
time_t start=clock();
int aCost,bCost;
char buffer[NMAX];
int editDistance(string a,string b,int k){
  if(a.size() < b.size()) swap(a,b);
  if(aCost==0) return 0;
  //else if(bCost==0)
	//return (a.size()-b.size()<=k?a.size()-b.size():-1);
  int sz=b.size()+1;
  //sz=max(sz,k+1);
  vector<int> pre(sz,inf),dis(sz,inf);
  for(int i = 0 ; i <= b.size(); i++){
    pre[i] = aCost*i;
  }
  for(int j=1 ; j <= a.size(); j++) {
    dis[0] = j*aCost;
    int minIdx = max(j - k, 1);
    int maxIdx = min(j + k, (int)b.size());
    if(minIdx > 1){
      dis[minIdx -1] = inf;
    }
    int minVal = inf;
    for(int i = minIdx ; i <= maxIdx ; i++){
      if(a[j-1] == b[i-1]){
  	dis[i] = pre[i-1];
      } else {
  	dis[i] = min(pre[i]+aCost, min(dis[i-1]+aCost, pre[i-1]+bCost));
      }
      if(dis[i] < minVal) minVal = dis[i];
    }
    swap(pre,dis);
    if(minVal > k) break;
  }
  if(pre[b.size()]<=k) return pre[b.size()];
  return -1;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string x,y;
    int k;
    scanf("%s",buffer);
    x=string(buffer);
    scanf("%s",buffer);
    y=string(buffer);
    scanf("%d %d %d",&aCost,&bCost,&k);
    //assert(!(k<aCost && k<bCost));
    int res=editDistance(x,y,k);
    if(res!=inf)
      printf("%d\n",res);
    else printf("-1\n");
  }
  //printf("%.6f",((double)clock()-start)/CLOCKS_PER_SEC);
  return 0;
}
