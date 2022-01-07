class Solution {
public:
    unordered_map<string, int> visitedA; // -1: not in queue, -2: not visited, >= 0: distance to s/t
    unordered_map<string, int> visitedB;

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
        if (similarity(beginWord, endWord) == 0) return 1;
        for (string word: wordList){
            if (!visitedA.count(word)){
                visitedA[word] = -1;
            }
            if (!visitedB.count(word)){
                visitedB[word] = -1;
            }
        }
        if (!visitedA.count(endWord)) return 0;
        
        // bi-directional bfs
        int count = 0;
        vector<string> queueA(wordList.size());
        vector<string> queueB(wordList.size());
        int At0 = 0, At1 = 0, Ah = 0;
        int Bt0 = 0, Bt1 = 0, Bh = 0;
        queueA[Ah++] = beginWord;
        queueB[Bh++] = endWord;
        visitedA[beginWord] = -2;
        visitedB[endWord] = -2;

        for (; At0 < Ah; count++){
            for (int i = At0; i < At1; ++i){
                beginWord = queueA[i];
                visitedA[beginWord] = count;
                for (string word: wordList){
                    
                    if (visitedA[word] == -1){            
                        if (similarity(beginWord, word) == 1) {
                            if (visitedB[word] == -2) {
                                return 2 * count;
                            }
                            visitedA[word] = -2;
                            queueA[Ah++] = word;
                        }
                    }   
                }
            }

            At0 = At1;
            At1 = Ah;

            for (int i = Bt0; i < Bt1; ++i){
                endWord = queueB[i];
                visitedB[endWord] = count;
                for (string word: wordList){
                    
                    if (visitedB[word] == -1){            
                        if (similarity(endWord, word) == 1) {
                            if (visitedA[word] == -2) {
                                return 2 * count + 1;
                            }
                            visitedB[word] = -2;
                            queueB[Bh++] = word;
                        }
                    }   
                }
            }
            Bt0 = Bt1;
            Bt1 = Bh;
        }
        
        return 0;
    }
};
