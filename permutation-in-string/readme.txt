https://leetcode-cn.com/problems/permutation-in-string/

ver1: Inclusion permutation means that each letter appears the same number of times. Map is used to store the number of occurrences of each letter of the string, and the map of s1 is compared with the map of each substring (the same size as s1) of s2. AC: 1952 ms, 169.4 MB
ver2: Modify the way to update the map of substring of s2, only change the count of initial letter and final letter. AC: 20 ms, 7.7 MB
ver3: Use the int array of size 26 to replace the function of map. s1 and s2 use the same array, while s1 counting up and s2 counting down. AC: 4 ms, 7.1 MB
