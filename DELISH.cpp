#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
typedef long long int x64;
vector<x64> input;
inline x64 absolute(x64 x)
{
	if(x>0) return x;
	else return (-x);
}
void solve()
{
	vector<x64>	leftMax,leftMin,rightMax,rightMin;
	int len=input.size();
	leftMax=vector<x64>(len,0);
	leftMin=vector<x64>(len,0);
	rightMax=vector<x64>(len,0);
	rightMin=vector<x64>(len,0);
	/*leftMax[0]=input[0];
	leftMin[0]=input[0];
	rightMax[len-1]=input[len-1];
	rightMin[len-1]=input[len-1];*/
	x64 maxResult=LLONG_MIN;
	x64 maxSum=0;
	x64 minResult=LLONG_MAX;
	x64 minSum=0;
	for(int i=0;i<len;++i)
	{
		maxSum+=input[i];
		if(maxSum>maxResult)	maxResult=maxSum;
		if(maxSum<0)		maxSum=0;
		leftMax[i]=maxResult;
		minSum+=input[i];
		if(minSum<minResult)	minResult=minSum;
		if(minSum>0)	minSum=0;
		leftMin[i]=minResult;
	}
	maxResult=LLONG_MIN;
	maxSum=0;
	minResult=LLONG_MAX;
	minSum=0;
	for(int i=len-1;i>=0;--i)
	{
		maxSum+=input[i];
		if(maxSum>maxResult)	maxResult=maxSum;
		if(maxSum<0)		maxSum=0;
		rightMax[i]=maxResult;
		minSum+=input[i];
		if(minSum<minResult)	minResult=minSum;
		if(minSum>0)	minSum=0;
		rightMin[i]=minResult;
	}
	x64 result=LLONG_MIN;
	for(int i=0;i<len-1;++i)
	{
		x64 leftHigh,leftLow,rightHigh,rightLow;
		leftHigh=leftMax[i];
		leftLow=leftMin[i];
		rightHigh=rightMax[i+1];
		rightLow=rightMin[i+1];
		result=max(result,max(absolute(rightHigh-leftLow),absolute(leftHigh-rightLow)));
	}
	printf("%lld\n",result);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		int N;
		scanf("%d",&N);
		input=vector<x64>(N,0);
		for(int i=0;i<N;++i)
			scanf("%lld",&input[i]);
		solve();
		--T;
	}
	return 0;
}
