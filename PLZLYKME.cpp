#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL L,D,S,C;
		scanf("%llu %llu %llu %llu",&L,&D,&S,&C);
		int flag=0;
		LL res=S;
		LL days=1;
		while(1){
			if(res>=L){
				flag=1;
				break;
			}
			++days;
			if(days>D) break;
			res=res*(C+1);
		}
		if(flag) printf("ALIVE AND KICKING\n");
		else printf("DEAD AND ROTTING\n");
	}
	return 0;
}
