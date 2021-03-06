#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 999999
#define TX 0
#define TY 1
using namespace std;
struct query{
	int x,y,type;
	int d,index;
}q[NMAX];
int res[NMAX/3],tree[NMAX][2];
int N,Q;
void update(int idx,int val,int t){
	for(int i=idx;i<NMAX;i+=(i&-i))
		tree[i][t]+=val;
}
bool comp(const query &l,const query &r){
		if(l.x+l.y<r.x+r.y) return true;
		if((l.x+l.y==r.x+r.y) && (l.type<r.type)) return true;
		return false;
}
int read(int idx,int t){
	int res=0;
	for(int i=idx;i>0;i-=(i&-i))
		res+=tree[i][t];
	return res;
}
int main(){
	int qptr=0;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;++i){
		scanf("%d %d",&q[qptr].x,&q[qptr].y);
		q[qptr].type=0;
		++qptr;
	}
	for(int i=0;i<Q;++i){
		scanf("%d %d %d",&q[qptr].x,&q[qptr].y,&q[qptr].d);
		q[qptr].index=i;
		q[qptr].type=-1;
		++qptr;
		q[qptr].x=q[qptr-1].x,q[qptr].y=q[qptr-1].y+q[qptr-1].d,q[qptr].d=q[qptr-1].d,q[qptr].index=q[qptr-1].index;
		q[qptr].type=1;
		++qptr;
	}
	sort(q,q+qptr,comp);
	memset(tree,0,sizeof(tree));
	int pts=0;
	for(int i=0;i<qptr;++i){
		query qry=q[i];
		//printf("%d %d %d\n",qry.x,qry.y,qry.type);
		if(qry.type==0){
			update(qry.x,+1,TX);
			update(qry.y,+1,TY);
			++pts;
		}
		else if(qry.type==-1){
			res[qry.index]=read(qry.x-1,TX)+read(qry.y-1,TY)-pts;
			//printf("%d\n",res[qry.index]);
		}
		else{
			res[qry.index]+=pts-read(qry.x-1,TX)-read(qry.y-qry.d-1,TY);
			//printf("%d\n",res[qry.index]);
		}
	}
	for(int i=0;i<Q;++i) printf("%d\n",res[i]);
	return 0;
}
