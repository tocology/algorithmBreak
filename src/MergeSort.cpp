#include <cstdio>
#include <cstring>

void merge(int array[], int low, int middle, int high){
  
  int helper[sizeof(array) / sizeof(int)];
  
  memcpy(array, helper, sizeof(array));
  
  int helpLeft = low;
  int helpRight = middle + 1;
  int current = low;
  
  while(helpLeft <= middle && helpRight <= high){
    if(helper[helpLeft] <= helper[helpRight]){
      array[current] = helper[helpLeft];
      helpLeft++;
    } else {
      array[current] = helper[helpRight];
      helpRight++;
    }
    current++;
  }
  
  int remaining = middle - helpLeft;
  for(int i=0; i<=remaining; ++i){
    array[current + i] = helper[helpLeft + i];
  }
}

void mergeSort(int array[], int low, int high){
  
  if(low < high){
    int middle = (low + high) / 2;
    mergeSort(array, low, middle);
    mergeSort(array, middle + 1, high);
    merge(array, low, middle, high);
  }
}

int main() {
  int test[] = {4,10,2,3,1,100};
  
  mergeSort(test, 0,  - 1);
  
}