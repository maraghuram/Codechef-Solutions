#include <bits/stdc++.h>
using namespace	std;
int main(){
  ios::sync_with_stdio(	false );
  int T;
  cin >> T;
  while( T-- ){
    long long int R,G,B,K, res = 0;
    cin >> R >> G >> B >> K;
    res += min( K-1, R );
    res	+= min( K-1, G );
    res	+= min( K-1, B );
    cout << res + 1 << endl;
  }
  return 0;
}
