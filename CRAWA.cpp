#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;++t){
		int x,y,flag=0;
		scanf("%d %d",&x,&y);
		if(x==0){
			if(y==0) printf("YES\n");
			else flag=1;
		}
		else if(x==1){
			if(y==1 || y==2) printf("YES\n");
			else flag=1;
		}
		else if(x>0){
			if((x+1)&1) flag=1;
			else{
				int d=(x-1)/2;
				if(y>=(-d*2)&&y<=((d+1)*2)) printf("YES\n");
				else flag=1;
			}
		}
		else{
			int tmp=-x;
			if(tmp&1) flag=1;
			else{
				if(y>=(-tmp) && y<=tmp) printf("YES\n");
				else flag=1;
			}
		}
		if(flag){
			if(y>0){
				if(y&1) printf("NO\n");
				else{
					if(x>=(-y)&&x<=(y-1)) printf("YES\n");
					else printf("NO\n");
				}
			}
			else{
				int tmp=(-y);
				if(tmp&1) printf("NO\n");
				else{
					if(x>=(-tmp)&&x<=(tmp+1)) printf("YES\n");
					else printf("NO\n");
				}
			}
		}
	}
	return 0;
}
