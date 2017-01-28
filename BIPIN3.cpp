#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll pow2( ll base, ll exp ){
  ll res = 1;
  while( exp ){
    if( exp & 1 ) res *= base, res %= MOD;
    base *= base, base %= MOD;
    exp >>= 1;
  }
  return res;
}
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
    int N,K;
    cin >> N >> K;
    if( K == 1 ){
      if( N == 1 ) cout << 1 << endl;
      else cout << 0 << endl;
    }
    else{
      ll result = K;
      result *= pow2( K-1, N-1 );
      result %= MOD;
      cout << result << endl;
    }
  }
}
