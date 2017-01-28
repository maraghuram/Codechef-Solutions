#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
      string L1,L2,L3;
      long long int N;
      cin >> L1 >> L2 >> L3 >> N;
      long long int result = 0;
      for(int i=0;i<L1.size();++i)
    	  result += (L1[i] == '1' ? 1:0);
      for(int i=0;i<L3.size();++i)
    	  result += (L3[i] == '1' ? 1:0);
      for(int i=0;i<L2.size();++i)
    	  result += (L2[i] == '1' ? N:0);
      if( result == 0 ){
    	  cout << result << endl;
		  continue;
      }
      //cout << "init:" << result << endl;
      int check=L3.size()-1;
      while( check >=0 ){
    	  if( L3[check] == '0' ) break;
    	  -- result, -- check;
      }
      if( check >= 0 ){
    	  cout << result + 1 << endl;
    	  continue;
      }
      check = L2.size()-1;
      long long int tmp = 0;
      while( check >=0 ){
    	  if( L2[check] == '0' ) break;
    	  ++ tmp, -- check;
      }
      if( check >= 0 ){
    	  result -= tmp;
    	  cout << result + 1 << endl;
    	  continue;
      }
      result -= (N*tmp);
      check = L1.size()-1;
      while( check >=0 ){
    	  if( L1[check] == '0' ) break;
    	  -- result, -- check;
      }
      cout << result + 1 << endl;
  }
  return 0;
}
