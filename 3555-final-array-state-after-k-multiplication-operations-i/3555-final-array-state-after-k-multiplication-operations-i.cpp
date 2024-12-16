class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; i++){
            int smallest = 0 ;
            for(int j=0; j<nums.size(); j++){
                if (nums[j] < nums[smallest]) smallest = j ;
                else if (nums[j] == nums[smallest] && j < smallest) smallest = j ;
            }
            nums[smallest] *= multiplier ;
        }
        return nums ;
    }
};