#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
int A[NMAX];
int start,end;
int main(){
  int N,M;
  scanf("%d %d",&N, &M);
  start = 0;
  for(int i=0;i<N;++i) 
    scanf("%d",&A[i]);
  for(int i=0;i<M;++i){
    char buf[5];
    int x;
    scanf("%s %d",buf,&x);
    switch(buf[0]){
    case 'R' : printf( "%d\n", A[ ( start + x - 1 + N ) % N] );
      break;
    case 'C' : start = ( start + x ) % N;
      break;
    case 'A' : start = ( start - x + N ) % N;
      break;
    }
    //cout << start << "-- " << endl;
  }
  return 0;
}
