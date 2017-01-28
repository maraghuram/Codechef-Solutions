#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int f=0;
		if(s.size()%2) {
			cout << "NO" << endl;
			continue;
		}
		for(int i=0;i<26;++i){
			int cnt = 0;
			for(int j=0; j<s.size(); ++j)
				if(s[j]==i+'a') ++cnt;
			if(cnt == s.size()/2){
				cout << "YES" << endl;
				f=1;
				break;
			}
		}
		if(!f)
		cout << "NO" << endl;
	}
}
