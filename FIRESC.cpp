#include <stdio.h>
#include <iostream>
#define MOD 1000000007
struct node
{
	int rank,elements;
	node *parent;
};
node *nodes[100001];
void MakeSet(node *x)
{
	x->parent=x;
	x->rank=0;
	x->elements=1;
}
node * Find(node *x)
{
	if(x->parent!=x)
		x->parent=Find(x->parent);
	return x->parent;
}
void Link(node *x,node *y)
{
	if(x->rank > y->rank)
	{
		y->parent=x;
		x->elements+=y->elements;
	}
	else
	{
		x->parent=y;
		y->elements+=x->elements;
		if(x->rank==y->rank)
			y->rank+=1;
	}
}
void Union(node *x,node *y)
{
	Link(Find(x),Find(y));
}
void CreateDisjointSets(int &groups,unsigned long &leaders)
{
	int N,M,count=0;
	unsigned long long ways=1;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i)
	{
		node *newNode=new node();
		nodes[i]=(newNode);
		MakeSet(newNode);
	}
	for(int j=0;j<M;++j)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(Find(nodes[u])!=Find(nodes[v]))
		{
			Union(nodes[u],nodes[v]);
		}
	}
	for(int i=1;i<=N;++i)
	{
		if(nodes[i]->parent==nodes[i])
		{
			++count;
			ways=ways*nodes[i]->elements;
			if(ways>MOD)
				ways=ways%MOD;
		}
	}
	groups=count;
	leaders=ways;
}
int main()
{
	int T,ans[5];
	unsigned long leader[5];
	scanf("%d",&T);
	for(int i=0;i<T;++i)
	{
		CreateDisjointSets(ans[i],leader[i]);
		printf("%d %lu\n",ans[i],leader[i]);
	}
}
