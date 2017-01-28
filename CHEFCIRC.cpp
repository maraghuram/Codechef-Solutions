#include <bits/stdc++.h>
#define NMAX 502
#define eps 0.00001
using namespace std;
typedef pair<double,int> pdi;
inline double sq(double x){
  return x*x;
}
double X[NMAX], Y[NMAX];
int N,M;
void solve(){
  // double minX,minY,maxX,maxY;
  // minX=X[0], maxX=X[0];
  // minY=Y[0], maxY=Y[0];
  // for(int i=1;i<N;++i){
  //   minX = min(minX,X[i]);
  //   maxX = max(maxX,X[i]);
  //   minY = min(minY,Y[i]);
  //   maxY = max(maxY,Y[i]);
  // }
  double maxRadius = 707106.000;
  double minRadius = 0.0;
  while(maxRadius-minRadius > eps){
    double checkRadius = (maxRadius + minRadius)/2;
    int maxInside = 0;
    //cout << maxRadius << " " << minRadius << " " << checkRadius << endl;
    for(int i=0;i<N;++i){
      double x1=X[i], y1=Y[i];
      vector<pdi> events;
      //cout << x1 << "," << y1 << endl;
      for(int j=0;j<N;++j){
	if(i==j) continue;
	double x2=X[j], y2=Y[j];
	double d = sqrt(sq(x1-x2) + sq(y1-y2))/2;
	if(d>checkRadius) continue;
	double delta = atan2(y2-y1,x2-x1);
	double phi = acos(d/checkRadius);
	//cout << x2 << "," << y2 << " " << delta << " " << phi << endl;
	events.push_back(pdi(delta-phi,-1));
	events.push_back(pdi(delta+phi,+1));
      }
    
      sort(events.begin(),events.end());
      
      int currentCount, maxCount;
      currentCount = maxCount = 0;
      
      for(int i=0;i<events.size();++i){
	if(events[i].second == -1) ++currentCount;
	else --currentCount;
	maxCount = max(maxCount, currentCount);
	//cout << events[i].first << ":"  << events[i].second << " " << currentCount << endl;
      }
      maxCount++;
      maxInside = max(maxInside, maxCount);
      //cout << "maxOn:" << maxCount << endl;
    }
    //cout << "maxInside: " << maxInside << endl;
    if(maxInside<M) minRadius = checkRadius + 0.01;
    else maxRadius = checkRadius;
  }
  cout << maxRadius << endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for(int i=0;i<N;++i)
    cin >> X[i] >> Y[i];
  solve();
  return 0;
}
