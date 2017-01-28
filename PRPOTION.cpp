#include <bits/stdc++.h>
#define inf 1000000011
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int maxR,maxG,maxB,res;
    int R,G,B,M,tmp;
    maxR=maxG=maxB=0;
    scanf("%d %d %d %d",&R,&G,&B,&M);
    for(int i=0;i<R;++i){
      scanf("%d",&tmp);
      maxR=max(maxR,tmp);
    }
    for(int i=0;i<G;++i){
      scanf("%d",&tmp);
      maxG=max(maxG,tmp);
    }
    for(int i=0;i<B;++i){
      scanf("%d",&tmp);
      maxB=max(maxB,tmp);
    }
    res=max(maxR,max(maxB,maxG));
    for(int i=0;i<M;++i){
      if(maxR>=maxG && maxR>=maxB){
    	  maxR/=2;
      }
      else if(maxG>=maxR && maxG>=maxB){
    	  maxG/=2;
      }
      else{
    	  maxB/=2;
      }
      res = min(res,max(maxR,max(maxG,maxB)));
    }
    printf("%d\n",res);
  }
  return 0;
}
