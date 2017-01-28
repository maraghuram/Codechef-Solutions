// author noob333
// H + Shift C + B + E + B + E
#include <bits/stdc++.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXVAL 500001
#define NMAX 500010
#define gc getchar_unlocked
#define DEBUG 1
using namespace std;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
// Useful container manipulation / traversal macros
#define REP(i,a,b)                  for(int i=a;i<b;i++)
#define RREP(i,a,b)                 for(int i=a;i>b;i--)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define fi                          first
#define se                          second
// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define L(x)                         ( (x<<1) )
#define R(x)                         ( (x<<1)+1 )
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
      if(!first)
	os << ", ";
      os << *ii ;
      first = false;
    }
  return os << "]";
}
class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};
class FastOutput {
	public:
		FastOutput() {
			m_dataOffset = 0;
		}
		~FastOutput() {
		}
		void Flush() {
			if (m_dataOffset) {
				if (write(1, m_data, m_dataOffset));
				m_dataOffset = 0;
			}
		}
		void PrintUint(uint32_t v, char d) {
			if (m_dataOffset + 11 > sizeof(m_data)) Flush();
			if (v < 100000) {
				if (v < 1000) {
					if (v < 10) {
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 1;
					} else if (v < 100) {
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 2;
					} else {
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 3;
					}
				} else {
					if (v < 10000) {
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 4;
 
					} else {
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 5;
 
					}
 
				}
 
			} else {
 
				if (v < 100000000) {
 
					if (v < 1000000) {
 
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 6;
 
					} else if (v < 10000000) {
 
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 7;
 
					} else {
 
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 8;
 
					}
 
				} else {
 
					if (v < 1000000000) {
 
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 9;
 
					} else {
 
						m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
						m_data[m_dataOffset + 0] = v + 48;
 
						m_dataOffset += 10;
 
					}
 
				}
 
			}
 
			m_data[m_dataOffset++] = d;
 
		}
 
		void PrintChar(char d) {
 
			if (m_dataOffset + 1 > sizeof(m_data)) Flush();
 
			m_data[m_dataOffset++] = d;
 
		}
 
		void ReplaceChar(int offset, char d) {
 
			m_data[m_dataOffset + offset] = d;
 
		}
 
 
 
	public:
 
		uint8_t m_data[32768];
 
		size_t m_dataOffset;
 
};
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int input[NMAX];
int N,M;
struct trieNode{
  trieNode* next[2];
  int cnt;
  trieNode(){
    next[0] = next[1] = NULL;
    cnt = 0;
  }
};
void printTrie(trieNode *root,int val){
  if(root->next[0]==NULL && root->next[1]==NULL)
    cout << val << ",";
  if(root->next[0]) printTrie(root->next[0],val<<1);
  if(root->next[1]) printTrie(root->next[1],(val<<1)+1);
}
trieNode *trieVersions[NMAX];
trieNode* insert(trieNode* root,int x,int mask){
  int tmp = (x&mask)>0?1:0;
  trieNode* ptr = new trieNode();
  ptr->next[0] = root->next[0]; ptr->next[1] = root->next[1];
  ptr->cnt = root->cnt + 1;
  if(root->next[tmp]==NULL){
    trieNode* head = ptr;
    while(mask){
      ptr->next[tmp] = new trieNode();
      ptr = ptr->next[tmp];
      ptr->cnt += 1;
      mask >>= 1;
      tmp = (x&mask)>0?1:0;
    }
    return head;
  }
  ptr->next[tmp] = insert(root->next[tmp],x,mask>>1);
  return ptr;
}
// trieNode* insert(trieNode* root,int x){
//   // trieNode *ptr=(trieNode*)malloc(sizeof(trieNode));
//   trieNode *ptr = new trieNode();
//   trieNode *head = ptr;
//   ptr->next[0] = root->next[0]; ptr->next[1] = root->next[1];
//   ptr->cnt = root->cnt + 1;
//   int mask = 1<<19; int tmp = (mask&x)>0?1:0;
//   while(mask && root->next[tmp]!=NULL){
    
