#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, W;
int cache[10000+1];
vector<pair<int, int> > jewels; // first: weight, second: price

bool comp(pair<int, int> a, pair<int,int> b){
	return a.first > b.first;	
}

int findMax(int remain, int jewelNumber){
	
	if(jewelNumber == N)
		return 0;
	
	int &ret = cache[remain];
	if(ret != -1){
		return ret;
	}
	
	ret = -1;
	int weight = jewels[jewelNumber].first, price = jewels[jewelNumber].second;
	int possible = remain / weight;

	for(int i=0; i<=possible; ++i){
		if(remain - weight*i >= 0){
			int cond = price*i + findMax(remain - weight*i, jewelNumber+1);
			ret = max(ret, cond);
		}
	}
	
	return ret;
}

int main(){
	
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	scanf("%d", &W);
	
	for(int i=0; i<N; ++i){
		int weight, price;
		scanf("%d", &weight);
		scanf("%d", &price);
		jewels.push_back(make_pair(weight, price));
	}
	
	// sort by weight
	sort(jewels.begin(), jewels.end(), comp);
		
	printf("%d\n", findMax(W, 0));
	
	return 0;
}
