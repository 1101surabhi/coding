// bubble sort using recursion

#include <stdio.h>
using namespace std ;

void bubbleSort(int arr[], int n){
    if (n <= 1) return ;
    
    bool swapped = false ;
    
    for (int j=0; j<n-1; j++){
        if (arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]) ;
            swapped = true ;
        }
    }
    
    if (!swapped) return ;
    bubbleSort(arr, --n) ;
}

int main(){
    int arr[] = {2,5,66,22,63,91,54,55} ;
    int n = 8 ;
    bubbleSort(arr, n) ;
    
    for (int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
