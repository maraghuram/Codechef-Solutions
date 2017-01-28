#include <bits/stdc++.h>
#define NMAX 100002
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppi;
vector<ppi> xlines[NMAX];
vector<ppi> ylines[NMAX];
bool eventCompare( ppi i, ppi j ){
  return (i.first.first == j.first.first? i.first.second < j.first.second: i.first.first < j.first.first);
}
int bitTree[NMAX<<3];
inline void add( int index, int val ){
  for(int i=index; i<(NMAX<<3); i+= (i&-i))
    bitTree[i] += val;
}
inline int get( int index ){
  int result = 0;
  for(int i=index; i > 0; i-= (i&-i))
    result += bitTree[i];
  return result;
}
int signals[NMAX];
long long int counter;
void solve(){
  memset(bitTree, 0, sizeof(bitTree));
  vector<ppi> events;
  for(int i=1;i<NMAX;++i){
    for(int j=0;j<xlines[i].size();++j){
      events.push_back(ppi(pii(xlines[i][j].first.first,1),i));
      events.push_back(ppi(pii(xlines[i][j].first.first,4),i));
      events.push_back(ppi(pii(xlines[i][j].first.first,6),i));
      events.push_back(ppi(pii(xlines[i][j].first.second,3),i));
    }
  }
  
  for(int i=1;i<NMAX;++i){
    for(int j=0;j<ylines[i].size();++j){
      events.push_back(ppi(pii(i,2),j));
      events.push_back(ppi(pii(i,5),j));
    }
  }
  sort(events.begin(), events.end(), eventCompare);
  for(int i=0;i<events.size();++i){
    int xval = events[i].first.first;
    int type = events[i].first.second;
    if( type == 3 || type == 4 ){
      int yval = events[i].second;
      add( yval, -1 );
    }
    else if( type == 1 || type == 6 ){
      add( events[i].second, +1 );
    }
    else if( type == 2 ){
      int j = events[i].second;
      int l = ylines[xval][j].first.first + 1;
      int r = ylines[xval][j].first.second - 1;
      int ptr = ylines[xval][j].second;
      if(l<=r){
	int res = get(r)-get(l-1);
	counter += res;
	signals[ptr] += res;
      }
    }
    else{
      int j = events[i].second;
      int l = ylines[xval][j].first.first;
      int r = ylines[xval][j].first.second;
      int ptr = ylines[xval][j].second;
      int res = get(r)-get(r-1);
      counter += res;
      signals[ptr] += res;
	
      res = get(l)-get(l-1);
      counter += res;
      signals[ptr] += res;      
    }    
  }
}
int main(){
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for(int i=0;i<N;++i){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if( x1 == x2 )
      ylines[x1].push_back(ppi(pii(min(y1,y2),max(y1,y2)),i));
    else
      xlines[y1].push_back(ppi(pii(min(x1,x2),max(x1,x2)),i));
  }
  counter = 0;
  solve();
  long long int signalCount = counter;
  for(int i=1;i<NMAX;++i){
    swap( xlines[i], ylines[i] );
  }
  solve();
  cout << signalCount << endl;
  for(int i=0;i<N-1;++i) cout << signals[i] << " ";
  cout << signals[N-1] << endl;
  return 0;
}
