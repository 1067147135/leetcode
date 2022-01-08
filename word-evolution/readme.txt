Word Ladder
https://leetcode-cn.com/problems/om3reC/

ver1: BFS, with some purning, 34 / 49, TLE
ver2: BFS implementation upgrade, 37 / 49, TLE
ver3: Bi-directional BFS, 49 / 49, AC: 1856 ms, 17.7 MB
ver4: Using std::queue to implement Bi-directional BFS, 49 / 49, AC: 1696 ms, 14 MB
ver5: Using unordered_map to implement Bi-directional BFS, give priority to expanding layers with a large number of elements, similarity/getNeighbor function implementation upgrade, 49 / 49, AC: 16 ms, 13.6 MB
