#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
inline ll ReadNext(){
register ll c = getchar();
ll x = 0;
for(;(c<48 || c>57);c = getchar());
for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
return x;
}
int main(){
  int T;
  //scanf("%d",&T);
  T=ReadNext();
  while(T--){
    ll m,n;
    //scanf("%lld %lld",&m,&n);
    m=ReadNext();
    n=ReadNext();
    for(ll k=m;k<=n;++k)
      if(Miller(k,10))
	printf("%lld\n",k);
    if(T) printf("\n");
  }
  
  return 0;
}
