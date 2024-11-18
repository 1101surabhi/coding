class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() ;
        vector<int> ans ;
        if (k == 0){
            for (int i=0; i<n; i++){
                code[i] = 0 ;
            }
            return code ;
        }
        else if (k > 0){
            for (int i=0; i<n; i++){
                int count = k, j = i+1, num = 0 ;
                while (j < n && count > 0){
                    num += code[j] ;
                    count-- ;
                    j++ ;
                }
                if (j >= n) j = 0 ;
                while (j < n && count > 0){
                    num += code[j] ;
                    count-- ;
                    j++ ;
                }
                ans.push_back(num) ;
            }
        }
        else {
            for (int i=0; i<n; i++){
                int count = abs(k), j = i-1, num = 0 ;
                while (j >= 0 && count > 0){
                    num += code[j] ;
                    count-- ;
                    j-- ;
                }
                if (j < 0) j = n-1 ;
                while (j >= 0 && count > 0){
                    num += code[j] ;
                    count-- ;
                    j-- ;
                }
                ans.push_back(num) ;
            }
        }
        return ans ;
    }
};