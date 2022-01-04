class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2);
        int size = nums.size();
        for (int i = 0; i < size/2; i++){
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            diff[min(nums[i], nums[size - i - 1]) + 1] -= 1;
            diff[max(nums[i], nums[size - i - 1]) + limit + 1] += 1;
            diff[nums[i] + nums[size - i - 1]] -= 1;
            diff[nums[i] + nums[size - i - 1] + 1] += 1;
        }

        int MinCount = INT_MAX;
        int count = 0;
        for (int i = 2; i <= 2 * limit; i++){
            count += diff[i];
            MinCount = min(MinCount, count);
        }

        return MinCount;
    }
};
