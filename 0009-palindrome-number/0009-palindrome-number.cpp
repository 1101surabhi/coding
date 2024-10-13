class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false ;
        string numString = to_string(x) ;
        int n = numString.size() ;
        for (int i=0; i<=n/2; i++){
            if (numString[i] != numString[n-i-1]) return false ;
        }
        return true ;
    }
};