#include <bits/stdc++.h>
#define NMAX 44
typedef double ld;
using namespace std;
int C[NMAX];
ld P[NMAX];
int flag[NMAX];
ld dp[NMAX][NMAX];
ld F[NMAX][NMAX];
int N,M;
vector<ld> group[NMAX];
void init(){
	for(int i=0;i<NMAX;++i)
		for(int j=0;j<NMAX;++j)
			dp[i][j]=0.0;
	dp[0][0]=1.0;
	for(int i=1;i<NMAX;++i){
		dp[i][0]=1.0;
		for(int j=1;j<=i;++j)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
	}
}
ld pow2(int x){
	if(x==0) return 1.0;
	else if(x&1) return 2.0*pow2(x-1);
	else{
		ld t=pow2(x/2);
		return t*t;
	}
}
vector<ld> k_products_1(vector<ld> a, int n){
	vector<ld> newer,older;
    older=vector<ld>(n+1);
    int d, i;
    older[0] = 1.0;
    for(d = 1; d <= n; ++d){
        newer = vector<ld>(n+1);
        newer[0] = a[d-1]*older[0];
        for(i = 1; i <= d; ++i){
            newer[i] = older[i-1] + a[d-1]*older[i];
        }
        older = newer;
    }
    return older;
}
void solve1();
int main(){
	solve1();
	/*init();
	int T;
	scanf("%d",&T);
	while(T--){
		memset(flag,0,sizeof(flag));
		for(int i=0;i<NMAX;++i) group[i].clear();
		int groups=0;
		ld res=0.0;
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;++i){
			scanf("%d %lf",&C[i],&P[i]);
			if(flag[C[i]]==0){
				++groups;
				flag[C[i]]=groups;
			}
			group[flag[C[i]]].push_back(P[i]);
		}
			ld tot=0.0;
			ld sum=0.0;
			vector<ld> powers(groups);
			for(int i=0;i<groups;++i){
				powers[i]=pow2(group[i+1].size())-1;
				//printf("%lf ",powers[i]);
			}
			//printf("\n");
			vector<ld> res2=k_products_1(powers,groups);
			//for(int i=0;i<res.size();++i) printf("%lf\n",res[i]);
			for(int i=M;i<=groups;++i) tot+=res2[groups-i];
			for(int i=1;i<=groups;++i){
				vector<ld> other_powers;
				vector<ld> res3;
				for(int j=1;j<=groups;++j){
					if(j!=i) other_powers.push_back(pow2(group[i].size())-1);
				}
				res3=k_products_1(other_powers,groups-1);
				double x,y;
				x=y=0.0;
				for(int j=0;j<group[i].size();++j) x+=group[i][j];
				for(int j=max(0,M-1);j<=groups-1;++j) y+=res3[groups-1-j];
				sum+=(x*y*(pow2(group[i].size()-1))/tot);
			}
		//	printf("%0.9Lf %0.9Lf",tot,2.0*tot);
			//printf("%lf\n",tot);
			ld rem=pow2(N-M);
//			tot+=dp[groups][M]*rem;
			if(M==0){
				for(int j=0;j<N;++j) sum+=((rem-1)*(P[j]/tot));
			}
			else{
				for(int j=0;j<N;++j) sum+=(dp[groups-1][M-1]*rem*(P[j]/tot));
			}
			res=sum;
			printf("%0.9lf\n",res);
	}*/
	return 0;
}
void solve1(){
	init();
		int T;
		scanf("%d",&T);
		while(T--){
			memset(flag,0,sizeof(flag));
			for(int i=0;i<NMAX;++i) group[i].clear();
			int groups=0;
			ld res=0.0;
			scanf("%d %d",&N,&M);
			for(int i=0;i<N;++i){
				scanf("%d %lf",&C[i],&P[i]);
				if(flag[C[i]]==0){
					++groups;
					flag[C[i]]=groups;
				}
				group[flag[C[i]]].push_back(P[i]);
			}
				ld tot=0.0;
				ld sum=0.0;
				vector<ld> powers(groups);
				for(int i=0;i<groups;++i){
					powers[i]=pow2(group[i+1].size())-1;
					//printf("%lf ",powers[i]);
				}
				//printf("\n");
				vector<ld> res2=k_products_1(powers,groups);
				//for(int i=0;i<res.size();++i) printf("%lf\n",res[i]);
				for(int i=M;i<=groups;++i) tot+=res2[groups-i];
				for(int i=1;i<=groups;++i){
					vector<ld> other_powers;
					vector<ld> res3;
					for(int j=1;j<=groups;++j){
						if(j!=i) other_powers.push_back(pow2(group[j].size())-1);
					}
					res3=k_products_1(other_powers,groups-1);
					double x,y;
					x=y=0.0;
					for(int j=0;j<group[i].size();++j) x+=group[i][j];
					for(int j=max(0,M-1);j<=groups-1;++j) y+=res3[groups-1-j];
					sum+=(x*y*(pow2(group[i].size()-1))/tot);
				}
			/*//	printf("%0.9Lf %0.9Lf",tot,2.0*tot);
				//printf("%lf\n",tot);
				ld rem=pow2(N-M);
	//			tot+=dp[groups][M]*rem;
				if(M==0){
					for(int j=0;j<N;++j) sum+=((rem-1)*(P[j]/tot));
				}
				else{
					for(int j=0;j<N;++j) sum+=(dp[groups-1][M-1]*rem*(P[j]/tot));
				}
	*/
				res=sum;
				printf("%0.9lf\n",res);
		}
}
