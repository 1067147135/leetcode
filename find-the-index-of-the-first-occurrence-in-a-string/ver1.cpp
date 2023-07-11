class Solution {
public:
    int strStr(string haystack, string needle) {
        // Knuth-Morris-Pratt 算法
        // step 1: 通过 needle 构建动态规划数组 kmp （状态机）- 在 needle 中匹配 needle[1...end]
        // kmp[j][c] = next
        // 0 <= j < needle.size()，代表当前的状态
        // 0 <= c < 26，代表遇到的字符（小写英文字母 - 'a'）
        // 0 <= next <= needle.size()，代表下一个状态
        vector<vector<int>> kmp (needle.size(), vector<int>(26, 0));
        // 初始状态: 仅当字符对上的时候可以状态推进
        kmp[0][needle[0]-'a'] = 1;
        int x = 0;
        for (int j = 1 ; j < needle.size(); j++){
            for (int k = 0 ; k < 26; k++){
                if (needle[j] == k + 'a'){
                    // 状态推进
                    kmp[j][k] = j + 1;
                }
                else{
                    // 状态回退：通过影子状态 x 确认最少回退到的位置
                    // needle[0:x] == needle[j-x:j]
                    kmp[j][k] = kmp[x][k];
                }
            }
            // cout << "before: " << x << " <-> " << j << endl;
            x = kmp[x][needle[j]-'a'];
            // cout << "after: " << x << " <-> " << j << endl;
        }

        // step 2: 在 haystack 中匹配 needle
        int j = 0;
        for (int i = 0; i < haystack.size(); i++){
            j = kmp[j][haystack[i]-'a'];
            // 抵达最后一个状态，完全匹配到目标
            if (j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};
