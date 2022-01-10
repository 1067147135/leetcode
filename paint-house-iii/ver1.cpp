class Solution {

public:
    int N;

    void DynamicProgramming(vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>>& dp, int i, int j, int k) {
        if (i == 0 && k == 0) {
            if (houses[i] != -1 && houses[i] != j) dp[i][j][k] = INT_MAX / 2;
            else if (houses[i] != -1 && houses[i] == j) dp[i][j][k] = 0;
            else dp[i][j][k] = cost[i][j];
        }
        else if (i == 0 && k != 0) {
            dp[i][j][k] = INT_MAX / 2;
        }
        else if (houses[i] != -1 && houses[i] != j) {
            dp[i][j][k] = INT_MAX / 2;
        }
        else if (houses[i] != -1 && houses[i] == j) {
            if (k == 0) {
                if (dp[i - 1][j][k] == -1) DynamicProgramming(houses, cost, dp, i - 1, j, k);
                dp[i][j][k] = dp[i - 1][j][k];
            }
            else {
                int tmp = INT_MAX / 2;
                for (int x = 0; x < N; x++) {
                    if (x == houses[i]) {
                        if (dp[i - 1][x][k] == -1) DynamicProgramming(houses, cost, dp, i - 1, x, k);
                        tmp = min(tmp, dp[i - 1][x][k]);
                    }
                    else {
                        if (dp[i - 1][x][k - 1] == -1) DynamicProgramming(houses, cost, dp, i - 1, x, k - 1);
                        tmp = min(tmp, dp[i - 1][x][k - 1]);
                    }
                }
                dp[i][j][k] = tmp;
            }
            
        }
        else if (houses[i] == -1) {
            if (k == 0) {
                if (dp[i - 1][j][k] == -1) DynamicProgramming(houses, cost, dp, i - 1, j, k);
                dp[i][j][k] = dp[i - 1][j][k] + cost[i][j];
            }
            else {
                int tmp = INT_MAX / 2;
                for (int x = 0; x < N; x++) {
                    if (x == j) {
                        if (dp[i - 1][x][k] == -1) DynamicProgramming(houses, cost, dp, i - 1, x, k);
                        tmp = min(tmp, dp[i - 1][x][k] + cost[i][j]);
                    }
                    else {
                        if (dp[i - 1][x][k - 1] == -1) DynamicProgramming(houses, cost, dp, i - 1, x, k - 1);
                        tmp = min(tmp, dp[i - 1][x][k - 1] + cost[i][j]);
                    }
                }
                dp[i][j][k] = tmp;
            }  
        }
        // cout << "DynamicProgramming: i = " << i << ", j = " << j << ", k = " << k << ", value = " << dp[i][j][k] << endl;
    }



    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int count = 0;
        int tmp = -1;
        for (int i = 0; i < m; i++) {
            houses[i]--;
            if (houses[i] != -1 && houses[i] != tmp) {
                tmp = houses[i];
                count++;
            }
        }
        if (count > target) return - 1;

        N = n;

        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(target, -1)));
        DynamicProgramming(houses, cost, dp, m - 1, n - 1, target - 1);
        int result = INT_MAX / 2;
        for (int x = 0; x < N; x++) {
            if (dp[m - 1][x][target - 1] == -1) DynamicProgramming(houses, cost, dp, m - 1, x, target - 1);
            result = min(result, dp[m - 1][x][target - 1]);
        }
        if (result == 1073741823) return -1;
        return result;
    }
};
