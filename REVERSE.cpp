#include <bits/stdc++.h>
#define NMAX 111111
#define gc getchar
//#define debug 1
#define inf NMAX<<2
using namespace std;
typedef pair<int,int> pii;
time_t start=clock();
inline void _scan(int &x)
{
    register int c = gc();
    x = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
vector<pii> adjList[NMAX];
int dist[NMAX],visited[NMAX];
void genTest(){
	FILE *fp=freopen("1.in","w",stdout);
	printf("%d %d\n",100000,100000);
	for(int i=0;i<100000;++i){
		int u=rand()%100000+1;
		int v=rand()%100000+1;
		printf("%d %d\n",u,v);
	}
	fclose(fp);
}
int N,M;
int main(){
	//scanf("%d %d",&N,&M);
#ifdef debug
	genTest();
	start=clock();
	freopen("1.in","r",stdin);
#endif
	_scan(N);
	_scan(M);
	for(int i=0;i<M;++i){
		int u,v;
		//scanf("%d %d",&u,&v);
		_scan(u);
		_scan(v);
		if(u==v) continue;
		adjList[u].push_back(pii(v,0));
		adjList[v].push_back(pii(u,1));
	}
	for(int i=1;i<=N;++i) dist[i]=inf;
	set<pii> q;
	q.insert(pii(0,1));
	while(!q.empty()){
		pii best=*q.begin();
		q.erase(q.begin());
		int u=best.second;
		int cst=best.first;
		if(u==N){
			printf("%d\n",cst);
//#ifdef debug
//			fprintf(stderr,"%.5lf",((double)clock()-start)/CLOCKS_PER_SEC);
//			assert(((double)clock()-start)/CLOCKS_PER_SEC<1.0);
//#endif
			return 0;
		}
		visited[u]=1;
		for(int i=0;i<adjList[u].size();++i){
			int v=adjList[u][i].first;
			int w=adjList[u][i].second;
			if(visited[v]) continue;
			if(dist[v]>w+cst){
				q.erase(pii(dist[v],v));
				dist[v]=w+cst;
				q.insert(pii(dist[v],v));
			}
		}
	}
	printf("-1\n");
//#ifdef debug
//	fprintf(stderr,"%.5lf",((double)clock()-start)/CLOCKS_PER_SEC);
//	assert(((double)clock()-start)/CLOCKS_PER_SEC<1.0);
//#endif
	return 0;
}
