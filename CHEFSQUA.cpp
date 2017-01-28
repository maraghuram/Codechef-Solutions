#include <bits/stdc++.h>
#define NMAX 2222
#define x first
#define y second
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;
typedef pair<pi,pi> ppii;
pi a[NMAX];
set<pi> check;
inline ll dist(int x1,int y1,int x2,int y2){
  ll res = (x1-x2);
  res *= (x1-x2); res += (y1-y2)*(y1-y2);
  return res;
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    scanf("%d %d",&a[i].x,&a[i].y);
    check.insert(a[i]);
  }
  assert(n==check.size());
  if(n==0){
    printf("%d\n",4);
    return 0;
  }
  else if(n==1){
    printf("%d\n",3);
    return 0;
  }
  int x1,x2,y1,y2;
  int best=0;
  ll a2;
  ppii p1,p2;
  pi t1,t2,t3,t4;
  int above,below;
  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      x1=a[i].x;x2=a[j].x;y1=a[i].y;y2=a[j].y;
      a2 = dist(x1,y1,x2,y2);
      t1=pi(x1+(y2-y1),y1+(x1-x2));
      t2=pi(x1-(y2-y1),y1-(x1-x2));
      t3=pi(x2+(y2-y1),y2+(x1-x2));
      t4=pi(x2-(y2-y1),y2-(x1-x2));
      if(dist(t1.x,t1.y,t3.x,t3.y)==a2){
	p1.x=t1; p1.y=t3; p2.x=t2; p2.y=t4;
      }
      else{
	assert(dist(t1.x,t1.y,t4.x,t4.y)==a2);
	p1.x=t1; p1.y=t4; p2.x=t2; p2.y=t3;
      }
      above=below=0;
      if(check.find(p1.x)!=check.end()) ++above;
      if(check.find(p1.y)!=check.end()) ++above;
      if(check.find(p2.x)!=check.end()) ++below;
      if(check.find(p2.y)!=check.end()) ++below;
      best=max(best,max(above,below)+2);
    }
  }
  printf("%d\n",4-best);
  return 0;
}
