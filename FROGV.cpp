#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
typedef long long int ll;
ll A[NMAX];
int rank[NMAX],maxInd[NMAX];
inline void swap(int &x,int &y){
  int t;
  t=x,x=y,y=t;
}
int main(){
  int N,P;
  ll K;
  vector<ll> B;
  scanf("%d %lld %d",&N,&K,&P);
  for(int i=0;i<N;++i){
    scanf("%lld",&A[i]);
    B.push_back(A[i]);
  }      
  sort(B.begin(),B.end());
  B.erase(unique(B.begin(),B.end()),B.end());
  for(int i=0;i<N;++i){
    rank[i]= lower_bound(B.begin(),B.end(),A[i])-B.begin();
  }
  int best=B.size()-1;
  maxInd[best]=best;
  for(int i=B.size()-2;i>=0;--i){
    if(B[i+1]-B[i]>K) best=i;
    maxInd[i]=best;
    //cout<<B[i]<<"<<- "<<maxInd[i]<<endl;
  }
  for(int i=0;i<P;++i){
    int u,v;
    scanf("%d %d",&u,&v);
    --u,--v;
    int x,y;
    if(rank[u]<rank[v]) x=u,y=v;
    else x=v,y=u;
    if(rank[y]<=maxInd[rank[x]]) printf("Yes\n");
    else printf("No\n");
  }
  
  return 0;
}
