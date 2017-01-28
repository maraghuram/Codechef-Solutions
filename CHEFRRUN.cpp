#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
vector<int> adj[NMAX];
stack<int> connectedVertices;
int disc[NMAX],low[NMAX],onstack[NMAX];
int result = 0;
int cdisc = 1;
void dfs( int u ){
  disc[u] = cdisc;
  low[u] = cdisc++;
  onstack[u] = 1;
  connectedVertices.push( u );
  for(int i=0;i<adj[u].size();++i){
    int v = adj[u][i];
    if( !disc[v] ){
      dfs( v );
      low[u] = min( low[u], low[v] );
    }
    else if( onstack[v] ){
      low[u] = min( low[u], disc[v] );
    }
  }
  if( disc[u] == low[u] ){
    if( connectedVertices.top() != u ) result++;
    while( connectedVertices.top() != u ){
      result++;
      onstack[ connectedVertices.top() ] = 0;
      connectedVertices.pop();
    }
    onstack[ connectedVertices.top() ]=0;
    connectedVertices.pop();
  }
}
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    
    connectedVertices = stack<int>();
    result = 0;
    cdisc = 0;
    for(int i=1;i<=N;++i) disc[i]=low[i]=onstack[i]=0, adj[i].clear();
    for(int i=0;i<N;++i){
      int nxt = ((i+A[i]+1)%N);
      if( nxt == i ) ++result;
      else adj[i+1].push_back( nxt + 1 );
    }
    for(int i=1;i<=N;++i){
      if( !disc[i] ) 
	dfs( i );
    }
    
    cout << result << endl;
  }
  return 0;
}
