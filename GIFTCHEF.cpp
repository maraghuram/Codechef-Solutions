#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
//typedef unsigned long long ull;
typedef long long int ll;
ll hash(const string & s)
{
  ll ret = 0;
  for(int i = 0; i < s.size(); ++i){
    ret *= 257;
    ret += s[i];
    ret %= MOD;
  }
  return ret;
}
ll pow2(ll base, ll exp){
  ll res = 1;
  while( exp > 0 ){
    if( exp & 1 ) res *= base, res %= MOD;
    base *= base, base %= MOD;
    exp >>= 1;
  }
  return res;
}
vector<int> rollingHashMatch(const string& needle, const string& haystack)
{
  vector<int> isMatch(haystack.size(),0);
  ll hash1 = hash(needle);
  ll hash2 = 0;
  ll maxCoff = pow2( 257, needle.size() );
  
  for (int i = 0; i < haystack.size(); i++){
    hash2 = hash2 * 257 + haystack[i];
    hash2 %= MOD;
    if (i >= needle.size()){
      hash2 -= (maxCoff * haystack[i-needle.size()])%MOD;
      hash2 += MOD, hash2 %= MOD;
    }
    
    if (i >= needle.size()-1 && hash1 == hash2)
      isMatch[i] = 1;
  }
  
  return isMatch;
}
ll solve(const string& needle, const string& haystack){
  int n = needle.size();
  vector<int> matches = rollingHashMatch( needle, haystack );
  vector<ll> dp(haystack.size(),0), cumulativeDp(haystack.size(),0);
  for(int i=0;i<haystack.size();++i){
    dp[i] = 0;
    if( matches[i] ){
      //cout << "HERE" << i << endl;
      ll res = 1;
      if( i - n >= 0 ) res += cumulativeDp[i-n], res %= MOD;
      dp[i] = res;      
    }
    cumulativeDp[i] = dp[i];
    if( i > 0 ) cumulativeDp[i] += cumulativeDp[i-1], cumulativeDp[i] %= MOD;
  }
  return cumulativeDp[haystack.size()-1];
}
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
    string haystack,needle;
    cin >> haystack >> needle;
    cout << solve( needle, haystack ) << endl;
  }
  
  return 0;
}
