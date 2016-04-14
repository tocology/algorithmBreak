#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX_VALUE 987654321

using namespace std;

int charge[64000+1];
vector<int> levels;

int findMin(int remain){
	
	if(remain == 0)
		return 0;
	
	int &ret = charge[remain];
	if(ret != -1)
		return ret;
		
	ret = MAX_VALUE;
	for(int i=0; i < levels.size(); ++i){
		if(remain - levels[i] >= 0){
			int cond = 1 + findMin(remain - levels[i]);
			ret = min(ret, cond);
		}
	}
	
	return ret;
}

int main(){
	
	int N;
	int remain;
	
	memset(charge, -1, sizeof(charge));
	
	scanf("%d", &N);
	
	for(int i=0; i<N; ++i){
		int level;
		scanf("%d", &level);
		levels.push_back(level);
	}
	
	scanf("%d", &remain);
	
	int result = findMin(remain);
	if(result >= MAX_VALUE){
		printf("impossible\n");
		return 0;
	}
	printf("%d\n", result);
		
	return 0;
}
