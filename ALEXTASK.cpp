#include <bits/stdc++.h>
using namespace std;
int computeGcd( int x, int y ){
  int tmp;
  while( y > 0 ){
    tmp = x%y;
    x = y;
    y = tmp;
  }
  return x;
}
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while( T-- ){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;++i) cin >> a[i];
    unsigned long long int res = ULLONG_MAX;
    for(int i=0;i<N;++i){
      for(int j=i+1;j<N;++j){
	int gcd = computeGcd( a[i], a[j] );
	unsigned long long int mul, lcm;
	if( a[i] % gcd ){
	  mul = a[i]/gcd;
	  lcm = a[j]*mul;
	}
	else{
	  mul = a[j]/gcd;
	  lcm = a[i]*mul;
	}
	res = min( res, lcm );
      }
    }
    cout << res << endl;
  }
  return 0;
}
