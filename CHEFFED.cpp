#include <bits/stdc++.h>
using namespace std;
int maxSx = 81;
int maxSSx = 16;
int digitSum( int x ){
	int sum = 0;
	while( x > 0 ) sum += x%10, x/=10;
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	int N, cnt = 0;
	cin >> N;
	
	for(int i=1;i<=maxSx;++i){
		for(int j=1;j<=maxSSx;++j){
			int x = N - i - j;
			if( x < 0 ) continue;
			int sx = digitSum( x );
			int ssx = digitSum( sx );
			if( sx == i && ssx == j ) ++cnt;
		}
	}
	cout << cnt << endl;
	
	return 0;
}
