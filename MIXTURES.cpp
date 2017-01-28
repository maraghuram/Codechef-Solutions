#include <bits/stdc++.h>
#define NMAX 111
#define INF 9999999
using namespace std;
int mix[NMAX][NMAX];
int color[NMAX][NMAX];
int input[NMAX];
int N;
void init(){
  for(int i=0;i<N;++i){
    color[i][i]=input[i];
    for(int j=i+1;j<N;++j)
      color[i][j]=(color[i][j-1]+input[j])%100;
  }
}
void solve(){
    for(int i=0;i<N;++i) mix[i][i]=0;
    for(int sz=2;sz<=N;++sz){
      for(int i=0;i<N;++i){
	int j=i+sz-1;
	if(j>=N) break;
	mix[i][j]=INF;
        for(int k=i;k<j;++k)
	  mix[i][j]=min(mix[i][j],mix[i][k]+mix[k+1][j]+color[i][k]*color[k+1][j]);
      }
    }
    printf("%d\n",mix[0][N-1]);
}
int main(){
  //int T;
  //scanf("%d",&T);
  while(scanf("%d",&N)>0){
    //scanf("%d",&N);
    for(int i=0;i<N;++i) scanf("%d",&input[i]);
    init();
    solve();
  }
  return 0;
}
