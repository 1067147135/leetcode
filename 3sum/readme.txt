https://leetcode-cn.com/problems/3sum/

ver1: sort and 3-layer-traversal while i <= j <= k and find i + j + k == 0, 315 / 318, TLE
ver2: sort and 2-layer-traversal while i <= j, nums[j] + nums[k] >= -nums[i], AC: 72 ms, 19.4 MB
