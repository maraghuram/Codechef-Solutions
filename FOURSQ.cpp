#include <bits/stdc++.h>
#define NMAX 1000000
#define SMAX 100000
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const ull ten11 = 100000000000LL;
const ull ten10 = 10000000000LL;
const ull ten9  = 1000000000LL;
const int ten3  = 1000;
const int ten6  = 1000000;
vector<int> squares;
vector<int> splits[NMAX+1];
int sqRoot[NMAX+1], input[SMAX+1], fourSquares[NMAX+1];
ll MOD;
int check(int x,int depth){
if(x>NMAX) assert(false);
if(depth>3) return 0;
if(fourSquares[x] == 1 ) return 1;
int pos = upper_bound(squares.begin(),squares.end(),x)-squares.begin()-1;
if(squares[pos] == x){
fourSquares[x] = 1;
splits[x].push_back(x);
return 1;
}
while(pos>=0){
if(check(x-squares[pos], depth+1)){
if(splits[x-squares[pos]].size()<=3){
for(int i=0;i<splits[x-squares[pos]].size();++i)
splits[x].push_back(splits[x-squares[pos]][i]);
splits[x].push_back(squares[pos]);
//splits[x].push_back(squares[pos]);
//splits[x].push_back(x-squares[pos]);
fourSquares[x] = 1;
return 1;
}
}
--pos;
}
//assert(false);
return 0;
}
struct node{
ll a,b,c,d;
node(): a(0), b(0), c(0), d(0) {};
node(ll _a, ll _b, ll _c, ll _d): a(_a), b(_b), c(_c), d(_d) {};
}tree[SMAX<<3];
inline ull mulmod(ull A, ull B)
{
  register int x1,y1,x2,y2;
  register ull res;
  x1 = A/ten3;
  y1 = (A-(x1*ten3));
  x2 = B/ten3;
  y2 = (B-(x2*ten3));
  res = ((ull)x1*x2);
  if(res>=MOD) res %= MOD;
  res *= ten6;
  ull tmp = ((ull)x1*y2*ten3) + ((ull)x2*y1*ten3) + (y1*y2);
  res += tmp;
  if(res>=MOD) res %= MOD;
  // register ull x1,y1,res;
  // register ull x2,x3,y2,y3;
  // x3 = A/ten11;
  // x2 = (A-(x3*ten11))/ten10;
  // x1 = (A-(x3*ten11)-(x2*ten10));
  // y3 = B/ten11;
  // y2 = (B-(y3*ten11))/ten10;
  // y1 = (B-(y3*ten11)-(y2*ten10));
  // res = (x1*y1);
  // if(res>=MOD) res %= MOD;
  // ull tmp = (y1*ten9);
  // if(tmp>=MOD) tmp %= MOD;
  // tmp *= (10*x2+100*x3);
  // if(tmp>=MOD) tmp %= MOD;
  // res += tmp;
  // if(res>=MOD) res -= MOD;
  // res += ((y1*ten9))*(10*x2+100*x3);
  // res += ((x1*ten9))*(10*y2+100*y3);
  //res += ((x2+10*x3)*y1*1000);
//res += ((y2+10*y3)*x1*1000)%MOD;
  //res += ((((x1*y2 + y1*x2 + 10*x1*y3 + 10*y1*x3)*1000)%MOD)*10000000LL)%MOD;
  // //res += ((((((x2*y2 + 10*x2*y3 + 10*x3*y2 + 100*x3*y3)*ten10)%MOD)*100000)%MOD)*100000)%MOD;
  // res %= MOD;
  // if ( A == 0 || B == 0 ) return 0;
  // if ( 128-__builtin_clzll(A)-__builtin_clzll(B) <= 64 ) return (A*B)%MOD;
  // ull u = multiply(A, B>>1);
  // ull res = 0;
  // u <<= 1;
  // res += u;
  // if ( B&1 )
  //   res += A;
  //res %= MOD;
  return res;
}
// ull hand_multiply(ull a, ull b) {
//    if(b == 0 || b<=10000000) {
//      return (a*b)%MOD;
//    }
//    else {
//      ll result = (hand_multiply(a, b/10)*10)%MOD;
//      ll lastDigit = b%10;
//      result = (result+((a*lastDigit)))%MOD;
//      return result;
//    }
// }
//long long mulmod(long long A, long long B){
// if(A == 0 || LLONG_MAX/A >= B)
// return (A*B)%MOD;
//return multiply(max(A,B), min(A,B));
//}
// inline ll mulmod(ll a, ll b) {
// if(a == | LLONG_MAX/a >= b)
// return (a*b)%MOD;
// ll res = 0;
// while (a != 0) {
// if (a & 1) res = (res + b) % MOD;
// a >>= 1;
// b = (b << 1) % MOD;
// }
// return res;
// }
inline node splitToNode(int x){
vector<int> splitX = splits[x];
if(splitX.size()==1) return node(sqRoot[splitX[0]], 0, 0, 0);
else if(splitX.size()==2) return node(sqRoot[splitX[0]], sqRoot[splitX[1]], 0, 0);
else if(splitX.size()==3) return node(sqRoot[splitX[0]], sqRoot[splitX[1]], sqRoot[splitX[2]], 0);
else return node(sqRoot[splitX[0]], sqRoot[splitX[1]], sqRoot[splitX[2]], sqRoot[splitX[3]]);
}
inline node merge(node x, node y){
  register ll a,b,c,d;
  a = mulmod(x.a,y.a);
  a += mulmod(x.b,y.b); if(a>=MOD) a-= MOD;
  a += mulmod(x.c,y.c); if(a>=MOD) a-= MOD;
  a += mulmod(x.d,y.d); if(a>=MOD) a-= MOD;
  b = mulmod(x.a,y.b);
  b -= mulmod(x.b,y.a); if(b<0) b += MOD;
  b += mulmod(x.c,y.d); if(b>=MOD) b -= MOD;
  b -= mulmod(x.d,y.c); if(b<0) b += MOD;
  c = mulmod(x.a,y.c);
  c -= mulmod(x.c,y.a); if(c<0) c += MOD;
  c += mulmod(x.d,y.b); if(c>=MOD) c -= MOD;
  c -= mulmod(x.b,y.d); if(c<0) c += MOD;
  d = mulmod(x.a,y.d);
  d -= mulmod(x.d,y.a); if(d<0) d += MOD;
  d += mulmod(x.b,y.c); if(d>=MOD) d -= MOD;
  d -= mulmod(x.c,y.b); if(d<0) d += MOD;
// ll a = mulmod(x.a,y.a) + mulmod(x.b,y.b) + mulmod(x.c,y.c) + mulmod(x.d,y.d);
// ll b = mulmod(x.a,y.b) - mulmod(x.b,y.a) + mulmod(x.c,y.d) - mulmod(x.d,y.c);
// ll c = mulmod(x.a,y.c) - mulmod(x.c,y.a) + mulmod(x.d,y.b) - mulmod(x.b,y.d);
// ll d = mulmod(x.a,y.d) - mulmod(x.d,y.a) + mulmod(x.b,y.c) - mulmod(x.c,y.b);
//  a = a%MOD;
//  if(a<0) a+= MOD;
// b = b%MOD;
// if(b<0) b+= MOD;
// c = c%MOD;
// if(c<0) c+= MOD;
// d = d%MOD;
// if(d<0) d+= MOD;
return node(a,b,c,d);
}
void init(int idx, int i, int j){
if(i==j){
tree[idx] = splitToNode(input[i-1]);
return;
}
int mid = (i+j)>>1;
init(L(idx),i,mid);
init(R(idx),mid+1,j);
tree[idx] = merge(tree[L(idx)],tree[R(idx)]);
}
void update(int idx, int i, int j, int pos, int Y){
if(i==j && i==pos){
tree[idx] = splitToNode(Y);
return;
}
int mid=(i+j)>>1;
if(pos<=mid) update(L(idx),i,mid,pos,Y);
else update(R(idx),mid+1,j,pos,Y);
tree[idx] = merge(tree[L(idx)],tree[R(idx)]);
}
node query(int idx, int i, int j, int left, int right){
if(i==left && j==right) return tree[idx];
int mid = (i+j)>>1;
if(right<=mid) return query(L(idx),i,mid,left,right);
else if(left>mid) return query(R(idx),mid+1,j,left,right);
else{
return merge(query(L(idx),i,mid,left,mid)
,query(R(idx),mid+1,j,mid+1,right));
}
}
int main(){
  //ios::sync_with_stdio(false);
//clock_t start = clock();
for(int a=0;a*a<=NMAX;++a){
squares.push_back(a*a);
sqRoot[a*a]=a;
}
for(int i=0;i<=NMAX;++i){
  check(i,0);
// int s=0;
// for(int j=0;j<splits[i].size();++j)
// s += splits[i][j];
// if(splits[i].size()==0 || splits[i].size()>4 || s != i)
// assert(false);
}
int T;
//cin >> T;
 scanf("%d",&T);
while(T--){
int N,Q;
//cin >> N >> Q >> MOD;
 scanf("%d %d %lld", &N, &Q, &MOD);
 for(int i=0;i<N;++i) scanf("%d", &input[i]);
  // cin >> input[i];
//for(int i=0;i<N;++i) check(input[i], 0);
init(1,1,N);
for(int i=0;i<Q;++i){
int type, u, v;
//cin >> type >> u >> v;
 scanf("%d %d %d", &type, &u, &v);
if(type == 1){
  //check(v, 0);
update(1,1,N,u,v);
}
else{
node res = query(1,1,N,u,v);
//cout << res.a << " " << res.b << " " << res.c << " " << res.d << endl;
 printf("%lld %lld %lld %lld\n", res.a, res.b, res.c, res.d);
}
}
}
//clock_t stop = clock();
//cout << (stop - start)*1.0 / CLOCKS_PER_SEC << endl;
return 0;
}
