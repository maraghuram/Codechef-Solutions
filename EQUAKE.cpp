#include <bits/stdc++.h>
#define NMAX 800011
#define DMAX 12
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define gc getchar_unlocked
void _scan(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
using namespace std;
time_t start=clock();
struct node{
  int lazy,currPtr;
  int best[DMAX];
  node(){
    lazy=0;
    currPtr=0;
  }
}tree[NMAX<<2];
int N,M;
int A[NMAX],B[NMAX];
node null;
vector<int> pre[10000];
int cnt[10000];
int st,en,f;
void preCompute(){
  for(int i=0;i<10;++i){    
    pre[i].push_back(i);
    for(int j=0;j<11;++j) pre[i].push_back(i);
    cnt[i]=1;
  }
  for(int i=10;i<100;++i){
    pre[i].push_back(i);
    pre[i].push_back((i%10)*10 + i/10);
    for(int j=0;j<5;++j){
      pre[i].push_back(pre[i][0]);
      pre[i].push_back(pre[i][1]);
    }
    cnt[i]=2;
  }
  for(int i=100;i<1000;++i){
    pre[i].push_back(i);
    pre[i].push_back((i%10)*10 + ((i/10)%10)*100 + i/100);
    pre[i].push_back((i%10)*100 + (i/100)*10 + (i/10)%10);
    for(int j=0;j<3;++j){
      pre[i].push_back(pre[i][0]);
      pre[i].push_back(pre[i][1]);
      pre[i].push_back(pre[i][2]);
    }
    cnt[i]=3;
  }
  for(int i=1000;i<10000;++i){
    pre[i].push_back(i);
    pre[i].push_back((i%10)*10 + ((i/10)%10)*100 + ((i/100)%10)*1000 + i/1000);
    pre[i].push_back((i%10)*100 + ((i/10)%10)*1000 + ((i/100)%10) + (i/1000)*10);
    pre[i].push_back((i%10)*1000 + ((i/10)%10) + ((i/100)%10)*10 + (i/1000)*100);
    for(int j=0;j<2;++j){
      pre[i].push_back(pre[i][0]);
      pre[i].push_back(pre[i][1]);
      pre[i].push_back(pre[i][2]);
      pre[i].push_back(pre[i][3]);
    }
    cnt[i]=4;
  }
}
inline node merge( node x, node y ){
  node z;
  for(int i=0;i<DMAX;++i)
    z.best[i]=max(x.best[(x.currPtr+i)%DMAX],y.best[(y.currPtr+i)%DMAX]);
  return z;
}
inline void setVal(int index,int i,int j,int val){
  int cnt=val%DMAX;
  tree[index].currPtr += cnt;
  tree[index].currPtr %= DMAX;
  if(i!=j){
    tree[L(index)].lazy += cnt;
    tree[L(index)].lazy %= DMAX;
    tree[R(index)].lazy += cnt;
    tree[R(index)].lazy %= DMAX;
  }
}
inline void propagate(int index,int i,int j){
  if(tree[index].lazy){
    setVal(index,i,j,tree[index].lazy);
    tree[index].lazy=0;
  }
}
inline void build(int index,int i,int j){
  tree[index].currPtr=tree[index].lazy=0;
  if(i==j){
    tree[index].currPtr=0;
    for(int k=0;k<DMAX;++k) 
      tree[index].best[k]=pre[A[i]][k];
    return;
  }
  int mid=(i+j)>>1;
  build(L(index),i,mid);
  build(R(index),mid+1,j);
  tree[index]=merge(tree[L(index)],tree[R(index)]);
}
inline void update(int index,int i,int j){
  propagate(index,i,j);
  if(i>=st && j<=en){
    setVal(index,i,j,f);
    return;
  }
  if(i>en || j<st) return;
  int mid=(i+j)>>1;
  update(L(index),i,mid);
  update(R(index),mid+1,j);
  tree[index]=merge(tree[L(index)],tree[R(index)]);
}
inline int query(int index,int i,int j){
  propagate(index,i,j);
  if(i>=st && j<=en){
    return tree[index].best[tree[index].currPtr];
  }
  if(i>en || j<st) return 0;
  int mid=(i+j)>>1;
  int x=query(L(index),i,mid);
  int y=query(R(index),mid+1,j);
  tree[index]=merge(tree[L(index)],tree[R(index)]);
  return max(x,y);
}
void printTree(int index,int i,int j){
  if(i==j){
    cout<<i<<","<<j<<" ";
    for(int k=tree[index].currPtr;(k+1)%DMAX!=tree[index].currPtr;k=(k+1)%DMAX) cout<<tree[index].best[k]<<" ";
    cout<<"--"<<tree[index].lazy<<" "<<tree[index].currPtr<<endl;
    return;
  }
  int mid=(i+j)>>1;
  printTree(L(index),i,mid);
  printTree(R(index),mid+1,j);
  cout<<i<<","<<j<<" ";
  for(int k=tree[index].currPtr;(k+1)%DMAX!=tree[index].currPtr;k=(k+1)%DMAX) cout<<tree[index].best[k]<<" ";
  cout<<"--"<<tree[index].lazy<<" "<<tree[index].currPtr<<endl;    
}
void debug(){
#ifdef deb
  cout<<endl<< "---- DEBUGGIING ----"<<endl;
  printTree(1,1,N);
  cout<<endl<< "--- END ------" <<endl;
#endif
}
int main(){
  //  freopen("1.in","r",stdin);
  //freopen("5.out","w",stdout);
  preCompute();
  //scanf("%d",&N);
  _scan(N);
  //N=fi.ReadNext();
  for(int i=1;i<=N;++i){
    //scanf("%d",&A[i]);
    _scan(A[i]);    
    //A[i]=fi.ReadNext();    
    //B[i]=cnt[A[i]];
  }
  build(1,1,N);
  //scanf("%d",&M);
  _scan(M);
  //M=fi.ReadNext();
  for(int i=0;i<M;++i){
    int type,u,v;
    //scanf("%d %d %d",&type,&u,&v);
    //type=fi.ReadNext();u=fi.ReadNext();v=fi.ReadNext();
    _scan(type);_scan(u);_scan(v);
    ++u,++v;
    if( type == 1 ){
    //fo.PrintUint(query(u,v),'\n');
      st=u;en=v;
      printf("%d\n",query(1,1,N));
    }
    else{
      //scanf("%d",&f);
      //f=fi.ReadNext();
      _scan(f);
      st=u;en=v;
      update(1,1,N);
      //update(u,v,f);
    }
  }
  //fo.Flush();
  //fprintf(stderr,"%.3lf\n",(((double)clock())-start)/CLOCKS_PER_SEC);
  return 0;
}
