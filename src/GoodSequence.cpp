#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int N;

bool solve(char *arr, int n){
    
    // base condition
    if(n == N) return;
    
    bool ret = false;
    for(int i=1; i<=3; ++i){
        if(arr[n-1] == arr[n]) continue;
        if(n > 2) {
            int index = n-2; // same point
            int count = 1;
            while(index >= 0){
                if(arr[index] == arr[n]){
                    break;
                }
                index--;
                count++;
            }
            if(index < 0){ // there is no same point
                arr[n] = i;
                ret = solve(arr, n+1);
                if(ret) break;
                else continue;
            } else if( index - count >= 0 ){
                bool flag = true;
                for(int j=n-1, int k=index-1, int cnt =0; cnt < count; ++cnt, --j, --k){
                    if(arr[j] == arr[k]) flag = false;
                    else flag = true;
                }
                if(flag) {
                    arr[n] = i;
                    ret = solve(arr, n+1);
                    if(ret) break;
                    else continue;
                }
            } else {
                arr[n] = i;
                ret = solve(arr, n+1);
                if(ret) break;
                else continue;
            }
        }
        
        if(ret) break;
    }
    
    return ret;
}


int main() {
    
    scanf("%d", &N);
    
    char *arr = (char*)malloc(sizeof(char)*N);
    
    arr[0] = '0';
    solve(arr, N-1);
    
    printf("%s", arr);
    
    return 0;
}