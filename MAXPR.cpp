#include <bits/stdc++.h>
#define NMAX 222222
#define MOD 1000000007	    
#define gc getchar_unlocked
using namespace std;
typedef long int ll;
int input[NMAX]; 
int N;
ll sum[111],pow2[NMAX];
inline void scan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void solve() {
  ll total = 0;
  ll subs = pow2[N];
  for(int diff=-100; diff<=100; ++diff){
    ll curr=0;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<N;++i ){
      ll res = 0;
      if(input[i]-diff >= 0 && input[i]-diff <= 100 )
	res = ( sum[input[i]-diff] );	        
	if( res>=MOD ) res=res%MOD;
      sum[input[i]] = ( sum[input[i]] + res + 1 );
      if( sum[input[i]] >= MOD ) sum[input[i]] = sum[input[i]] %MOD;
      curr = ( curr + res + 1);
      if( curr >= MOD ) curr = curr % MOD;
    }    
    curr = ( curr - N ) % MOD;
    if( curr < 0 ) curr += MOD;
    total = ( curr + total );
    if( total >= MOD ) total = total % MOD;
  }
  total = ( total + N );
  if( total >= MOD ) total = total % MOD;
  subs = (subs - 1 - total)%MOD;
  if( subs<0 ) subs += MOD;
	   
  printf("%ld\n",subs);
	   
}
int main(){
  int T;
  //scanf("%d",&T);
  scan(T);
  pow2[0]=1;
  for(int i=1;i<=200000; ++i){
    pow2[i]=pow2[i-1]<<1;
    if(pow2[i]>=MOD) pow2[i]=pow2[i]%MOD;
  }
  while( T-- ) {
    //scanf("%d",&N);        
    scan(N);
    
    for(int i=0;i<N;++i ){
      //scanf("%d",&input[i]) ;
      scan(input[i]);      
    }
    solve();  
  }
  return 0;
}
