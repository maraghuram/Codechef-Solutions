#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define NMAX 111111
using namespace std;
int tree[NMAX],input[NMAX],res[NMAX];
int N,Q;
struct Query{
	int pos,k;
	int index,count;
}qry[NMAX<<1];
void update(int idx,int val){
	for(int i=idx;i<NMAX;i+=(i&-i))
		tree[i]+=val;
}
int read(int idx){
	int sum=0;
	for(int i=idx;i>0;i-=(i&-i))
		sum+=tree[i];
	return sum;
}
bool comp(const Query &x,const Query &y){
	if(x.pos<y.pos) return true;
	return false;
}
int main(){
	scanf("%d %d",&N,&Q);
	input[0]=0;
	for(int i=1;i<=N;++i) scanf("%d",&input[i]);
	for(int i=0;i<(Q<<1);++i) {
		scanf("%d %d %d",&qry[i].pos,&qry[i+1].pos,&qry[i].k);
		qry[i].index=i/2;
		qry[i+1].index=i/2;
		qry[i+1].k=qry[i].k;
		--qry[i].pos;
		++i;
	}
	sort(qry,qry+(Q<<1),comp);
	//memset(tree,0,sizeof(tree));
	//memset(res,0,sizeof(res));
	int qptr=0;
	for(int i=0;i<=N;++i){
		for(int j=1;j*j<=input[i];++j)
			if(input[i]%j==0){
				++tree[j];
				if((input[i]!=j*j)) ++tree[input[i]/j]  ;
			}
		while( qptr<(Q<<1) && qry[qptr].pos==i ){
			res[qry[qptr].index]=tree[qry[qptr].k]-res[qry[qptr].index];
			++qptr;
		}
		if(qptr>=(Q<<1)) break;
	}
	for(int i=0;i<Q;++i) printf("%d\n",res[i]);
	return 0;
}
