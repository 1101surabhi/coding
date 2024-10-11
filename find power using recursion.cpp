//find power using recursion

#include <stdio.h>
using namespace std ;

int power(int x, int n){
    if (n == 0) return 1 ;
    
    int num = power(x, n/2) ;
    
    // squaring num (i.e x^n/2 * x^n/2) ;
    num = num * num ;
    
    if (n & 1) return (x * num) ; //if num is odd, multiplying x one more time with num
    return num ;
}

int main(){
    int x = 4 ;
    int n = 0 ;
    cout << power(x, n) << endl ;
}
