#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio( false );
  int T;
  
  cin >> T;
  while( T-- ){
    int s,v;
    cin >> s >> v;
    
    double tmp = (2.0/3.0) * s;
    cout << setprecision (6) << fixed << tmp/v << endl;
  }
}
