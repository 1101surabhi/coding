class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        while (!isDistinct(nums)) {
            // Remove the first 3 elements
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            count++;
        }
        return count;
    }

    bool isDistinct(const vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return false; // Duplicate found
            seen.insert(num);
        }
        return true; // All elements are distinct
    }
};