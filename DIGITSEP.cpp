#include <bits/stdc++.h>
#define NMAX 300
#define MMAX 10
using namespace std;
typedef long long int ll;
int N,M,X,Y;
string s;
ll maxGcd;
ll _gcd(ll a, ll b) {
    return b == 0 ? a : _gcd(b, a % b);
}
void dfs(int idx, int m, int counter, ll currGcd){
  //cout << idx << " " << m << " " << endl;
  if(currGcd == 1) return;
  if(idx>=N){
    --counter;
    if(counter >= X && counter <= Y)
      maxGcd = max(maxGcd, currGcd);
    return;
  }
  if(counter>Y) return;
  ll currVal = 0;
  for(int i=0;i<m;++i){
    if(idx+i>=N) break;
    currVal *= 10;
    currVal += s[idx+i]-'0';
  }
  if(currGcd < 0) currGcd = currVal;
  else currGcd = _gcd(currGcd, currVal);
  if(currGcd == 1) return;
  for(int i=1;i<=M;++i){
    dfs(idx+m, i, counter+1, currGcd);
  }
}
void solve(){
  maxGcd = 1;
  for(int i=0;i<=M;++i)
    dfs(0,i,0,-1);
  cout << maxGcd << endl;
}
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--){
    cin >> N;
    cin >> s;
    cin >> M >> X >> Y;
    solve();
  }
  return 0;
}
