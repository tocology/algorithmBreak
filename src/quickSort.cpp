#include <cstdio>

using namespace std;

void partition(int[] arr, int low, int high){
    int pivot = arr[(low+hight) / 2];
    while(low <= high){
        while(arr[low] < pivot) low++;
        while(arr[right] > pivot) high--;

        if(low <= high) {
            int tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;
            low++;
            high--;
        }
    }
    return low;
}

void quickSort(int[] arr, int low, int high){
    int index = partition(arr, low, high);
    if(low < index - 1){
        quickSort(arr, low, index - 1);
    }
    if(index < right){
        quickSort(arr, index, right);
    }
}

int main(){

    return 0;

}
