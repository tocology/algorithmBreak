#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int L, W;
int island[51][51];
int landCnt;
int findCnt;

pair<int, int> findMaxPoint(pair<int, int> start){
	
	map<pair<int, int>, int> distance;
	queue<pair<int, int> > q;
	
	distance[start] = 0;
	q.push(start);
	
	while(!q.empty()){
		pair<int, int> here = q.front();
		q.pop();
		
		for(int i=0; i<4; ++i){
			int thereY = here.first + dy[i];
			int thereX = here.second + dx[i];
			if(thereY >= 0 && thereY < L 
				&& thereX >= 0 && thereX < W){
				pair<int, int> there = make_pair(thereY, thereX);
				if(distance.count(there) == 0){
					distance[there] = distance[here] + 1;
					q.push(there);
				}
			}
		}
		
		map<pair<int, int>, int>::iterator it;
		
		for(it = distance.begin(); ;){
			
		}
	}
	
}

int main(){
	
	memset(island, -1, sizeof(island));
	
	scanf("%d %d", &L, &W);
	while(getchar() != '\n');
	
	landCnt = 0;
	findCnt = 0;
	for(int i=0; i<L; ++i){
		for(int j=0; j<W; ++j){
			char input;
			scanf("%1c", &input);
			if(input == 'L'){
				island[i][j] = 0;
				landCnt++;
			}
		}
		while(getchar() != '\n');
	}
	
	while(findCnt < landCnt){
		// find start point
		pair<int, int> start;
		for(int i=0; i<L; ++i){
			int j;
			for(j=0; j<W; ++j){
				if(island[i][j] == 0){
					start.first = i; start.second = j;
					break;
				}
			}
			// success to find
			if(j != W)
				break;
		}
	
		// renew start point
		start = findMaxPoint(start);
	}
	
	
	
	
	return 0;
}