#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > map;
int N;

int paperCnt[2];

int findPaper(int y, int x, int size){
  if(size == 1)
    return map[y][x];
  
  int newSize = size/2;
  
  int topLeft  = findPaper(y, x, newSize);
  int topRight = findPaper(y, x+newSize, newSize);
  int bottomLeft  = findPaper(y+newSize, x, newSize);
  int bottomRight = findPaper(y+newSize, x+newSize, newSize);
  
  // pending check result
  if(topLeft == topRight == bottomLeft == bottomRight)
    return topLeft;
  
  paperCnt[topLeft]++; paperCnt[topRight]++;
  paperCnt[bottomLeft]++; paperCnt[bottomRight]++;
  
  return -1;
}

int main(){
  
  scanf("%d", &N);
  
  map = vector<vector<int> >(N, vector<int>(N));
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      scanf("%d",&map[i][j]);
  
  paperCnt[0] = paperCnt[1] = 0;
  
  findPaper(0, 0, N);
  
  printf("%d\n%d\n", paperCnt[0], paperCnt[1]);
  
  return 0;
}