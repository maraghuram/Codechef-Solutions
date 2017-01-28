#include <bits/stdc++.h>
#define NMAX 11111
using namespace std;
int par[NMAX],best[NMAX],sz[NMAX];
int N;
int find(int x){
  if( par[x] == -1) return x;
  else par[x]=find(par[x]);
}
int join(int x,int y){
  par[x]=y;
  best[y]=max(best[y],best[x]);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
      par[i]=-1;
      sz[i]=1;
      scanf("%d",&best[i]);
    }
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;++i){
      int t;
      scanf("%d",&t);
      if(t==0){     
	int u,v;
	scanf("%d %d",&u,&v);
	int x,y;
	x=find(u);
	y=find(v);
	if(x==y) printf("Invalid query!\n");
	else if( best[x]<best[y] ) join(x,y);
	else if( best[y]<best[x] ) join(y,x);	
      }
      else{
	int u;
	scanf("%d",&u);
	printf("%d\n",find(u));
      }
      
    }
  }
  return 0;
}