//   }
//   REP(i,0,20){    
//     int tmp = (mask&x)>0?1:0;
//     if(ptr->next[tmp]==NULL) ptr->next[tmp] = new trieNode();
//     ptr=ptr->next[tmp];
//     ptr->cnt += 1;
//     mask >>= 1;
//   }  
//   return head;
// }
ii getTrieMax(trieNode* st,trieNode* en,int x){
  //debug(x);
  int mask = 1<<19;
  int best = 0, val = 0;
  REP(i,0,20){
    int tmp = (mask&x)>0?1:0;
    //debug(st,en,tmp,mask);
    if(en->next[1^tmp] && !(st!=NULL && st->next[1^tmp]!=NULL && en->next[1^tmp]->cnt - st->next[1^tmp]->cnt==0)){
      best += mask;
      val += ((1^tmp)*mask);
      en=en->next[1^tmp]; if(st!=NULL) st=st->next[1^tmp];
    }
    else{
      val += (tmp*mask);
      en = en->next[tmp]; if(st!=NULL) st=st->next[tmp];
    }
    mask >>= 1;
  }
  return ii(best,val);
}
// inline void insert(trieNode* root,int x){
//   trieNode *ptr=root;
//   int mask = 1<<19;
//   ptr->cnt += 1;
//   REP(i,0,20){
//     int tmp = (mask&x)>0?1:0;
//     if(!ptr->next[tmp]) ptr->next[tmp]=(trieNode*)malloc(sizeof(trieNode));
//     ptr=ptr->next[tmp];
//     ptr->cnt += 1;
//     mask >>= 1;
//   }
// }
// inline void remove(trieNode* root,int x){
//   trieNode * ptr=root;
//   int mask = 1<<19;
//   REP(i,0,20){
//     int tmp = (mask&x)>0?1:0;
//     //debug(tmp,mask);
//     ptr->cnt -= 1;    
//     if(ptr->next[tmp]->cnt==1){
//       ptr->next[tmp]=NULL;
//       return;
//     }
//     ptr = ptr->next[tmp];
//     // ptr=ptr->next[tmp];
//     // ptr->cnt -= 1;
//     // if(ptr->cnt == 0 ){
//     //   delete ptr;
//     //   //ptr = NULL;
//     //   return;
//     // }     
//     mask >>= 1;
//   }
// }
// inline ii getTrieMax(trieNode *root,int x){
//   trieNode *ptr = root;
//   assert(ptr!=NULL);
//   int mask = 1<<19;
//   int best=0,val=0;
  
//   for(int i=0;i<20;++i){
//     int tmp = (mask&x)>0?1:0;
//     //debug(tmp,mask);
//     if(ptr->next[1^tmp]){
//       best += mask;
//       val += ((1^tmp)*mask);
//       ptr = ptr->next[1^tmp];
//     }
//     else{
//       val += (tmp*mask);
//       ptr = ptr->next[tmp];
//     }    
//     mask >>= 1;
//   }
//   return ii(best,val);
// }
// struct segNode{
//   trieNode* trie;
//   segNode(){
//     trie = (trieNode*)malloc(sizeof(trieNode));
//   }
// }xorTree[NMAX<<2];
// inline void build(int index,int i,int j){
//   xorTree[index]=segNode();
//   if(i==j) return;
//   int mid=(i+j)>>1;
//   build(L(index),i,mid);
//   build(R(index),mid+1,j);  
// }
// inline void update(int index,int i,int j,int pos,int val){  
//   if(input[pos]) remove(xorTree[index].trie,input[pos]);
//   insert(xorTree[index].trie,val);
//   if(i==j) return;  
//   int mid=(i+j)>>1;
//   if(pos<=mid) update(L(index),i,mid,pos,val);
//   else update(R(index),mid+1,j,pos,val);
// }
// inline ii query(int index,int i,int j,int st,int en,int val){
//   if(i==st && j==en){
//     return getTrieMax(xorTree[index].trie,val);
//   }
//   int mid=(i+j)>>1;
//   if(en<=mid) return query(L(index),i,mid,st,en,val);
//   else if(st>mid) return query(R(index),mid+1,j,st,en,val);
//   else{
//     ii r1,r2;
//     r1 = query(L(index),i,mid,st,mid,val);
//     r2 = query(R(index),mid+1,j,mid+1,en,val);
//     if(r1.fi>=r2.fi) return r1;
//     else return r2;
//   }
// }
// inline void printTree(int index,int i,int j){
//   if(i==j){
//     cout << i << "," << j << "---";
//     printTrie(xorTree[index].trie,0);
//     cout << endl;	
//     return;
//   }
//   int mid=(i+j)>>1;
//   printTree(L(index),i,mid);
//   printTree(R(index),mid+1,j);
//   cout << i << "," << j << "---";
//   printTrie(xorTree[index].trie,0);
//   cout << endl;	
// }
struct perNode{
  perNode *l,*r;
  int cnt;
  perNode(){
    l = r = NULL;
    cnt = 0;
  }
};
perNode* versions[NMAX];
inline perNode* buildPerNode(int i,int j){
  perNode *root = (perNode*) malloc(sizeof(perNode));
  if(i==j) return root;
  int mid=(i+j)>>1;
  root->l = buildPerNode(i,mid);
  root->r = buildPerNode(mid+1,j);
  return root;
}
inline perNode* updPerNode(perNode *root,int i,int j,int pos){
  perNode *tmp = (perNode*) malloc(sizeof(perNode));
  //perNode *tmp = root;
  tmp->l = root->l; tmp->r = root->r; tmp->cnt = root->cnt;
  tmp->cnt += 1;
  if(i==j) return tmp;
  int mid=(i+j)>>1;
  if(pos<=mid)
    tmp->l = updPerNode(root->l,i,mid,pos);
  else
    tmp->r = updPerNode(root->r,mid+1,j,pos);
  return tmp;
}
inline int queryPerNode(perNode *root,int i,int j,int st,int en){
  if(i==st && j==en) return root->cnt;
  int mid=(i+j)>>1;
  if(en<=mid) return queryPerNode(root->l,i,mid,st,en);
  else if(st>mid) return queryPerNode(root->r,mid+1,j,st,en);
  else return queryPerNode(root->l,i,mid,st,mid) + queryPerNode(root->r,mid+1,j,mid+1,en);
}
inline int askLessThan(int st,int en,int x){
  return queryPerNode(versions[en],1,MAXVAL,1,x)-queryPerNode(versions[st-1],1,MAXVAL,1,x);
}
inline int findKth(perNode *st,perNode *en,int i,int j,int k){
  if(i==j) return i;
  int small = en->l->cnt-st->l->cnt;
  int mid = (i+j)>>1;
  if(k<=small) return findKth(st->l,en->l,i,mid,k);
  else return findKth(st->r,en->r,mid+1,j,k-small);  
}
 
