#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;++t){
		int n,k;
		int evenCount=0;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			if(x%2==0) ++evenCount;
		}
		if(evenCount==n && k==0) printf("NO");
		else if(k<=evenCount) printf("YES");
		else printf("NO");
		if(t<T-1) printf("\n");
	}
	return 0;
}
