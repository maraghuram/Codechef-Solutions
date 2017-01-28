#include <cstdio>
#include <cstring>
#define NMAX 1111111
typedef long long int LL;
LL tree[NMAX];
void update(int idx,LL val){
	for(int i=idx;i<NMAX;i+=(i&-i))
		tree[i]+=val;
}
LL read(int idx){
	LL val=0;
	for(int i=idx;i>0;i-=(i&-i))
		val+=tree[i];
	return val;
}
int main(){
	int N,Q;
	memset(tree,0,sizeof(tree));
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;++i){
		int in;
		scanf("%d",&in);
		update(i+1,in);
	}
	for(int i=0;i<Q;++i){
		char type[3];
		int u,v;
		scanf("%s %d %d",type,&u,&v);
		switch(type[0]){
		case 'S' : 	++u,++v;
					printf("%lld\n",u>1?read(v)-read(u-1):read(v));
					break;
		case 'G' :  ++u;
					update(u,v);
					break;
		case 'T' :  ++u;
					update(u,-v);
					break;
		}
	}
	return 0;
}
