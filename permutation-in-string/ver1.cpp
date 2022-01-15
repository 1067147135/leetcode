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
        map<char, int> sample = check(s1);
        bool flag = false;
        if (s2.size() < s1.size()) return flag;
        for (int i = 0; i <= s2.size() - s1.size(); i++){
            flag = true;
            map<char, int> test = check(s2.substr(i, size));
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
