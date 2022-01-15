https://leetcode-cn.com/problems/hand-of-straights/

ver1: Sort, then take away needed group of cards from all given cards from value low to high, once fail to take a full group, return fail. Using sort() to sort the vector, find() to find the needed card, earse() to remove the card from the vector. AC: 308 ms, 19.2 MB 
ver2: Use array to store count of the card with the same value, count down when take away an card. Using sort(). AC: 20 ms, 19.4 MB
