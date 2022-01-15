class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s1.size();
        if (s2.size() < s1.size()) return false;
        // initialize the array
        int count[26];
        for (int i = 0; i < 26; i++){
            count[i] = 0;
        }
        
        // count the occurance of each letter of s1
        for (char c: s1){
            count[c-97] += 1;
        }
        // subtract the occurance of each letter of the substring (the same size of s1) of s2
        for (int i = 0; i < size; i++){
            count[s2[i]-97] -= 1;
        }

        // if all elements in count equal to 0, then return true
        bool flag = true;
        for (int i = 0; i < 26; i++){
            if (count[i]) {
                flag = false;
                break;
            }
        }
        if (flag) return flag;
        for (int i = 1; i <= s2.size() - s1.size(); i++){
            flag = true;
            count[s2[i-1]-97] += 1;
            count[s2[i+size-1]-97] -= 1;
            for (int i = 0; i < 26; i++){
                if (count[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) break;
        }
        return flag;
    }
};
