#include <bits/stdc++.h>
#define NMAX 1111111
using namespace std;
char str[NMAX];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		int len=strlen(str);
		stack<int> t;
		int match=0;
		for(int i=0;i<len;++i){
			if(str[i]=='<') t.push(1);
			else if(str[i]=='>'){
				if(t.empty()) break;
				t.pop();
			}
			if(t.empty()) match=i+1;
		}
		printf("%d\n",match);
	}
	return 0;
}
