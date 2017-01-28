#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int D;
	cin >> D;
	while( D-- ){
		string s;
		cin >> s;
		int sz=s.size();
		if(sz == 1) cout << "NO" << endl;
		else if(sz&1){
			int i=0, cnt=0, j=sz/2 + 1;	
			while( i <= sz/2 && cnt < 2 ){
				if( s[i] != s[j] ) cnt++, ++i;
				else ++i, ++j;
			}
			if( cnt < 2 ) cout << "YES" << endl;
			else{
				reverse(s.begin(),s.end());
	
				i=0, cnt=0, j=sz/2 + 1;	
				while( i <= sz/2 && cnt < 2 ){
					if( s[i] != s[j] ) cnt++, ++i;
					else ++i, ++j;
				}
	
				if( cnt < 2 ) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
		else{
			int flag = 0;
			for(int i=0,j=sz/2;j<sz;++i,++j)
				if(s[i] != s[j]){
					flag=1;
					break;
				}
			if( flag ) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		
	}
	
	return 0;
}
