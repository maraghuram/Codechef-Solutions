// author noob333
// H + Shift C + B + E + B + E
#include <bits/stdc++.h>
#define NMAX 100002
#define EMAX 200002
#define gc getchar_unlocked
#define DEBUG 1
using namespace std;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
// Useful container manipulation / traversal macros
#define REP(i,a,b)                  for(int i=a;i<b;i++)
#define RREP(i,a,b)                 for(int i=a;i>b;i--)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define fi                          first
#define se                          second
// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
      if(!first)
	os << ", ";
      os << *ii ;
      first = false;
    }
  return os << "]";
}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int nodeDegree[NMAX], visited[NMAX];
vector<int> adjacencyList[NMAX];
int edgeStart[EMAX], edgeEnd[EMAX], direction[EMAX];
int nodeLastIndex[NMAX];
void eulerTour(int u){
  while(nodeLastIndex[u]<adjacencyList[u].size()){
    int idx=adjacencyList[u][nodeLastIndex[u]++];
    if(direction[idx] == 0){
      int st = edgeStart[idx], en = edgeEnd[idx];
      if(st == u){
	direction[idx] = +1;
	eulerTour(en);
      }
      else{
	direction[idx] = -1;
	eulerTour(st);
      }
    }
  }
}
void dfs(int u){
  visited[u] = 1;
  for(int i=0;i<adjacencyList[u].size();++i){
    int idx = adjacencyList[u][i];
    int st = edgeStart[idx], en = edgeEnd[idx];
    if(st == u){
      if(!visited[en]) dfs(en);
    }
    else{
      if(!visited[st]) dfs(st);
    }
  }    
}
int main(){
  //ios::sync_with_stdio(false);
  int N, E;
  //cin >> N >> E;
  //scanf("%d %d",&N,&E);
  scanint(N);
  scanint(E);
  for(int i=0;i<E;++i){
    int u,v;
    //cin >> u >> v;
    //scanf("%d %d",&u,&v);
    scanint(u);
    scanint(v);
    edgeStart[i] = u;
    edgeEnd[i] = v;
    adjacencyList[u].pb(i);
    adjacencyList[v].pb(i);
    nodeDegree[u]++;
    nodeDegree[v]++;
  }
  dfs(1);
  for(int i=1;i<=N;++i){
    if(!visited[i] || nodeDegree[i]%2){
      //cout << "NO" << endl;
      printf("NO\n");
      return 0;
    }
  }
  eulerTour(1);
  //cout << "YES" << endl;
  printf("YES\n");
  for(int i=0;i<E;++i){
    if(direction[i] == -1)
      printf("%d %d\n",edgeEnd[i], edgeStart[i]);
    else
      printf("%d %d\n",edgeStart[i], edgeEnd[i]);
  }
  
  return 0;
}
