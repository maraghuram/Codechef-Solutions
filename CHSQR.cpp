#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio( false );
  int T;
  cin >> T;
  while( T-- ){
    int K;
    cin >> K;
    if( K == 1 ){
      cout << 1 << endl;
      continue;
    }
    vector<vector<int> > a(K, vector<int>(K));
    for(int i=0;i<K;++i)
      for(int j=0;j<K;++j)
	a[i][j] = (j-i+K)%K;
    for(int i=0,j=K/2-1;i<j;++i,--j)
      swap( a[i], a[j] );
    for(int i=K/2,j=K-1;i<j;++i,--j)
      swap( a[i], a[j] ); 
    //swap( a[K/2], a[K/2+1] );
    for(int i=0;i<K;++i){
      for(int j=0;j<K-1;++j)
	cout << a[i][j] + 1 << " ";
      cout << a[i][K-1] + 1 << endl;
    }
  }
  return 0;
}
