#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N,M;
    scanf("%d %d",&N,&M);
    vector<int> input(N),flag(N,0);
    vector<pii> intervals;
    for(int i=0;i<N;++i) scanf("%d",&input[i]);
    for(int i=0;i<M;++i){
      int u,v;
      scanf("%d %d",&u,&v);
      intervals.push_back(pii(u,v));
    }
    sort(intervals.begin(),intervals.end());
    stack<pii> s;
    s.push(intervals[0]);
    for(int i=1;i<M;++i){
      pii t = s.top();
      if( intervals[i].first > t.second )
	s.push(intervals[i]);
      else if( intervals[i].second > t.second ){
	t.second=intervals[i].second;
	s.pop();
	s.push(t);
      }
    }
    int poss=1;
    while(!s.empty()){
      pii curr = s.top();
      s.pop();
      for(int i=curr.first;i<=curr.second;++i){
	if( input[i-1]>curr.second || input[i-1]<curr.first ){
	  poss=0;
	  break;
	}
	flag[i-1]=1;
      }
    }
    if(!poss) printf("Impossible\n");
    else{
      
      for(int i=0;i<N;++i)
	if(flag[i]==0 && input[i]!=i+1){
	  poss=0;
	  break;
	}
      if(poss) printf("Possible\n");
      else printf("Impossible\n");
    }
  }
  return 0;
}
