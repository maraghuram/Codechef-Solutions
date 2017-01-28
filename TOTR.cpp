#include <map>
#include <iostream>
#include <stdio.h>
std::map< char,char > lookupTable;
void createMap(char s[])
{
	char c='a';
	for(int i=0;s[i]!='\0';++i,++c)
	{
		lookupTable[c]=s[i];
		lookupTable[(char)(c-32)]=(char)(s[i]-32);
	}
	lookupTable['_']=' ';
}
int main()
{
	int T;
	char str[30],N[101][101];
	scanf("%d %s",&T,str);
	createMap(str);
	for(int i=0;i<T;++i)
	{
		scanf("%s",N[i]);
	}
	for(int i=0;i<T;++i)
	{
		for(int j=0;N[i][j]!='\0';++j)
		{
			if(lookupTable.find(N[i][j])!=lookupTable.end())
				N[i][j]=lookupTable[N[i][j]];
		}
		printf("%s\n",N[i]);
	}
}
