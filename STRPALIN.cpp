#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio( false );
  
  int T;
  cin >> T;
  while( T-- ){
    string a,b;
    cin >> a >> b;
    vector<int> flag(26);
    int f=0;
    for(int i=0;i<a.size();++i) flag[a[i]-'a']=1;
    for(int i=0;i<b.size();++i) 
      if(flag[b[i]-'a']==1){
	f=1;
	break;
      }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    
  }
  return 0;
}
