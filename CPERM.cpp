#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll powmod( ll base, ll exp ){
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
    int N;
    cin >> N;
    
    if( N < 2 ){
      cout << 0 << endl;
      continue;
    }
    cout << (powmod( 2, N-1 )+MOD-2)%MOD << endl;
  }
  return 0;
}
