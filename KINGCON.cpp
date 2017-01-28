#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
class Graph
{
	VVI adjList;
	int missile;
	vector<int> lowValues,dfsValues,visited,parent,articulation;
	int articulationPoints;
	int root,rootCount;
	int counter;
public:
	void CreateList(int,int,int);
	void CountArticulationPoints(int);
	long long int GetCost();
};
long long int Graph::GetCost()
{
	return ((long long int)missile)*articulationPoints;
}
void Graph::CreateList(int Vertices,int Edges,int val)
{
	int N1,N2;
	adjList=VVI(Vertices,VI());
	missile=val;
	lowValues.resize(Vertices,0);
	dfsValues.resize(Vertices,0);
	visited.resize(Vertices,0);
	parent.resize(Vertices,0);
	articulation.resize(Vertices,0);
	for(int i=0;i<Edges;++i)
	{
		scanf("%d %d",&N1,&N2);
		adjList[N1].push_back(N2);
		adjList[N2].push_back(N1);
	}
	articulationPoints=counter=root=rootCount=0;
	CountArticulationPoints(root);
	for(int i=0;i<Vertices;++i)
	{
		articulationPoints+=articulation[i];
	}
}
void Graph::CountArticulationPoints(int v)
{
	visited[v]=1;
	lowValues[v]=dfsValues[v]=counter++;
	for(VI::iterator itr=adjList[v].begin();itr!=adjList[v].end();++itr)
	{
		int val=(*itr);
		if(!visited[val])
		{
			parent[val]=v;
			if(v==root)
				++rootCount;
			CountArticulationPoints(val);
			if(lowValues[val]>=dfsValues[v])
			{
				if(v==root)
				{
					if(rootCount>1)
					{
						articulation[v]=1;
					}
				}
				else
				{
					articulation[v]=1;
				}
			}
			lowValues[v]=min(lowValues[v],lowValues[val]);
		}
		else if(parent[v]!=val)
		{
			lowValues[v]=min(lowValues[v],dfsValues[val]);
		}
	}
}
int main()
{
	int N,E,m,T;
	scanf("%d",&T);
	while(T>0)
	{
		Graph g;
		scanf("%d %d %d",&N,&E,&m);
		g.CreateList(N,E,m);
		printf("%lld\n",g.GetCost());
		--T;
	}
	return 0;
}
