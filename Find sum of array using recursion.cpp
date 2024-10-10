// Q- Find the total sum of the array elements using recursion.

#include <stdio.h>
using namespace std ;

int arraySum(int arr[], int n){
    if (n == 0) return 0 ;
    if (n == 1) return arr[0] ;
    
    arr[1] += arr[0] ;
    
    return arraySum(arr+1, --n) ;
}

int main(){
    int arr[] = {2,3,9,5,6} ;
    cout << arraySum(arr, 5) ;
}
