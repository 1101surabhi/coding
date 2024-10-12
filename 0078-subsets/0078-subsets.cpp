class Solution {
public:
    string convertToString(int x, int n){
        string ans = "" ;
        while (n--){
            string rem = std::to_string(x % 2) ;
            ans = rem + ans ;
            x /= 2 ;
        }
        return ans ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        int n = nums.size() ;
        for (int i=0; i<pow(2, n); i++){
            string numString = convertToString(i, n) ;
            vector<int> temp ;
            for (int j=0; j<n; j++){
                if (numString[j] == '1'){
                    temp.push_back(nums[j]) ;
                }
            }
            ans.push_back(temp) ;
        }
        return ans ;
    }
};