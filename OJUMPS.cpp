#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
	LL x;
	scanf("%lld",&x);
	if(x%6==0 || x%6==1 || x%6==3) printf("yes\n");
	else printf("no\n");
	return 0;
}
