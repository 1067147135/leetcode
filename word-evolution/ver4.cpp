class Solution {
public:
    // -1: not in queue, >= 0: distance to s/t
    unordered_map<string, pair<int, int>> visited; 


    int similarity(string &WordA, string &WordB){
        if (WordA.length() != WordB.length()) return 2;
        int length = WordA.length();
        int count = 0;
        for (int i = 0; i < length; i++){
            if (WordA[i] != WordB[i]) count++;
            if (count == 2) return 2;
        }
        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (similarity(beginWord, endWord) == 0) return 1;
        for (string word: wordList){
            if (!visited.count(word)){
                visited[word] = {-1, -1};
            }
        }
        if (!visited.count(endWord)) return 0;
        
        // bi-directional bfs
        queue<string> queueA;
        queue<string> queueB;
        queueA.push(beginWord);
        queueB.push(endWord);
        visited[beginWord].first = 0;
        visited[endWord].second = 0;
        int count = 0;

        for (;!queueA.empty() && !queueB.empty(); count++){
            for (;!queueA.empty();){
                beginWord = queueA.front();
                if (count != visited[beginWord].first) break;
                queueA.pop();
                for (string word: wordList){
                    if (visited[word].first == -1){            
                        if (similarity(beginWord, word) == 1) {
                            if (visited[word].second >= 0) {
                                return count + visited[word].second + 2;
                            }
                            visited[word].first = count + 1;
                            queueA.push(word);
                        }
                    }   
                }
            }

            for (;!queueB.empty();){
                endWord = queueB.front();
                if (count != visited[endWord].second) break;
                queueB.pop();
                for (string word: wordList){
                    if (visited[word].second == -1){            
                        if (similarity(endWord, word) == 1) {
                            if (visited[word].first >= 0) {
                                return visited[word].first + count + 2;
                            }
                            visited[word].second = count + 1;
                            queueB.push(word);
                        }
                    }   
                }
            }
        }
        return 0;
    }
};
