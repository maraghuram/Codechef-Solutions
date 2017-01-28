#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio( false );
	int a[4], flag = 0;
	for(int i=0;i<4;++i) cin >> a[i];
	
	sort(a, a+3);
	do {
    	double x = ((double)a[0])/a[1];
    	double y = ((double)a[2])/a[3];
    	if( x == y ){
    		flag = 1;
    		break;
    	}
    	
    }while ( next_permutation(a,a+3) );
    
    if(flag) cout << "Possible";
    else cout << "Impossible";
    
	return 0;
}
