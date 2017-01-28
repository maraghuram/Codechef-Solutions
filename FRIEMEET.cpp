#include <bits/stdc++.h>
#define NMAX 555555
using namespace std;
typedef pair<int,int> pii;
typedef long long int ull;
ull computeGcd(ull a, ull b)
{
    if (a == 0)
        return b;
    return computeGcd(b%a, a);
}
ull trigger;
int N,M;
int cost[NMAX], friendly[NMAX], subtree[NMAX];
vector<pii> adj[NMAX];
int dfs( int u, int par, int edgeCost ){
  cost[u] = edgeCost;
  subtree[u] = 0;
  if( friendly[u] ) subtree[u] = 1;
  for(int i=0;i<adj[u].size();++i){
    int next = adj[u][i].first, val = adj[u][i].second;
    if( next != par )
      subtree[u] += dfs( next, u, val );
  }
  
  return subtree[u];
}
ull solve(){
  ull result = 0;
  dfs( 1, -1, 0 );
  for(int i=2;i<=N;++i){
    ull inSubtree = subtree[i];
    ull outOfSubtree = M - subtree[i];
    ull edgeInPaths = cost[i];
    edgeInPaths *= inSubtree;
    edgeInPaths *= outOfSubtree;
    result += edgeInPaths;
    if( result > trigger ) assert(false);
  }
  ull allPairs = ((ull)M)*M;
  result *= 2;
  ull gcd = computeGcd( result, allPairs );
  result /= gcd;
  allPairs /= gcd;
  cout << result << " " << allPairs << endl;
  //cout << result/gcd << " "  << allPairs/gcd << endl;
}
void resetVectors(){
  for(int i=1; i<=N; ++i)
    cost[i] = 0, friendly[i] = 0, subtree[i] = 0, adj[i].clear();  
}
int main(){
  ios::sync_with_stdio(false);
  trigger = 1;
  for(int i=0;i<18;++i) trigger *= 10;
  int T;
  cin >> T;
  while( T-- ){  
    cin >> N >> M;    
    resetVectors();
    for(int i=0;i<N-1;++i){
      int u,v,w;
      cin >> u >> v >> w;
      
      adj[u].push_back(pii(v,w));
      adj[v].push_back(pii(u,w));
    }
    for(int i=0;i<M;++i){
      int x;
      cin >> x;
      friendly[x] = 1;
    }
    
    solve();
  }
  return 0;
}
