class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            int k = size - 1;
            int target = -nums[i];           
            for (int j = i + 1; j < size-1; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                for (; k > j; k--){
                    if (nums[j] + nums[k] <= target) break;
                }
                if (j == k) break;
                if (nums[j] + nums[k] == target){
                    result.push_back({nums[i], nums[j], nums[k]});
                } 
            }
            
        }
        return result;
    }
};
