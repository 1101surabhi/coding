// Binary Search using Recursion

#include <stdio.h>
using namespace std ;

bool find(int arr[], int s, int e, int target){
    if (s > e) return false ;
    
    int mid = s + (e-s)/2 ;
    
    if (arr[mid] == target) return true ;
    else if (arr[mid] > target){
        return find(arr, s, mid-1, target) ;
    }
    else return find(arr, mid+1, e, target) ;
}

int main(){
    int arr[] = {2,4,6,9,12,45} ;
    cout << find(arr, 0, 5, 5) ;
}
