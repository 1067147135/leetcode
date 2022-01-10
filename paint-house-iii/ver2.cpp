class Solution {

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[k][j] = minimum cost where we have k neighbors until now, 
        // and the last house is painted with the color j
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, 1e9)); // initialization
        
        // iterate m times to reach final result
        // in each iteration, we only need the result of last iteration 
        // to calculate the result of this iteration
        for (int i = 0; i < m; i++) {
            for (int k = min(i, target); k >= (i == 0 ? 0 : 1); k--) {
                // m1 = the smallest cost of last iteration for specific k and any j
                // j1 = corresponding j for m1
                // m2 = the second smallest cost of last iteration for specific k and any j
                // j2 = corresponding j for m2
                int m1 = INT_MAX, j1 = -1;  
                int m2 = INT_MAX, j2 = -1; 
                if (i == 0) m1 = 0;
                else {
                    for (int j = 1; j <= n; j++) {
                        if (dp[k][j] < m1) {
                            m2 = m1;
                            j2 = j1;
                            m1 = dp[k][j];
                            j1 = j;
                        }
                        else if (dp[k][j] < m2) {
                            m2 = dp[k][j];
                            j2 = j;
                        }
                    }
                }
                // updation:
                // rule 1: houses[i] != 0 -> painted -> cost = 0; houses[i] == 0 -> unpainted -> cost = cost[i][j]
                // rule 2: k < target -> case 1: keep last 2 houses the same color -> dp[k][j] + cost
                //                       case 2: make last 2 houses have different colors -> min(dp[k][!=j]) + cost
                //                              -> update dp[k+1][j] the 2nd time
                // rule 3: k = target -> only case: keep last 2 houses the same color -> dp[k][j] + cost
                // rule 4: re-painted a house with wrong color is illegal -> infinity cost         
                for (int j = 1; j <= n; j++) {
                    if (houses[i] == 0 || houses[i] == j) {
                        int c = houses[i] == 0 ? cost[i][j - 1] : 0;
                        dp[k][j] = dp[k][j] + c;
                        if (k + 1 <= target) dp[k + 1][j] = min(dp[k + 1][j], (j == j1 ? m2 : m1) + c);
                    }
                    else dp[k][j] = 1e9;
                }
            }
        }
        int res = (int)1e9;
        for (int j = 1; j <= n; j++) res = min(res, dp[target][j]);
        return res >= (int)1e9 ? -1 : res;
    }
};
