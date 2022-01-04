class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int size = nums.size();
        int MinCount = INT_MAX;
        for (int SumTry = 2; SumTry <= 2 * limit; SumTry++){
            int count = 0;
            for (int i = 0; i < size/2; i++){
                int sum = nums[i] + nums[size - i - 1];
                if (sum == SumTry);
                else if (sum < SumTry) {
                    if (max(nums[i], nums[size - i - 1]) + limit >= SumTry) count += 1;
                    else count += 2;
                    continue;
                }
                else if (sum > SumTry) {
                    if (min(nums[i], nums[size - i - 1]) + 1 <= SumTry) count += 1;
                    else count += 2;
                }
                if (count > MinCount) break;
            }
            if (count < MinCount) MinCount = count;
        }   
        return MinCount;
    }
};
