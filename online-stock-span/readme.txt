https://leetcode-cn.com/problems/online-stock-span/

ver1: use a vector to store all stock information, then count from now to past, 99 / 99, AC: 1512 ms, 84.2 MB
ver2: monotone stack, decreasing order (equivalent to find the lastest day whose price is higher than today), 99 / 99, AC: 204 ms, 82.2 MB
