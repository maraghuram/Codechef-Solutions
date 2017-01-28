#include <bits/stdc++.h>
#define NMAX 111111
#define MOD 1000000009
using namespace std;
typedef pair<int,char> pic;
pic a[NMAX];
int main(){
	int t;
	char buf[3];
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%s %d",buf,&a[i].first);
			a[i].second=buf[0];
		}
		sort(a,a+m);
		long long res=1;
		for(int i=0;i<m-1;++i){
			pic next=a[i+1];
			if(next.second!=a[i].second){
				res *= (next.first-a[i].first);
				res %= MOD;
			}
		}
		printf("%lld\n",res);	
	}
	return 0;
}
