#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
char input[NMAX];
int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		scanf("%s",input);
		int len=strlen(input);
		int flag=0;
		for(int i=0;i<len-2;++i){
			if((input[i]=='0'&&input[i+1]=='1'&&input[i+2]=='0')||(input[i]=='1'&&input[i+1]=='0'&&input[i+2]=='1'))
			{
				flag=1;
				break;
			}
		}
		if(flag) printf("Good\n");
		else printf("Bad\n");
		--T;
	}
	return 0;
}
