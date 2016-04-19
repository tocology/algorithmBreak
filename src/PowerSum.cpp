#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX_VALUE 987654321

using namespace std;

int cache[100*1000 + 1];

int count(int number){
	
	if(number <= 3) return number;
	
	int &ret = cache[number];
	if(ret != -1)
		return ret;
	
	int sub = sqrt(number);
	
	ret = MAX_VALUE;
	for(int i=sub; i>=1; --i)
		ret = min(ret, 1 + count(number - i*i));
	
	return ret;
}

int main(){
	
	int N;
	scanf("%d", &N);
	
	memset(cache, -1, sizeof(cache));
	
	printf("%d", count(N));
	
	return 0;
}