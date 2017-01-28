#include <bits/stdc++.h>
#define NMAX 111111
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;
vector<LL> modify[NMAX];
void solve1();
int main(){
/*	LL N,M,P;
	scanf("%lld %lld %lld",&N,&M,&P);
	for(LL i=0;i<P;++i){
		LL u,v;
		scanf("%lld %lld",&u,&v);
		modify[u].push_back(v);
	}
	for(LL i=1;i<=N;++i){
		if(M==1){
			printf("%lld\n",M+LL(modify[i].size()));
			continue;
		}
		else if(modify[i].size()==0){
			printf("%lld\n",M-1);
			continue;
		}
		else{
			LL flag=0;
			vector<pii> cnt;
			LL res=M-1;
			cnt.push_back(pii(-1,0));
			sort(modify[i].begin(),modify[i].end());
			LL sz=modify[i].size();
			LL ctr=0;
			modify[i].push_back(-1);
			for(LL j=0;j<sz;++j){
				++ctr;
				if(modify[i][j]!=modify[i][j+1]){
					cnt.push_back(pii(modify[i][j],ctr));
					ctr=0;
				}
			}
			cnt.push_back(pii(M+1,0));
			//for(int j=0;j<cnt.size();++j) printf("%lld,%lld ",cnt[j].first,cnt[j].second);
			//printf("\n");
			for(LL j=1;j<cnt.size()-1;++j){
				if(cnt[j-1].first+1!=cnt[j].first){
					if(cnt[j].first!=1) res+=cnt[j].second;
				}
				if(cnt[j].first==M){
					continue;
				}
				LL next=(cnt[j].first+1==cnt[j+1].first)?cnt[j+1].second:0;
				if(cnt[j].second>next+1){
					flag=1;
					break;
				}
				else res=res+(next-cnt[j].second);
			}
			if(flag) res=-1;
			printf("%lld\n",res);
		}
	}
*/
	solve1();
	return 0;
}
void solve1(){
	LL N,M,P;
		scanf("%lld %lld %lld",&N,&M,&P);
		for(LL i=0;i<P;++i){
			LL u,v;
			scanf("%lld %lld",&u,&v);
			modify[u].push_back(v);
		}
		for(LL i=1;i<=N;++i){
			if(M==1){
				printf("%d\n",0);
				continue;
			}
			else if(modify[i].size()==0){
				printf("%lld\n",M-1);
				continue;
			}
			else{
				LL flag=0;
				vector<pii> cnt;
				LL res=M-1;
				cnt.push_back(pii(-1,0));
				sort(modify[i].begin(),modify[i].end());
				LL sz=modify[i].size();
				LL ctr=0;
				modify[i].push_back(-1);
				for(LL j=0;j<sz;++j){
					++ctr;
					if(modify[i][j]!=modify[i][j+1]){
						cnt.push_back(pii(modify[i][j],ctr));
						ctr=0;
					}
				}
				cnt.push_back(pii(M+1,0));
				//for(int j=0;j<cnt.size();++j) printf("%lld,%lld ",cnt[j].first,cnt[j].second);
				//printf("\n");
				for(LL j=1;j<cnt.size()-1;++j){
					if(cnt[j-1].first+1!=cnt[j].first){
						if(cnt[j].first!=1) res+=cnt[j].second;
					}
					if(cnt[j].first==M){
						continue;
					}
					LL next=(cnt[j].first+1==cnt[j+1].first)?cnt[j+1].second:0;
					if(cnt[j].second>next+1){
						flag=1;
						break;
					}
					else res=res+(next-cnt[j].second);
				}
				if(flag) res=-1;
				printf("%lld\n",res);
			}
		}
}
