// Linear Search using recursion

#include <stdio.h>
using namespace std ;

bool find(int arr[], int n, int target){
    if (n == 0) return false ;
    if (arr[0] == target) return true ;
    return find(arr+1, --n, target) ;
}

int main(){
    int arr[] = {2,3,9,5,6,91} ;
    cout << find(arr, 6, 91) ;
}
