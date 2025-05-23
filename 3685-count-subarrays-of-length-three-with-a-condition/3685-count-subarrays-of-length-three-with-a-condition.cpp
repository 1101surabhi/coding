class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0 ;

        for (int i=0; i<=nums.size()-3; i++){
            int a = nums[i] ;
            int b = nums[i+1] ;
            int c = nums[i+2] ;

            if ((a+c) == b/2.0) count++ ;
        }
        return count ;
    }
};