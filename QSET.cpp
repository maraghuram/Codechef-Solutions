// author noob333
// H + Shift C + B + E + B + E
#include <bits/stdc++.h>
#define NMAX 111111
//#define DEBUG 1
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
#define L(x)                        ((x<<1))
#define R(x)                        ((x<<1)+1)
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
struct node{
  int val[3];
  int lazy;
  node(){
    val[0] = val[1] = val[2] = 0;
    lazy = 0;
  }
}tree[NMAX<<2];
inline void oneswap(node &x){
  swap(x.val[0],x.val[1]);
  swap(x.val[0],x.val[2]);
}
int a[NMAX];
int mod3[NMAX];
char input[NMAX];
void merge(node &a,node b,node c){
  REP(i,0,3)
    a.val[i] = b.val[i] + c.val[i];
}
void build(int idx,int i,int j){
  if(i==j){
    REP(k,0,3) tree[idx].val[k]=0; tree[idx].lazy=0;
    tree[idx].val[mod3[i-1]]=1;
    return;
  }
  int mid=(i+j)>>1;
  build(L(idx),i,mid);
  build(R(idx),mid+1,j);
  merge(tree[idx],tree[L(idx)],tree[R(idx)]);
}
node get(int idx,int i,int j,int st,int en){
  //debug("GET",i,j);
  if(tree[idx].lazy){
    if(tree[idx].lazy%3){
      REP(k,0,tree[idx].lazy%3) oneswap(tree[idx]);
      if(i!=j){
  	tree[L(idx)].lazy += tree[idx].lazy;
  	tree[R(idx)].lazy += tree[idx].lazy;
      }
    }
    tree[idx].lazy=0;
  }
  if(i>en || j <st) return node();
  if(st<=i && j<=en) return tree[idx];
  //if(i==st && j==en) return tree[idx];
  int mid=(i+j)>>1;
  node res,r1,r2;
  r1=get(L(idx),i,mid,st,en);
  r2=get(R(idx),mid+1,j,st,en);
  merge(res,r1,r2);
  //debug("***",vi(res.val,res.val+3),"***");
  return res;
}
void add(int idx,int i,int j,int st,int en,int newMod){
  if(tree[idx].lazy){
    if(tree[idx].lazy%3){
      REP(k,0,tree[idx].lazy%3) oneswap(tree[idx]);
      if(i!=j){
	tree[L(idx)].lazy += tree[idx].lazy;
	tree[R(idx)].lazy += tree[idx].lazy;
      }
    }
    tree[idx].lazy=0;
  }
  if(i>en || j<st) return;
  if(st<=i && j<=en){
    REP(k,0,newMod) oneswap(tree[idx]);
    if(i!=j){
      tree[L(idx)].lazy += newMod;
      tree[R(idx)].lazy += newMod;
    }
    return;
  }
  int mid = (i+j)>>1;
  add(L(idx),i,mid,st,en,newMod);
  add(R(idx),mid+1,j,st,en,newMod);
  merge(tree[idx],tree[L(idx)],tree[R(idx)]);
}
 
void printTree(int idx,int i,int j){
  if(i==j){
    //debug(i,j,vi(tree[idx].val,tree[idx].val+3),tree[idx].lazy);
    return;
  }
  int mid = (i+j)>>1;
  printTree(L(idx),i,mid);
  printTree(R(idx),mid+1,j);
  //debug(i,j,vi(tree[idx].val,tree[idx].val+3),tree[idx].lazy);
}
int main(){
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  cin >> input;
  int tot = 0;
  REP(i,0,n){
    a[i] = (input[i]-'0')%3;
    tot += input[i]-'0';
    tot %= 3;
    mod3[i] = tot;
    //add(tot,i+1,1);
  }
  build(1,1,n);
  REP(i,0,m){
    int ty,u,v;
    cin >> ty >> u >> v;
    if(ty==1){
      v %= 3;
      //debug("-->",a[u-1],v,"<--");
      if(a[u-1]==v) continue;
      else{
      	int delta = (v-a[u-1]+3)%3;
	add(1,1,n,u,n,delta);
	// REP(j,0,3){
      	//   cur[j] = get(j,n)-get(j,u-1);
      	//   add(j,u,-cur[j]);
      	// }
      	// REP(j,0,3) add(j,u,cur[(j+delta)%3]);
      	// //add(a[u-1],u,-1);
      	// //add(v,u,1);
      	a[u-1] = v;
      }
    }
    else{
      ll ans = 0;
      node res= get(1,1,n,u,v);
      REP(j,0,3){
	ans += ((ll)res.val[j]*((ll)res.val[j]-1))/2;
      }
      //debug(vi(res.val,res.val+3));
      int prevMod = 0;
      if(u>1){
	node tmp = get(1,1,n,u-1,u-1);
	REP(j,0,3){
	  if(tmp.val[j]>0){
	    prevMod = j;
	    break;
	  }
	}
      }
      //debug(prevMod);
      ans += res.val[prevMod];
      cout << ans << endl;
    }
    //debug('\n');
    //printTree(1,1,n);
  }
  return 0;
}
