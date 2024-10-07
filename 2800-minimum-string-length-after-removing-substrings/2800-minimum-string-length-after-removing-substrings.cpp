class Solution {
public:
    int minLength(string s) {
        int i = 0 ;
        while (i < s.size()){
            if (i+1 < s.size() && s[i] == 'A' && s[i+1] == 'B'){
                s.erase(i, 2) ;
                i = 0 ;
            }
            else if (i+1 < s.size() && s[i] == 'C' && s[i+1] == 'D'){
                s.erase(i,2) ;
                i = 0 ;
            }
            else i++ ;
        }
        return s.size() ;
    }
};