inline void addOperation(int x){
  N++;
  //update(1,1,M,N,x);
  trieVersions[N] = insert(trieVersions[N-1],x,1<<19);
  versions[N] = updPerNode(versions[N-1],1,MAXVAL,x);
  input[N] = x;
  // REP(i,1,N+1){
  //   printTrie(trieVersions[i],0);
  //   cout << endl;
  // }
}
inline void removeOperation(int k){
  N -= k;  
}
inline int maxXorOperation(int l,int r,int x){
  ii res = getTrieMax(trieVersions[l-1],trieVersions[r],x);
  //if(x^input[l]>res.fi) return input[l];
  return res.se;
}
inline int kThOperation(int l,int r,int x){
  return findKth(versions[l-1],versions[r],1,MAXVAL,x);
}
FastInput fi;
FastOutput fo;
int main(){
  //ios::sync_with_stdio(false);
  int type,u,v,k;
  //cin >> M;
  //scanint(M);
  M=fi.ReadNext();
  //build(1,1,M);
  versions[0] = buildPerNode(1,MAXVAL);
  trieVersions[0] = new trieNode();
  N = 0;
  REP(i,0,M){
    //cin >> type;
    //scanint(type);
    type=fi.ReadNext();
    if(type == 0){
      //cin >> k;
      //scanint(k);
      k=fi.ReadNext();
      addOperation(k);
    }
    else if(type == 1){
      //cin >> u >> v >> k;
      //scanint(u); scanint(v); scanint(k);
      u=fi.ReadNext(); v=fi.ReadNext(); k=fi.ReadNext();
      // cout << maxXorOperation(u,v,k) << endl;
      //printf("%d\n",maxXorOperation(u,v,k));
      fo.PrintUint(maxXorOperation(u,v,k),'\n');
    }
    else if(type == 2){
      //cin >> k;
      //scanint(k);
      k=fi.ReadNext();
      removeOperation(k);
    }
    else if(type == 3){
      //cin >> u >> v >> k;
      //scanint(u); scanint(v); scanint(k);
      u=fi.ReadNext(); v=fi.ReadNext(); k=fi.ReadNext();
      //cout << askLessThan(u,v,k) << endl;
      //printf("%d\n",askLessThan(u,v,k));
      fo.PrintUint(askLessThan(u,v,k),'\n');
    }
    else{
      //cin >> u >> v >> k;
      //scanint(u); scanint(v); scanint(k);
      u=fi.ReadNext(); v=fi.ReadNext(); k=fi.ReadNext();
      //cout << kThOperation(u,v,k) << endl;
      //printf("%d\n",kThOperation(u,v,k));
      fo.PrintUint(kThOperation(u,v,k),'\n');
    }    
  }
  fo.Flush();
  return 0;
}
