#include <cstdio>
#include <iostream>
using namespace std;
const int MAX=51;
char array[MAX][MAX];
int R,C;
void print()
{
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			printf("\n%d,%d : %c",i,j,array[i][j]);
}
int find(int x,int y)
{
	int i,j;
	int up,down,left,right;
	up=down=left=right=0;
	i=x-1;
	while(i>=0)
	{
		if(array[i][y]=='#') break;
		++up;
		--i;
	}
	i=x+1;
	while(i<R)
	{
		if(array[i][y]=='#') break;
		++down;
		++i;
	}
	j=y-1;
	while(j>=0)
	{
		if(array[x][j]=='#') break;
		++left;
		--j;
	}
	j=y+1;
	while(j<C)
	{
		if(array[x][j]=='#') break;
		++right;
		++j;
	}
	return min(left,min(right,min(up,down)));
}
int solve()
{
	int count=0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			if(array[i][j]=='^' && find(i,j)>=2) ++count;
	return count;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d %d",&R,&C);
		for(int i=0;i<R;++i)
			scanf("%s",array[i]);
		printf("%d\n",solve());
		--T;
	}
	return 0;
}
