#include <bits/stdc++.h>
#define NMAX 55
#define CMAX 111
using namespace std;
typedef double ld;
int query[NMAX];
ld prob[NMAX][CMAX];
int n,c,k;
void solve(){
  ld ci = ld(1)/c;
  ld res=0.0;
  ld exp=0.0;    
  for(int i=0;i<k+1;++i)
    for(int j=0;j<c;++j)
      prob[i][j]=0.0;
  prob[0][1]=1.0;
  
  for(int i=0;i<k+1;++i){
    for(int j=0;j<c;++j){
      if(prob[i][j]>0.0){
	prob[i+1][j] += (prob[i][j]/2.0);
	for(int col=0;col<c;++col){
	  int newCol = (col*j)%c;
	  prob[i+1][newCol] += ((ci)*(prob[i][j]/2.0));
	}
      }
      //cout<<prob[i][j]<<" ";
    }
    //cout<<endl;
  }
  for(int i=0;i<n;++i){
    int indx=query[i];
    exp=0.0;
    for(int j=0;j<c;++j) exp += (ld(j)*prob[indx][j]);
    res += exp;
    //cout<< query[i]<<" "<<exp << endl;
  }
  printf("%.9lf\n",res);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    memset(query,0,sizeof(query));
    scanf("%d %d %d",&n,&c,&k);
    for(int i=0;i<k;++i){
      int l,r;
      scanf("%d %d",&l,&r);
      --l,--r;
      for(int j=l;j<=r;++j) query[j] += 1;      
    }
    solve();
  }
  return 0;
}
