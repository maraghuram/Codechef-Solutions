#include <bits/stdc++.h>
#define NMAX 111111
#define MOD 1000000007
#define MOD2INV 500000004
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
using namespace std;
typedef long long int ll;
template <typename T>
inline T fpow( T base, int exp ){
  T res = 1;
  while( exp ){
    if( exp & 1 ) res= (res*base)%MOD;
    base=(base*base)%MOD;
    exp >>= 1;
  }
  return res;
}
struct ComplexNumber {
  ll real, img;
  ComplexNumber( ll x=0, ll y=0 ){
    real = x, img = y;
  }
  ComplexNumber operator+(const ComplexNumber& x){
    return ComplexNumber( real+x.real, img+x.img );
  }
  ComplexNumber operator-(const ComplexNumber& x){
    return ComplexNumber( real-x.real, img-x.img );
  }
  ComplexNumber operator%(const ll& mod){
    return ComplexNumber( real%mod, img%mod );
  }
  ComplexNumber operator*(const ComplexNumber& x){
    return ComplexNumber( real*x.real + 5*img*x.img, real*x.img + img*x.real );
  }  
  ComplexNumber operator=(const ComplexNumber& x){
    real = x.real, img = x.img;
  }
  ll getIm(){ return img; }
  friend ostream &operator<<( ostream &output, const ComplexNumber &D )
  { 
    output << D.real << " + " << D.img << "i";
    return output;            
  }
};
ComplexNumber phiPower( int n ){
  return fpow( ComplexNumber(1,1), n );
}
int input[NMAX];
ComplexNumber tree[NMAX<<3];
void printTree( int idx, int i, int j ){
  cout << i << "," << j << " " << tree[idx] << endl;
  if(i==j) return;
  int mid=(i+j)>>1;
  printTree(L(idx),i,mid);
  printTree(R(idx),mid+1,j);
}
ll revmod( int n ){
  return fpow( (ll)MOD2INV, n );
}
void init( int idx, int i, int j ){  
  if( i==j ){
    tree[idx] = phiPower( input[i] );
    tree[idx] = tree[idx] * revmod(input[i]), tree[idx] = tree[idx] % MOD;
    tree[idx] = tree[idx] + ComplexNumber(1,0), tree[idx] = tree[idx]%MOD;
    //cout << i << "," << j << " " << tree[idx] << endl;
    return;
  }
  int mid=(i+j)>>1;
  init( L(idx), i, mid );
  init( R(idx), mid + 1, j );
  tree[idx] = tree[L(idx)]*tree[R(idx)];
  tree[idx] = tree[idx]%MOD;
}
ComplexNumber query( int idx, int i, int j, int lt, int rt ){
  if( i==lt && j==rt ) return tree[idx];
  int mid=(i+j)>>1;
  if( rt <= mid ) return query( L(idx), i, mid, lt, rt );
  else if ( lt > mid ) return query( R(idx), mid + 1, j, lt, rt );
  else{
    ComplexNumber res = query( L(idx), i, mid, lt, mid )*query( R(idx), mid + 1, j, mid + 1, rt );
    res =res%MOD;
    return res;
  }
}
void update( int idx, int i, int j, int pos, int val ){
  if( i == j && i == pos ){
    tree[idx] = phiPower( val );
    tree[idx] = tree[idx] * revmod(val), tree[idx] = tree[idx] % MOD;
    tree[idx] = tree[idx] + ComplexNumber(1,0), tree[idx] = tree[idx]%MOD;
    return;
  }
  
  int mid=(i+j)>>1;
  if( pos <= mid ) update(L(idx), i, mid, pos, val);
  else update( R(idx), mid+1, j, pos, val );
  
  tree[idx] = tree[L(idx)]*tree[R(idx)];
  tree[idx] = tree[idx]%MOD;  
}
int main(){  
  ios::sync_with_stdio(false);
  
  //cout << phiPower(1) << "\t" << phiPower(2) << "\t" << phiPower(3) << endl;
  //cout << revmod[0] << endl << revmod[1] << endl << (phiPower(2) * revmod[2])%MOD << endl << (phiPower(3)*revmod[3])%MOD << endl;
  
  int N,Q;
  cin >> N >> Q;
  
  for(int i=1;i<=N;++i)
    cin >> input[i];
    
  init(1,1,N);
  //printTree(1,1,N);
  for(int i=0;i<Q;++i){
    string type;
    int x,y;
    cin >> type >> x >> y;
    
    if( type[0] == 'Q' ){
      ll res = query( 1, 1, N, x, y ).getIm();            
      res = (res * 2) % MOD;      
      cout << res << endl;
    }
    else{
      update( 1, 1, N, x, y );
    }
  }
  
  return 0;
}
