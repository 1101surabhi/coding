class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false ;
        int count = 10, turn = 0 ;
        while (n >= count){
            n -= count ;
            turn++ ;
            --count ;
        }
        return turn & 1 ;
    }
};