#include <bits/stdc++.h>
#define NMAX 111111
#define MOD 1000000007
using namespace std;
vector<int> primes;
vector<int> factors[NMAX];
int flag[NMAX];
int next[NMAX];
int highest[NMAX];
void sieve(){
  memset(flag,0,sizeof(flag));
  flag[0]=flag[1]=1;
  for(int i=2;i<NMAX;++i){
    if(flag[i]==0){
      primes.push_back(i);      
      highest[i]=1;
      for(int j=i;j<NMAX;j+=i){
	flag[j]=1;
	factors[j].push_back(i);
      }
    }
  }
}
int main(){
  sieve();
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
      scanf("%d",&next[i+1]);
      flag[i+1]=0;
    }
    
    int cnt=0;  
    vector<int> val;
    for(int i=0;i<primes.size();++i){
      if(primes[i]>N) break;
      highest[primes[i]]=1;
    }
    for(int i=1;i<=N;++i){
      if(flag[i]==0){
	int pos=i;
	int cnt=0;
	do{
	  flag[pos]=1;
	  pos=next[pos];
	  ++cnt;
	}while(pos!=i);
	val.push_back(cnt);
      }
    }
    for(int i=0;i<val.size();++i){
      int x=val[i];
      for(int j=0;j<factors[x].size();++j){
	int temp=x;
	int u=factors[x][j];
	int cnt=1;
	while(temp%u==0) temp=temp/u,cnt=cnt*u;
	highest[u]=max(highest[u],cnt);
      }
    }
    
    long long int res=1;
    
    for(int i=0;i<primes.size();++i){
      if(primes[i]>N) break;
      res = ( res * (long long int)highest[primes[i]] ) % MOD;
    }
    printf("%lld\n",res);
  }
  return 0;
}
