#include <bits/stdc++.h>
#define NMAX 1111
using namespace std;
char buf[NMAX];
int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;++t){
    int n,flag=0;
    scanf("%d\n",&n);
    gets(buf);
    for(int i=0;i<n;++i){
      if(buf[i]=='Y'){
	flag=1;	break;
      }
      else if(buf[i]=='I'){
	flag=2; break;
      }
    }
    if(flag==1) puts("NOT INDIAN");
    else if(flag==2) puts("INDIAN");
    else puts("NOT SURE");
  }
  return 0;
}
