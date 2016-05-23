#include <cstdio>
#include <stack>

using namespace std;

stack<int> st;
int height[60000+1];
int view[60000+1];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; ++i)
        scanf("%d", &height[i]);

    for(int i=N-1; i>=0; --i){
        if(st.empty()){
            st.push(i);
            view[i] = 0;
        } else {
            int cnt = 0;
            while(!st.empty() && height[st.top()] < height[i]){
                cnt += view[st.top()] + 1; // +1 is for adding themselves
                st.pop();
            }
            view[i] = cnt;
            st.push(i);
        }
    }

    int result = 0;
    for(int i=0; i<N; ++i)
        result += view[i];

    printf("%d", result);

    return 0;
}
