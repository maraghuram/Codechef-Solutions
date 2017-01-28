#include <cstdio>
#include <cstring>
#include <vector>
#define REP26(i)	for(i=0;i<26;++i)
using namespace std;
const int MAX=10005;
struct seg
{
	vector<int> count;
	vector<int> cumFreq;
	int max;
	int cumMax;
};
vector<seg> segments;
void solve()
{
	vector<seg>::iterator itr;
	int prefix,suffix,best,k,total;
	if(segments.begin()!=segments.end())
	{
		REP26(k)
				segments[0].cumFreq[k]=segments[0].count[k];
		segments[0].cumMax=segments[0].max;
	}
	for(int k=0;k<segments.size();++k)
	{
		int i;
		if(k+1==segments.size())
			break;
		REP26(i)
		{
			segments[k+1].cumFreq[i]=segments[k].cumFreq[i]+segments[k+1].count[i];
			segments[k+1].cumMax=max(segments[k+1].cumMax,segments[k+1].cumFreq[i]);
		}
	}
	total=segments.size()-1;
	best=0;
	for(int i=0;i<segments.size();++i)
	{
		suffix=0;
		if(i+1>=segments.size()||i+2>=segments.size()||i+3>=segments.size())
			break;
		prefix=segments[i].cumMax;
		int j;
		REP26(j)
			suffix=max(suffix,segments[total].cumFreq[j]-segments[i+2].cumFreq[j]);
		if(!(prefix&&suffix&&segments[i+1].max&&segments[i+2].max))
			continue;
		best=max(best,prefix+segments[i+1].max+segments[i+2].max+suffix);
	}
	if(best)
		printf("%d\n",best+3);
	else
		printf("%d\n",0);
}
void printSeg()
{
	for(int i=0;i<segments.size();++i)
	{
		int j;
		printf("\n\n");
		REP26(j)
			printf(" %d",segments[i].count[j]);
		printf("\n");
		REP26(j)
			printf(" %d",segments[i].cumFreq[j]);
		printf("\n %d %d",segments[i].max,segments[i].cumMax);
	}
}
int main()
{
	seg dummy;
	dummy.cumFreq=vector<int>(26,0);
	dummy.count=vector<int>(26,0);
	dummy.cumMax=dummy.max=0;
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		char str[MAX];
		int len,k;
		scanf("%s",str);
		len=strlen(str);
		segments.clear();
		segments.push_back(dummy);
		k=0;
		for(int i=0;i<len;++i)
		{
			if(str[i]=='#')
			{
				{
					++k;
					segments.push_back(dummy);
				}
			}
			else
			{
				++segments[k].count[str[i]-'a'];
				segments[k].max=max(segments[k].max,segments[k].count[str[i]-'a']);
			}
		}
		solve();
		--T;
	}
	return 0;
}
