#include <bits/stdc++.h>
#define NMAX 1111
using namespace std;
string str[NMAX];
int N,M;
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--){
    cin >> N >> M;
    for(int i=0;i<N;++i) cin >> str[i];
    int flag = 0;
    for(int i=0;i<N;++i){
      if(str[i][0] == 'W' || str[i][M-1] == 'W'){
	flag = 1;
	break;
      }
    }
    for(int i=0;i<M;++i){
      if(str[N-1][i] == 'W'){
	flag = 1;
	break;
      }
    }
    
    for(int i=0;i<N;++i){
      for(int j=0;j<M;++j){
	
	if(str[i][j] == 'W'){
	  if(j>0 && str[i][j-1]=='A'){
	    flag = 1;
	    break;
	  }
	  else if(j<M-1 && str[i][j+1]=='A'){
	    flag = 1;
	    break;
	  }
	  else if(i<N-1 && str[i+1][j]=='A'){
	    flag = 1;
	    break;
	  }
	}
	
	if(str[i][j] == 'A'){
	  if(i>0 && str[i-1][j]=='B'){
	    flag = 1;
	    break;
	  }
	}
	
      }
      if(flag == 1) break;
    }
    
    if(flag == 1) cout << "no" << endl;
    else cout << "yes" << endl;
    
  }
  return 0;
}
