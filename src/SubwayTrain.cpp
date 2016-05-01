#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, M;
vector<pair<int, int> > adj[100+1];
int parent[100+1];

int dijkstra(int start){
  
  priority_queue<pair<int,int> > pq;
  vector<int> dist = vector<int>(N, INF);
  
  pq.push(make_pair(0, start));
  dist[start] = 0;
  parent[start] = start;
  
  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    
    if(dist[here] < cost) continue;
    
    for(int i=0; i<adj[here].size(); ++i){
    	int there = adj[here][i].first;
    	int nextDist = cost + adj[here][i].second;
    	
    	if(dist[there] > nextDist){
    		dist[there] = nextDist;
    		pq.push(make_pair(-nextDist, there));
    		parent[there] = here;
		}
	}
  }
  
  return dist[M];
}

int main(){
  
  scanf("%d %d", &N, &M);
  
  for(int i=0; i<N; ++i){
  	for(int j=0; j<N; ++j){
  		int cost;
		scanf("%d", &cost);
		if(cost!=0)
			adj[i].push_back(make_pair(j,cost));
	}
  }
  
  printf("%d\n", dijkstra(M));
  
  int leaf = M;
  vector<int> route;
  while(parent[leaf] != leaf){
  	route.push_back(leaf);
  	leaf = parent[leaf];
  }
  
  reverse(route.begin(), route.end());
  
  for(int i=0; route.size(); ++i){
  	printf("%d ", route[i]);
  }  
  
  return 0;
}