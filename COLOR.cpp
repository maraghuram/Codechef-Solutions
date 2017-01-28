#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  string rgb( "RGB" );
  while( T-- ){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int minCost = NMAX;
    for(int i=0;i<3;++i){
      int cost = 0;
      for(int j=0;j<s.size();++j){
        if( s[j] != rgb[i] ) ++cost;
      }
      minCost = min( minCost, cost );
    }
    cout << minCost << endl;
  }
  return 0;
}
