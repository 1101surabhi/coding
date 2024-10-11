// check palindrome using recursion

#include <stdio.h>
using namespace std ;

bool checkPalindrome(string s, int i, int j){
    if (s[i] != s[j]) return false ;
    else if (i >= j) return true ;
    
    return checkPalindrome(s, ++i, --j) ;
}

int main(){
    string s = "abbbcba" ;
    cout << checkPalindrome(s, 0, s.length()-1) << endl ;
}
