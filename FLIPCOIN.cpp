#include <bits/stdc++.h>
#define NMAX 111111
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
using namespace std;
int tree[NMAX<<2][2];
void update(int index,int i,int j,int left,int right){
  //printf("%d %d\n",i,j);
  if(tree[index][1]){
    tree[index][0]=(tree[index][1]%2==0?tree[index][0]:(j-i+1)-tree[index][0]);
    if(i!=j) tree[L(index)][1]+=tree[index][1],tree[R(index)][1]+=tree[index][1];
    tree[index][1]=0;
  }
  if(i>right || j<left) return;
  if(i>=left && j<=right) {   
    tree[index][0]=(j-i+1)-tree[index][0];
    if(i!=j) ++tree[L(index)][1],++tree[R(index)][1];
    return;
  }
  if(i!=j){
  int mid=(i+j)>>1;
  update(L(index),i,mid,left,right);
  update(R(index),mid+1,j,left,right);
  tree[index][0]=tree[L(index)][0]+tree[R(index)][0];
  }
}
int query(int index,int i,int j,int left,int right){
  if(tree[index][1]){
    tree[index][0]=(tree[index][1]%2==0?tree[index][0]:(j-i+1)-tree[index][0]);
    if(i!=j) tree[L(index)][1]+=tree[index][1],tree[R(index)][1]+=tree[index][1];
    tree[index][1]=0;
  }
  if(i>right || j<left) return 0;
  if(i>=left && j<=right) return tree[index][0];
  
  if(i!=j){
  int mid=(i+j)>>1;
  int t1=query(L(index),i,mid,left,right);
  int t2=query(R(index),mid+1,j,left,right);
  tree[index][0]=tree[L(index)][0]+tree[R(index)][0];
  return t1+t2;  
  }
  
}
void printTree(int index,int i,int j){
  if(i==j) {
    printf("%d %d - %d,%d \n",i,j,tree[index][0],tree[index][1]);
    return;
  }
  int mid=(i+j)>>1;
  printTree(L(index),i,mid);
  printTree(R(index),mid+1,j);
  printf("%d %d - %d,%d \n",i,j,tree[index][0],tree[index][1]);
}
int main(){
  int N,Q;
  memset(tree,0,sizeof(tree));
  scanf("%d %d",&N,&Q);
  for(int i=0;i<Q;++i){
    int type,u,v;
    scanf("%d %d %d",&type,&u,&v);
    ++u,++v;
    //printf("u=%d,v=%d\n",u,v);
    if(type==0) update(1,1,N,u,v);
    else printf("%d\n",query(1,1,N,u,v));
    //printf("\nPRINTING TREE ----> \n");
    //printTree(1,1,N);
  }
  return 0;
}
