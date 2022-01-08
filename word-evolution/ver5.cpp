class Solution {
public:
    // int similarity(string &WordA, string &WordB){    // a slower version to find neighbors
    //     if (WordA.length() != WordB.length()) return 2;
    //     int length = WordA.length();
    //     int count = 0;
    //     for (int i = 0; i < length; i++){
    //         if (WordA[i] != WordB[i]) count++;
    //         if (count == 2) return 2;
    //     }
    //     return count;
    // }

    bool getNeighbor(unordered_set<string>& visted, unordered_set<string>& st2, unordered_set<string>& st3, string& word) {
        // for (auto it = visted.begin(); it != visted.end(); ++it){    // a slower version to find neighbors
        //     string node = *it;
        //     if (similarity(node, word) == 1) {
        //         if (st2.count(node)) return true;
        //         st3.insert(node);
        //     }
        // }

        for (int i = 0; i < word.size(); ++i) {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (ch != temp && visted.count(word)) {
                    if (st2.count(word)) {
                        return true;
                    }
                    st3.insert(word);
                }
            }
            word[i] = temp;
        }
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visted;
        for (auto& word : wordList) {
            visted.insert(word);
        }
        if (!visted.count(endWord)) {
            return 0;
        }

        unordered_set<string> st1;  // bi-directional bfs layer with more elements
        unordered_set<string> st2;  // bi-directional bfs layer with less elements
        st1.insert(beginWord);
        st2.insert(endWord);
        int len = 2;

        while (!st1.empty() && !st2.empty()) {
            if (st1.size() > st2.size()) {
                swap(st1, st2);
            }

            unordered_set<string> st3;  // next layer of st1, erase as many as possible nodes
            for (auto it = st1.begin(); it != st1.end(); ++it) {
                string word = *it;
                visted.erase(word);

                if (getNeighbor(visted, st2, st3, word)) {
                    return len;
                }
            }
            st1 = st3;
            len++;
        }

        return 0;
    }
};
