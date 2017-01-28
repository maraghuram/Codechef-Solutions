#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
	string s1,s2;
	vector<int> pos;
	int flag=0;
	cin>>s1>>s2;
	if(s1.length()!=s2.length()){
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<s2.length();++i)
		if(s2[i]==s1[0]) pos.push_back(i);
	for(int k=0;k<pos.size();++k){
		int i,j=pos[k];
		for(i=0;i<s1.length();++i,j=(j+1)%s2.size())
			if(s1[i]!=s2[j]) break;
		if(i==s1.length()){
			flag=1;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	}
	return 0;
}
