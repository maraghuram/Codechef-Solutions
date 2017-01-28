#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long int x64;
using namespace std;
vector<vector<int> > input;
vector<int> visits;
int N,M;
inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
    	neg = 1;
    	c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
    	x = -x;
}
x64 solve()
{
	x64 res=0;
	for(int i=0;i<N;++i)
		sort(input[i].begin(),input[i].end());
	for(int k=0;k<M;++k)
	{
		if(input[visits[k]].size()>0)
		{
			res+=input[visits[k]][input[visits[k]].size()-1];
			input[visits[k]].pop_back();
		}
	}
	return res;
}
int main()
{
	int T;
	fastRead_int(T);
	while(T>0)
	{
		fastRead_int(N);
		fastRead_int(M);
		input=vector<vector<int> >(N,vector<int>(0));
		visits=vector<int>(M,0);
		for(int i=0;i<M;++i) fastRead_int(visits[i]);
		for(int i=0;i<N;++i)
		{
			int lim;
			fastRead_int(lim);
			for(int j=0;j<lim;++j)
			{
				int V;
				fastRead_int(V);
				input[i].push_back(V);
			}
		}
		printf("%lld\n",solve());
		--T;
	}
	return 0;
}
