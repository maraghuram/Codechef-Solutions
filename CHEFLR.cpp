#include <bits/stdc++.h>
#define NMAX 111111
#define MOD 1000000007
using namespace std;
typedef long long int ll;
char buffer[NMAX];
ll modpow( int base, int exp ){
  ll res=1;
  ll b = (ll) base;
  while( exp > 0 ){
    if( exp&1 ) res = ( res * b ) % MOD; 
    b = ( b * b ) % MOD;
    exp >>= 1;
  }
  return res;
}
int main(){
  //cout << modpow(2,4) << " " << modpow(2,5) << " " << modpow(2,6)<< endl;
  int T;
  scanf("%d\n",&T);
  while(T--){
    scanf("%s",buffer);
    int n = strlen( buffer )+1;
    ll ignore = 0;
    for(int i=0;i<n;++i){
      if( buffer[i] == 'r' ) {
	ignore += modpow( 2, n-i-2 );
	ignore %= MOD;
      }
    }
    ll upto = 0;
    ll start;
    if( n%2 ) start = 1;
    else start = 2;
    while( start < n ){
      upto += modpow( 2, start-1 );
      upto %= MOD;
      start +=2 ;
    }
    //cout << ignore << " " << upto << endl;
    ll res = ( ( ( ignore + upto ) %MOD ) * 2 ) %MOD;
    res = ( res + (n%2?1:2) ) %MOD;
    printf("%lld\n", res );
  }
  return 0;
}
