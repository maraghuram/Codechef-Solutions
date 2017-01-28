#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long x64;
int main()
{
	int T,N;
	x64 B,L;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d",&N);
		vector<x64> bands,songs;
		map<x64,x64> flags;
		x64 sweetness=0;
		for(int i=0;i<N;++i)
		{
			scanf("%llu %llu",&B,&L);
			if(flags.find(B)==flags.end())
				flags[B]=L;
			else
			{
				x64 min=flags[B];
				if(L<min)
				{
					flags[B]=L;
					songs.push_back(min);
				}
				else
				{
					songs.push_back(L);
				}
			}
		}
		map<x64,x64>::iterator itr;
		for(itr=flags.begin();itr!=flags.end();++itr)
		{
			bands.push_back(itr->second);
		}
		sort(bands.begin(),bands.end());
		int count=1;
		sweetness=0;
		for(vector<x64>::iterator itr2=bands.begin();itr2!=bands.end();++itr2)
		{
			sweetness+=count*(*itr2);
			++count;
		}
		--count;
		for(vector<x64>::iterator itr3=songs.begin();itr3!=songs.end();++itr3)
		{
			sweetness+=count*(*itr3);
		}
		printf("%llu\n",sweetness);
		--T;
	}
}
