#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int N;

bool solve(char *arr, int n){
    
    // base condition
    if(n == N) return true;
        
    bool ret = false;
    for(int i=1; i<=3; ++i){
        if(arr[n-1] == (i+'0')) continue;
        if(n > 2) {
            int index = n-2; // same point
            int count = 1;
            while(index >= 0){
                if(arr[index] == i+'0'){
                    break;
                }
                index--;
                count++;
            }
            if(index < 0){ // there is no same point
                arr[n] = i+'0';
                ret = solve(arr, n+1);
                if(ret) break;
                else continue;
            } else if( index - count >= 0 ){
                bool flag = true;
                for(int j=n-1, k=index-1, cnt =0; cnt < count; ++cnt, --j, --k){
                    if(arr[j] == arr[k]) flag = false;
                    else {
                    	flag = true;
						break;	
					}
                }
                if(flag) {
                    arr[n] = i+'0';
                    ret = solve(arr, n+1);
                    if(ret) break;
                    else continue;
                } else continue;
            } else {
                arr[n] = i+'0';
                ret = solve(arr, n+1);
                if(ret) break;
                else continue;
            }
        } else {
        	arr[n] = i+'0';
            ret = solve(arr, n+1);
            if(ret) break;
            else continue;
		}
        
        if(ret) break;
    }
    
    return ret;
}


int main() {
    
    scanf("%d", &N);
    
    char *arr = (char*)malloc(N);
    
    arr[0] = '1';
    solve(arr, 1);
    
    printf("%s", arr);
    
    return 0;
}