#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define NMAX 155555
using namespace std;
typedef pair<int,char> pic;
vector<pic> calc;
char input[NMAX],freq[26],output[NMAX];
int pos[26];
inline bool alpha(char x){
	if(x>=65 && x<=90) return true;
	if(x>=97 && x<=122) return true;
	return false;
}
void solve(){
	int len=strlen(input);
	calc=vector<pic>(26,pic(0,' '));
	for(int i=0;i<26;++i) calc[i].second='A'+i;
	//puts(input);
	for(int i=0;i<len;++i){
		if(alpha(input[i]))
		{
			char t=input[i];
			if(input[i]>=97) t=t-'a'+'A';
			calc[t-'A'].first+=1;
			//printf("\nHERE");
		}
	}
	sort(calc.begin(),calc.end());
	for(int i=0;i<26;++i){
		pos[calc[i].second-'A']=i;
	}
	for(int i=0;i<len;++i){
		if(alpha(input[i])){
			char t=input[i];
			int temp=(t>=97)?t-'a':t-'A';
			output[i]=(t>=97?freq[pos[temp]]:freq[pos[temp]]-'a'+'A');
		}
		else output[i]=input[i];
	}
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T>0){
		memset(input,'\0',sizeof(input));
		memset(freq,'\0',sizeof(freq));
		memset(output,'\0',sizeof(output));
		gets(freq);
		gets(input);
		solve();
		puts(output);
		--T;
	}
	return 0;
}
