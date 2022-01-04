class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int size = nums.size();
        std::map<int, int>M;
        for (int i = 0; i < size/2; i++){
            int sum = nums[i] + nums[size - i - 1];
            if (M.find(sum) == M.end()){
                M[sum] = 1;
            }
            else{
                M[sum] ++;
            }
        }
        int MaxSum = limit;
        int MaxCount = 0;
        for (auto pair: M){
            if (pair.second > MaxCount){
                MaxCount = pair.second;
                MaxSum = pair.first;
            }
        }
        int count = 0;
        for (int i = 0; i < size/2; i++){
            int sum = nums[i] + nums[size - i - 1];
            if (sum == MaxSum) continue;
            if (sum < MaxSum) {
                if (max(nums[i], nums[size - i - 1]) + limit >= MaxSum) count += 1;
                else count += 2;
                continue;
            }
            if (sum > MaxSum) {
                if (min(nums[i], nums[size - i - 1]) + 1 <= MaxSum) count += 1;
                else count += 2;
            }
        }
        return count;
    }
};
