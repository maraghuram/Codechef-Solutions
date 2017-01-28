#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
    int N,M;
    cin >> N >> M;
    
    if( N%2 && M%2 ) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}
