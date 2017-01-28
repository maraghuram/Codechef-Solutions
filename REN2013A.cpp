#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int A,B,res;
    scanf("%d %d",&A,&B);
    res=0;
    int temp=A;
    int base=-1;
    while(temp){
      base=max(base,temp%10);
      temp=temp/10;
    }
    ++base;
    temp=A;
    int x=1;
    while(temp){
      res+=((temp%10)*x);
      x*=base;
      temp/=10;
    }
    temp=B;
    base=-1;
    while(temp){
      base=max(base,temp%10);
      temp=temp/10;
      
    }
    ++base;
    temp=B;
    x=1;
    while(temp){
      res+=((temp%10)*x);
      x*=base;
      temp/=10;
    }
    printf("%d\n",res);   
  }
  
  return 0;
}
