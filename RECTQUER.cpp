//============================================================================
// Name        : RECTQUER.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstring>
using namespace std;
#define NMAX 333
int input[NMAX][NMAX],state[NMAX][NMAX][10];
int main(){
	int N;
	scanf("%d",&N);
	memset(state,0,sizeof(state));
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			scanf("%d",&input[i][j]);
			if(i>0) for(int k=0;k<10;++k) state[i][j][k]+=state[i-1][j][k];
			if(j>0) for(int k=0;k<10;++k) state[i][j][k]+=state[i][j-1][k];
			if(i>0 && j>0) for(int k=0;k<10;++k) state[i][j][k]-=state[i-1][j-1][k];
			state[i][j][input[i][j]-1]+=1;
		}
/*	printf("\n STATE SPACE");
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			printf("\n @ %d,%d - ",i,j);
			for(int k=0;k<10;++k) printf(" %d",state[i][j][k]);
		}
*/
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;++i){
		int x1,y1,x2,y2,res;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		--x1;
		--x2;
		--y1;
		--y2;
		res=0;
		for(int i=0;i<10;++i){
			int ans=state[x2][y2][i];
			if(x1>0) ans-=state[x1-1][y2][i];
			if(y1>0) ans-=state[x2][y1-1][i];
			if(x1>0 && y1>0) ans+=state[x1-1][y1-1][i];
			if(ans>0) ++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
