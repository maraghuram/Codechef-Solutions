#include <cstdio>
#include <cstring>
#include <vector>
const int MAX=1005;
using namespace std;
vector<int> count;
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		char str[MAX];
		int len,i;
		bool flag=true;
		scanf("%s",str);
		len=strlen(str);
		count.clear();
		count.resize(26,0);
		for(i=0;i<len/2;++i)
			++count[str[i]-'a'];
		for(i=(len+1)/2;i<len;++i)
			--count[str[i]-'a'];
		for(i=0;i<26;++i)
			if(count[i])
			{
				flag=false;
				break;
			}
		if(!flag)
			printf("NO\n");
		else
			printf("YES\n");
		--T;
	}
	return 0;
}
