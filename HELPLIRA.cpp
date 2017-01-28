#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <cfloat>
using namespace std;
const double epsilon=0.01;
double modDouble(double x)
{
	if(x<0) return -x;
	return x;
}
int main()
{
	int N;
	scanf("%d",&N);
	double minArea,maxArea;
	int minIndex,maxIndex;
	minArea=DBL_MAX;
	maxArea=DBL_MIN;
	for(int i=1;i<=N;++i)
	{
		int x1,x2,x3,y1,y2,y3;
		double area=0.0;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		area=0.5*modDouble((((double)(x1-x3)*(y2-y1))-((x1-x2)*(y3-y1))));
		if(area<=minArea) minArea=area,minIndex=i;
		if(area>=maxArea) maxArea=area,maxIndex=i;
	}
	printf("%d %d\n",minIndex,maxIndex);
	return 0;
}
