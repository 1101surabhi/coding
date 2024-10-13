class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0 ? true : false ;
        int num = 0 ;
        x = abs(x) ;
        while (x){
            int digit = x % 10 ;
            if (num > (INT_MAX-digit)/10) return 0 ;
            num = num * 10 + digit ;
            x /= 10 ;
        }
        if (isNegative) return 0 - num ;
        return num ;
    }
};