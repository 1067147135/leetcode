https://leetcode.cn/problems/lru-cache/


ver1: O(n) to search target key in the vector and find the pair with the lowest time count, replace it when put new pair to the full cache. TLE 20/22
ver2: O(1) to search target key in the unordered map, O(1) to use the splice() to reorder the LRU two-way linked list. 408 ms	161.1 MB
