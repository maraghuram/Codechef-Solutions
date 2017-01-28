#include <bits/stdc++.h>
#define NMAX 55555
#define _abs(x) ( x>0?x:-x )
using namespace std;
int N,Q;
int input[NMAX];
int gcd(int a,int b){
  if(b==0) return _abs(a);
  return gcd(b,a%b);
}
// Begin Segment Tree Definition
struct node{
  node *l, *r;
  int diffG, lazy;
  int first, last;
  node(int a=0,int b=0,int c=0,int d=0,node *e=0,node *f=0){
    first=a;last=b;diffG=c;lazy=d;l=e;r=f;
  }
  node(node *x){
    first=x->first; last=x->last;
    diffG=x->diffG; lazy=x->lazy;
    l=x->l;r=x->r;
  }
};
struct segTree{
  node *root;
  vector<int> A;
  int sz;
  int value;
  segTree(vector<int> _A){
    A = vector<int>(_A);
    sz = A.size();
    root = build(1,sz);
  }
  void update(int st,int en,int val){
    value=val;
    root=update(root,1,sz,st,en);
  }
  int query(int st,int en){
    node *tmp=query(root,1,sz,st,en);
    return gcd(tmp->first,tmp->diffG);
  }
  node* modify(node *x,int val){
    x->first += val; x->last += val;
    x->lazy += val;
    return x;
  }
  node* push(node *x){
    if(x->l){
      if(x->lazy){
	modify(x->l,x->lazy);
	modify(x->r,x->lazy);
	x->lazy=0;
      }
    }
  }
  void merge(node *x, node*y, node *z){
    z->first=x->first;z->last=y->last;
    z->diffG = gcd(x->diffG,gcd(x->last-y->first,y->diffG));
  }
  
  node* build(int i,int j){
    node *tmp=new node();
    if(i==j){
      modify(tmp,A[i-1]);
      return tmp;
    }
    int mid=(i+j)>>1;
    tmp->l=build(i,mid);
    tmp->r=build(mid+1,j);
    merge(tmp->l,tmp->r,tmp);
    return tmp;
  }
  node* update(node *root,int i,int j,int st,int en){
    //node *tmp = new node(root->first,root->last,root->diffG,root->lazy,root->l,root->r);
    node *tmp = new node(root);
    if(i==st && j==en){
      modify(tmp,value);
      return tmp;
      //modify(root,value);
      //return root;
    }
    push(root); tmp->lazy=0;// push(tmp);
    int mid=(i+j)>>1;
    if(en<=mid) tmp->l = update(root->l,i,mid,st,en);
    else if(st>mid) tmp->r = update(root->r,mid+1,j,st,en);
    else{
      tmp->l = update(root->l,i,mid,st,mid);
      tmp->r = update(root->r,mid+1,j,mid+1,en);
    }
    merge(tmp->l,tmp->r,tmp);
    return tmp;
  }
  node* query(node *root,int i,int j,int st,int en){
    if(i==st && j==en) return root;
    push(root);
    int mid=(i+j)>>1;
    if(en<=mid) return query(root->l,i,mid,st,en);
    else if(st>mid) return query(root->r,mid+1,j,st,en);
    else{
      node *tmp=new node();
      merge(query(root->l,i,mid,st,mid),query(root->r,mid+1,j,mid+1,en),tmp);
      return tmp;
    }
  }
  void debug(){
    // cout << "----------------" << endl;
    // _print(root,1,sz);
    // cout << "----------------" << endl;   
  }
  void _print(node *root,int i,int j){
    if(i==j){
      printf("%d,%d - %d %d %d %d\n",i,j,root->first,root->last,root->diffG,root->lazy);
      return;
    }
    int mid=(i+j)>>1;
    _print(root->l,i,mid);
    _print(root->r,mid+1,j);
    printf("%d,%d - %d %d %d %d\n",i,j,root->first,root->last,root->diffG,root->lazy);
  }
};
// End of Segment Tree Definition
// -----------------------------------------------------------------------------------
// Begin LCA Functions
const int L = 19;
int p[NMAX][L];
int _log;
int ti[NMAX], to[NMAX], _tm;
int h[NMAX];
void buildLCA(){
  for(_log=0; 1<<_log<N; ++_log);
  ++_log;
  _tm = 0;
}
bool upper(int v, int u){
  return v==-1 || u!=-1 && ti[v]<ti[u] && to[v]>to[u];
}
int lca(int v, int u){
  if(v==u || upper(v,u)) return v;
  if(upper(u,v)) return u;
  for(int i=_log-1;i>=0;--i) if(!upper(p[v][i], u)) v = p[v][i];
  return p[v][0];
}
        
