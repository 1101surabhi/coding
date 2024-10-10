class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n ;
        int a=1, b=0 ;
        int c ;
        for (int i=2; i<=n; i++){
            c = a + b ;
            b = a ;
            a = c ;
        }
        return a ;
    }
};