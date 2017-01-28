#include <bits/stdc++.h>
#define SMAX 11
#define NMAX 111111
#define inf 99999
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
pii dist[SMAX];
char input[NMAX];
void solve1();
int main(){
  solve1();
  return 0;
}
void solve1(){
  int len;
  
  for(int i=0;i<SMAX;++i) dist[i]=pii(inf,inf);
  
  scanf("%s",input);
  
  len=strlen(input);
  dist[input[0]-'0'].x=dist[input[0]-'0'].y=0;
  for(int T=0;T<50;++T){
  for(int i=1;i<len-1;++i){
    int prevNum=input[i-1]-'0';
    int num=input[i]-'0';
    int nextNum=input[i+1]-'0';
    
    int currDist=(dist[num].y==i?0:1);
    currDist+=dist[num].x;
    
    int prevdist=(dist[prevNum].y==i-1?0:1);
    prevdist+=dist[prevNum].x+1;
    if(prevdist<currDist) dist[num].x=prevdist,dist[num].y=i;
    
    currDist=(dist[num].y==i?0:1);
    currDist+=dist[num].x;
    
    int nextDist=(dist[nextNum].y==i+1?0:1);
    nextDist+=dist[nextNum].x+1;
    if(nextDist<currDist) dist[num].x=nextDist,dist[num].y=i;
    
    currDist=(dist[num].y==i?0:1);
    currDist+=dist[num].x;    
    
    int prevDist=(dist[prevNum].y==i-1?0:1);
    prevDist+=dist[prevNum].x;
    
    nextDist=(dist[nextNum].y==i+1?0:1);
    nextDist+=dist[nextNum].x;
    
    if(nextDist>currDist+1) dist[nextNum].x=currDist+1,dist[nextNum].y=i+1;
    if(prevDist>currDist+1) dist[prevNum].x=currDist+1,dist[prevNum].y=i-1;
    
  }
  if(len>1) {
    int prevDist=(dist[input[len-2]-'0'].y==len-2?0:1);
    prevDist+=dist[input[len-2]-'0'].x+1;
    int currDist=(dist[input[len-1]-'0'].y==len-1?0:1);
    currDist+=dist[input[len-1]-'0'].x;
    if(currDist>prevDist) dist[input[len-1]-'0'].x=prevDist,dist[input[len-1]-'0'].y=len-1;
  }
  }
  //printf("%d\n",dist[1].x);
  printf("%d\n",(dist[input[len-1]-'0'].y==len-1?dist[input[len-1]-'0'].x:dist[input[len-1]-'0'].x+1));
  
  
  //return 0;
}
