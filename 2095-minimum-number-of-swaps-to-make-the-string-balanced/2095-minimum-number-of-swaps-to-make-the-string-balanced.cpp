class Solution {
public:
    int minSwaps(string s) {
        int maxClosing = 0, closing = 0 ;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '[') --closing ;
            else {
                ++closing ;
                maxClosing = max(closing, maxClosing) ;
            }
        }
        int ans = (maxClosing+1)/2 ;
        return ans ;
    }
};