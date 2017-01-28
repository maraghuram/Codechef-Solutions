#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int bestTeam,diff;
		diff=1111111;
		for(int i=0;i<10;++i){
			int small,large;
			large=-1;
			small=1111111;
			for(int j=0;j<15;++j){
				int x;
				scanf("%d",&x);
				small=min(small,x);
				large=max(large,x);
			}
			if(large-small<=diff) diff=large-small,bestTeam=i;
		}
		printf("%d %d\n",bestTeam+1,diff);
	}
	return 0;
}
