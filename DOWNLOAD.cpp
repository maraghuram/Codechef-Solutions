// By noob.
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;
#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;
const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second
clock_t start=clock();
#define N 330000
#define G 5010
int x[N],y[N],tree[N];
VI aliens[G];
int previous[G],result[G],m;
void update (int i, int delta) {
	for (; i < m; i |= i + 1)
		tree[i] += delta;
}
int read(int r)
{
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += tree[r];
		return res;
}
int main()
{
#ifdef OFFLINE_JUDGE
	freopen("1.in","r",stdin);
#endif
#ifdef WRITE_JUDGE
	freopen("1.out","w",stdout);
#endif
	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n;++i)	scanf("%d %d",&x[i],&y[i]);
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int k;
		scanf("%d",&k);
		aliens[i].resize(k);
		for(int j=0;j<k;++j)	scanf("%d",&aliens[i][j]);
	}
	//Mix everything and compress (mix masala)
	VI mixture;
	vector<pair<int,pair<int,int> > > queue;
	mixture.clear();
	queue.clear();
	for(int i=0;i<n;++i)
	{
		mixture.pb(x[i]);
		mixture.pb(y[i]);
	}
	for(int i=0;i<q;++i)
		for(int j=0;j<aliens[i].sz;++j)
			mixture.pb(aliens[i][j]);
	sort(all(mixture));
	mixture.erase(unique(all(mixture)),mixture.end());
	m=mixture.sz;
	for(int i=0;i<n;++i)
	{
		x[i]=lower_bound(all(mixture),x[i])-mixture.begin();
		y[i]=lower_bound(all(mixture),y[i])-mixture.begin();
		queue.pb(mp(x[i],mp(-1,i)));
		queue.pb(mp(y[i],mp(+1,i)));
	}
	for(int i=0;i<q;++i)
		for(int j=0;j<aliens[i].sz;++j)
		{
			aliens[i][j]=lower_bound(all(mixture),aliens[i][j])-mixture.begin();
			queue.pb(mp(aliens[i][j],mp(0,i)));
		}
	sort(all(queue));
	memset(result,0,sizeof(result));
	memset(previous,-1,sizeof(previous));
	memset(tree,0,sizeof(tree));
	for(int i=0;i<queue.sz;++i)
	{
		int point=queue[i].X;
		int type=queue[i].Y.X;
		int id=queue[i].Y.Y;
		if(type)
		{
			update(x[id],-type);
		}
		else
		{
			result[id]+=read(point);
			if(previous[id]!=-1)	result[id]-=read(previous[id]);
			previous[id]=point;
		}
	}
	for(int i=0;i<q;++i)	printf("%d\n",result[i]);
#ifdef OFFLINE_JUDGE
fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
return 0;
}
