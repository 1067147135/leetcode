https://leetcode-cn.com/problems/paint-house-iii/

ver1: dynamic programming, define dp[i][j][k] as the minimum cost where we have k+1 neighborhoods in the first i+1 houses and the i+1-th house is painted with the color j+1, 60 / 60, AC: 120 ms, 16.3 MB
ver2: dp[k][j] = minimum cost where we have k neighbors until now, and the last house is painted with the color j, iterate m times to reach final result, 60 / 60, AC: 20 ms, 9.9 MB
