class Solution {
public:
    unordered_map<string, int> visited;

    int similarity(string &WordA, string &WordB){
        if (WordA.length() != WordB.length()) return 10;
        int length = WordA.length();
        int count = 0;
        for (int i = 0; i < length; i++){
            if (WordA[i] != WordB[i]) count++;
        }
        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string word: wordList){
            if (!visited.count(word)){
                visited[word] = 0;
            }
        }
        if (!visited.count(endWord)) return 0;
        
        int count = 0;
        vector<string> queue(wordList.size());
        int que_t0 = 0, que_t1 = 0, que_h = 0;
        queue[que_h++] = beginWord;
        visited[beginWord] = 2;

        for (; que_t0 < que_h; count++){
            for (int que_i = que_t0; que_i < que_t1; ++que_i){
                beginWord = queue[que_i];
                if (similarity(beginWord, endWord) == 0) return count;
                visited[beginWord] = 2;
                for (string word: wordList){
                    if (visited[word] == 0){            
                        if (similarity(beginWord, word) == 1) {
                            visited[word] = 1;
                            queue[que_h++] = word;
                        }
                    }   
                }
            }
            que_t0 = que_t1;
            que_t1 = que_h;
        }
        
        return 0;
    }
};
