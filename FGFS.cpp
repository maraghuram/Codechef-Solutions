#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
vector<pii> input;
bool comp(const pii &f,const pii &s){
	if(f.y<s.y) return true;
	if(f.y==s.y) return f.x.y<s.x.y;
	return false;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int res=0;
		input.clear();
		int N,K;
		scanf("%d %d",&N,&K);
		for(int i=0;i<N;++i){
			int s,f,p;
			scanf("%d %d %d",&s,&f,&p);
			input.pb(pii(pi(s,f),p));
		}
		sort(input.begin(),input.end(),comp);
		int comp,prev,curr;
		prev=-1;
		for(int i=0;i<N;++i){
			comp=input[i].y;
			if(comp!=prev){
				++res;
				prev=comp;
				curr=i;
				continue;
			}
			if(input[i].x.x>=input[curr].x.y) ++res,curr=i;
			prev=comp;
		}
		printf("%d\n",res);
	}
	return 0;
}
