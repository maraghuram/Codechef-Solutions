// By noob.
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#define NMAX 111111
int N;
vector<VPII> Tree;
int cost[NMAX];
struct node{
	vector<node *>links;
	node(){
		links.resize(2,NULL);
	}
};
struct Trie{
	node *root;
	Trie(){
		root=new node();
	}
	void insert(int);
	int find(int);
};
void Trie::insert(int x){
	node *curr=root;
	//int lim=1;
	//while((lim<<1)<=x) lim=lim<<1;
	int lim=1<<30;
	for(;lim>0;lim=lim>>1){
		int d=(x&lim)==0?0:1;
		if(curr->links[d]==NULL)
			curr->links[d]=new node();
		curr=curr->links[d];
	}
}
int Trie::find(int x){
	node *curr=root;
	int lim=1<<30;
	int res=0;
	for(;lim>0;lim=lim>>1){
		int d=(x&lim)==0?0:1;
		if(curr->links[!d]!=NULL) res+=lim,curr=curr->links[!d];
		else curr=curr->links[d];
	}
	return res;
}
void dfs(int u,int p,int weight){
	cost[u]=cost[p]^weight;
	for(int i=0;i<Tree[u].size();++i){
		int v=Tree[u][i].X;
		if(v!=p){
			dfs(v,u,Tree[u][i].Y);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		Tree.clear();
		Tree.resize(N+1,VPII(0));
		for(int i=0;i<N-1;++i){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			Tree[u].pb(PII(v,w));
			Tree[v].pb(PII(u,w));
		}
		cost[1]=0;
		dfs(1,1,0);
		Trie *t=new Trie();
		for(int i=1;i<=N;++i){
			t->insert(cost[i]);
		}
		int best=INT_MIN;
		for(int i=1;i<=N;++i){
			best=max(best,t->find(cost[i]));
		}
		printf("%d\n",best);
		--T;
	}
	return 0;
}
