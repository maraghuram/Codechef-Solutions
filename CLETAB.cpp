#include <bits/stdc++.h>
#define NMAX 222
#define MMAX 444
using namespace std;
int N,M;
int pages[MMAX];
set<int> buffer;
set<int>::iterator bufferItr;
void solve(){
  int currPage = 0;
  int pageFaults = 0;
  buffer.clear();
  while( currPage < M ){
    if( buffer.find( pages[currPage] ) == buffer.end() ){
      ++pageFaults;
      if( buffer.size() < N ) buffer.insert( pages[currPage] );
      else{
	int mxPage,mxDist;
	mxPage = mxDist = -1;
	for( bufferItr = buffer.begin(); bufferItr != buffer.end(); ++ bufferItr ){
	  int page = *bufferItr;
	  int dist = MMAX + NMAX;
	  for( int i = currPage + 1; i < M; ++i )
	    if( pages[i] == page )
	      dist = min( dist, i );
	  if( mxPage == -1 || dist > mxDist) mxPage = page, mxDist = dist;
	}
	buffer.erase( mxPage );
	buffer.insert( pages[currPage] );
      }
    }
    ++currPage;
  }
  printf("%d\n", pageFaults );
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;++i) scanf("%d",&pages[i]);
    solve();
  }
  return 0;
}