int nextDownTo(int from, int downto){
  for(int i=_log-1;i>=0;--i) if(upper(from, p[downto][i])) downto = p[downto][i];
  return downto;
}
// End LCA Functions
//---------------------------------------------------------------------------------
// Begin Graph Routines
vector<int> adj[NMAX];
int subt[NMAX];
inline void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int dfs(int u,int par){
  ti[u] = ++_tm;
  p[u][0] = par;
  h[u] = (par==-1 ? 0 : h[par]+1);
  subt[u]=1;
  for(int i=1;i<_log;++i)
    p[u][i] = (p[u][i-1]==-1 ? -1: p[p[u][i-1]][i-1]);
  for(int i=0;i<adj[u].size();++i){
    int v=adj[u][i];
    if(v!=par) subt[u]+=dfs(v,u);
  }
  to[u] = ++_tm;
  return subt[u];
}
// End Graph Routines
//--------------------------------------------------------------------------
// Begin HLD Functions
vector<segTree*> trees;
vector<int> chain[NMAX];
int chId[NMAX], chPos[NMAX],chHd[NMAX];
int chNum;
int q[NMAX], qn;
int hld(int u,int p){
  if(chain[chNum].size()==0) chHd[chNum]=u;
  chain[chNum].push_back(input[u]);
  chId[u]=chNum; chPos[u]=chain[chNum].size();
  int most,ind;
  most = 0; ind = -1;
  for(int i=0;i<adj[u].size();++i){
    int v=adj[u][i];
    if(v!=p && subt[v]>most) most=subt[v], ind=v;
  }
  if(ind!=-1) hld(ind,u);
  for(int i=0;i<adj[u].size();++i){
    int v=adj[u][i];
    if(v!=ind && v!=p){
      ++chNum;
      hld(v,u);
    }
  }
}
void getPath(int from, int to){
  qn=0;
  for(;;){
    int fi = chId[from];
    int end = chHd[fi];
    if(fi==chId[to]) end = to;
    q[qn++]=fi;
    q[qn++]=chPos[end];
    q[qn++]=chPos[from];
    if(end==to) break;
    from = p[end][0];
  }
}
void buildSegTrees(){
  for(int i=0;i<=chNum;++i){
    segTree *tmp = new segTree(chain[i]);
    trees.push_back(tmp);
    tmp->debug();
  }
}
void changePath(int u,int p,int val){
  getPath(u,p);
  for(int i=0;i<qn;i+=3){
    int id=q[i];
    trees[id]->update(q[i+1],q[i+2],val);
  }
}
int queryPath(int u,int p){
  int res=0;
  getPath(u,p);
  for(int i=0;i<qn;i+=3)
    res = gcd(res, trees[q[i]]->query(q[i+1],q[i+2]));
  return res;
}
// End HLD functions
//-------------------------------------------------------------------------
// Solve Problem
void solve(){
  buildLCA();
  dfs(1,-1);
  hld(1,-1);
  buildSegTrees();
  char buf[3];
  int u,v,val,lc;
  for(int i=0;i<Q;++i){
    scanf("%s %d %d",buf,&u,&v);
    ++u;++v;
    lc = lca(u,v);
    if(buf[0]=='F')
      printf("%d\n",gcd(queryPath(u,lc),queryPath(v,lc)));
    else{
      scanf("%d",&val);
      changePath(u,lc,val);
      if(v!=lc) changePath(v,nextDownTo(lc,v),val);
    }
    // for(int i=0;i<=chNum;++i){
    //   cout << i << endl;
    //   trees[i]->debug();
    // }
      
  }
}
int main(){
  int u,v;
  scanf("%d",&N);
  for(int i=0;i<N-1;++i){
    scanf("%d %d",&u,&v);
    ++u;++v;
    addEdge(u,v);
  }
  for(int i=0;i<N;++i) scanf("%d",&input[i+1]);
  scanf("%d",&Q);
  solve();
  return 0;
}
