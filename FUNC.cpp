#include <bits/stdc++.h>
#define NMAX 11111
#define MOD 1000000007
#define pb push_back
using namespace std;
typedef long long int ll;
const ll MAXVAL = 1000000000000000000LL;
vector<ll> powers[65];
void pre_compute( ) {
  for( int i = 3; i<65; ++i ) powers[i].pb( (ll)1 );
  for( ll i = 2; i<=1000000; ++i ) {
    ll cnt,prod;
    cnt = 2;
    prod = i*i;
    while( i <= MAXVAL / prod ) {
      ++cnt;
      prod = prod * i;
      powers[cnt].pb( prod );
    }
  }
}
ll power( ll n, ll exp ) {
  ll res = 1;
  while( exp > 0 ){
    if( exp%2 ) res = res * n, exp = exp-1;
    else n = n * n, exp = exp>>1;
  }
  return res;
}
int main() {
  pre_compute();
  
  int T;
  scanf( "%d", &T );
  while( T-- ) {
    int N, Q;
    scanf( "%d %d", &N, &Q );
    
    vector<ll> A(N+5), B(N+5);
    B[0]=0;
    for(int i=1;i<=N;++i) {
      scanf("%lld",&A[i]);
      B[i]=B[i-1]+A[i];
      A[i]=A[i]%MOD;
      if( A[i] < 0 ) A[i] += MOD;
    }
    for(int i=0;i<Q;++i){
      ll x,res;
      int j;
      scanf("%lld",&x);
      
      res=0;
      for(j=1;j<=N;++j){
	ll root;
	
	if( j==1 ) root = x;
	else if( j==2 ) root = (ll) sqrt(x);
	else{
	  ll index = (ll) ( upper_bound( powers[j].begin(), powers[j].end(), x ) - powers[j].begin()  + 3 ); 
	  while( pow(index, j) > x ) --index;
	  root = index;
	}
	
	if( root == 1 ) break;
	
	root = root % MOD;
	res = ( res + ( root * A[j] ) %MOD ) % MOD;
      }
      ll temp = ( B[N] - B[j-1] ) % MOD;
      if( temp < 0 ) temp += MOD;
      res = ( res + temp ) % MOD;
      if( res < 0 ) res += MOD;
      printf("%lld",res);
      if(i < Q-1 ) printf(" ");
    }
    
    printf("\n");
  }
 
  return 0;
}
