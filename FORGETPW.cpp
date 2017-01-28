#include <bits/stdc++.h>
#define NMAX 1111111
#define RMAX 256
using namespace std;
char rule[RMAX],input[NMAX],output[NMAX];
inline void init(){
  for(int i=0;i<RMAX;++i) rule[i]=i;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    init();
    int rules;
    
    scanf("%d\n",&rules);
    for(int i=0;i<rules;++i) {
      char str[5];
      gets(str);
      //printf("\n---RUle%s\n",str);
      rule[int(str[0])]=str[2];
    }
    scanf("%s",input);
    //printf("%d %s\n",T,input);
    int flag=0;
    int ptr=0;
    int len=strlen(input);
    int i;
    assert(len>0);
    for(i=0;i<len;++i) input[i]=rule[input[i]];
    for(i=0;i<len;++i){
      if(input[i]=='.') break;
      if(flag || input[i]!='0' ) flag=1,output[ptr++]=input[i];
    }
    flag=ptr;
    for(;i<len;++i){
      if(input[i]!='0') flag=ptr+1;
      output[ptr++]=input[i];
    }
    for(i=ptr-1;i>=flag;--i) output[i]='\0',--ptr;
    if(output[ptr-1]=='.') output[i]='\0',--ptr;
    if(ptr==0) output[0]='0',++ptr;
    output[ptr]='\0';
    
    printf("%s\n",output);
  }
  return 0;
}
