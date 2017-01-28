#include <bits/stdc++.h>
#define NMAX 1111111
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
using namespace std;
typedef long long int LL;
struct node{
	LL val,freq;
	node(LL v,LL f){
		val=v,freq=f;
	}
	node(){
		val=-1;
		freq=0;
	}
};
node tree[NMAX<<3];
LL input[NMAX];
node merge(const node &x,const node &y){
	if(x.val==-1 && y.val==-1)
		return node(-1,0);
	else if(x.val==-1)
		return node(y.val,y.freq);
	else if(y.val==-1)
		return node(x.val,x.freq);
	else{
		if(x.val==y.val) return node(x.val,x.freq+y.freq);
		else if(x.val<y.val) return node(x.val,x.freq);
		else return node(y.val,y.freq);
	}
}
void init(LL index,LL i,LL j){
	if(i==j){
		if(input[i-1]%2) tree[index]=node(-1,0);
		else tree[index]=node(input[i-1],1);
		return;
	}
	LL mid=(i+j)>>1;
	init(L(index),i,mid);
	init(R(index),mid+1,j);
	tree[index]=merge(tree[L(index)],tree[R(index)]);
}
node query(LL index,LL i,LL j,LL left,LL right){
	if(i==left && j==right)
		return tree[index];
	else if(i>right || j<left)
		return node(-1,0);
	LL mid=(i+j)>>1;
	if(right<=mid) return query(L(index),i,mid,left,right);
	else if(left>mid) return query(R(index),mid+1,j,left,right);
	else return merge(query(L(index),i,mid,left,mid),query(R(index),mid+1,j,mid+1,right));
}
void update(LL index,LL i,LL j,LL pos,LL val){
	if(i==j && i==pos){
		if(val%2) tree[index]=node(-1,0);
		else tree[index]=node(val,1);
		return;
	}
	LL mid=(i+j)>>1;
	if(pos<=mid) update(L(index),i,mid,pos,val);
	else update(R(index),mid+1,j,pos,val);
	tree[index]=merge(tree[L(index)],tree[R(index)]);
}
/*void prLLTree(LL index,LL i,LL j){
	if(i==j){
		prLLf("%d,%d - %lld %lld\n",i,j,tree[index].val,tree[index].freq);
		return;
	}
	LL mid=(i+j)>>1;
	prLLTree(L(index),i,mid);
	prLLTree(R(index),mid+1,j);
	prLLf("%d,%d - %lld %lld\n",i,j,tree[index].val,tree[index].freq);
}*/
void swap(LL &x,LL &y){
	LL temp=x;
	x=y;
	y=temp;
}
int main(){
	LL N,M;
	scanf("%lld %lld",&N,&M);
	for(LL i=0;i<N;++i) scanf("%lld",&input[i]);
	init(1,1,N);
	for(LL i=0;i<M;++i) {
		LL type,u,v;
		scanf("%lld %lld %lld",&type,&u,&v);
		node res;
		switch(type){
		case 1 :	res=query(1,1,N,u,v);
					if(res.val==-1) res.freq=0;
					printf("%lld %lld\n",res.val,res.freq);
					break;
		case 2 :	update(1,1,N,u,v);
					break;
		}
	}
	return 0;
}
