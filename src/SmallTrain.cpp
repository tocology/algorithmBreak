#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int cache[50000][3]; // 3 - train count
vector<int> passNum;

int N; // total train count
int possible; // possible train count

int countMax(int start, int train){
	
	if(train == 3) return 0;
	
	int &ret = cache[start][train];
	if(ret != -1)
		return ret;
		
	// boundary
	int maximum = N - possible * (3 - train);
	
	ret = 0;
	for(int i=start; i<=maximum; ++i){
		int subTotal = 0;
        for(int j=i; j<i+possible; ++j)
            subTotal += passNum[j];
        ret = max(ret, subTotal + countMax(i+possible, train+1));
	}
	
	return ret;
}

int main(){
	
	scanf("%d", &N);
	
	passNum = vector<int>(N);
	memset(cache, -1, sizeof(cache));
	
	for(int i=0; i<N; ++i)
		scanf("%d", &passNum[i]);
		
	scanf("%d", &possible);		
		
	printf("%d", countMax(0,0));
	
	return 0;
}