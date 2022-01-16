class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int LastI = INT_MAX;
        int LastJ = INT_MAX;
        int LastK = INT_MAX;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == LastI) continue;
            else{
                LastI = nums[i];
                // cout << "I: " << LastI << endl;
                for (int j = i + 1; j < nums.size(); j++){
                    if (nums[j] == LastJ) continue;
                    else{
                        LastJ = nums[j];
                        // cout << "J: " << LastJ << endl;
                        for (int k = j + 1; k < nums.size(); k++){
                            if (nums[k] == LastK) continue;
                            else{
                                LastK = nums[k];
                                // cout << "K: " << LastK << endl;
                                if (LastI + LastJ + LastK == 0){
                                    vector<int> res = {LastI, LastJ, LastK};
                                    result.push_back(res);
                                } 
                            }
                        }
                        LastK = INT_MAX;
                    }
                }
                LastJ = INT_MAX;
            }
        }
        return result;
    }
};
