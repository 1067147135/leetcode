class Solution {
public:
    map<char, int> check(string s){
        map<char, int> count;
        for (char c = 'a'; c <= 'z'; c++){
            count[c] = 0;
        }
        for (char c: s){
            count[c] += 1;
        }
        return count;
    }

    bool checkInclusion(string s1, string s2) {
        int size = s1.size();
        bool flag = true;
        if (s2.size() < s1.size()) return false;
        map<char, int> sample = check(s1);
        map<char, int> test = check(s2.substr(0, size));
        for (char c = 'a'; c <= 'z'; c++){
            if (sample[c] != test[c]) {
                flag = false;
                break;
            }
        }
        if (flag) return flag;
        for (int i = 1; i <= s2.size() - s1.size(); i++){
            flag = true;
            test[s2[i-1]] -= 1;
            test[s2[i+size-1]] += 1;
            for (char c = 'a'; c <= 'z'; c++){
                if (sample[c] != test[c]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) break;
        }
        return flag;
    }
};
