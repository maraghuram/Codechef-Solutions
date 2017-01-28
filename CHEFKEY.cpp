#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  int T;
  
  cin >> T;
  while( T-- ){
      int n,m,c, res = 0;
      cin >> n >> m >> c;
      
      for(int i=1; i*i <= c; ++i ){
	if( c%i == 0 ){
	  int h = i, w = c/i;
	  if( h <= n && w <= m ) ++res;
	  if( h != w ){
	    swap( h, w );
	    if( h <= n && w <= m ) ++res;
	  }
	}
      }
      
      cout << res << endl;
  }
  
}
