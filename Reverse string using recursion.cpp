// reverse a string using recursion

#include <stdio.h>
using namespace std ;

string reverse(string s, int i, int j){
    if (i > j) return s ;
    
    swap(s[i], s[j]) ;
    
    return reverse(s, ++i, --j) ;
}

int main(){
    string s = "surabhi" ;
    cout << reverse(s, 0, 6) << endl ;
}
