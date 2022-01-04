class Solution {
public:
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
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        int count = 0;
        vector<string> QueueA;
        vector<string> QueueB;
        QueueA.push_back(beginWord);
        while ( similarity(beginWord, endWord)!= 0){
            count++;
            while (!QueueA.empty()){
                beginWord = QueueA.back();
                if (similarity(beginWord, endWord) == 0) return count;
                QueueA.pop_back();
                auto iter = find(wordList.begin(), wordList.end(), beginWord);
                if (iter != wordList.end()) wordList.erase(iter);
                for (string word: wordList){
                    if (similarity(beginWord, word) == 1) {
                        QueueB.push_back(word);
                    }
                }
            }
            if (QueueB.empty() == true) return 0;
            QueueA.swap(QueueB);
        }
        return count;
    }
};
