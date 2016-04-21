#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int dx[] = {-1, 1, 2, 2, 1,-1,-2,-2};
int dy[] = {-2,-2,-1, 1, 2, 2, 1,-1};

int N, M;

int bfs(pair<int,int> start, pair<int,int> finish){
	
	map<pair<int, int>, int> distance;
	queue<pair<int, int> > q;
	
	distance[start] = 0;
	q.push(start);
	
	while(!q.empty()){
		pair<int, int> here = q.front();
		q.pop();
		
		for(int i=0; i<8; ++i){
			int thereY = here.first + dy[i]; 
			int thereX = here.second + dx[i];
			
			if(thereY >= 0 && thereY < N 
				&& thereX >= 0 && thereX < M){
				pair<int, int> there = make_pair(thereY, thereX);
				if(distance.count(there) == 0){
					if(there == finish)
					return distance[here] + 1;
					q.push(there);
					distance[there] = distance[here] + 1;
				}
			}
		}
	}
	
	return -1;
}

int main() {
	
	scanf("%d %d", &N, &M);
	
	pair<int, int> start, finish;
	
	scanf("%d %d %d %d", &start.first, &start.second, &finish.first, &finish.second);
	
	printf("%d", bfs(start, finish));
	
	return 0;
}