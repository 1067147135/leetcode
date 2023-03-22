class LRUCache {
private:
vector<pair<int,int>> cache;
vector<long> count;
int cap;
long time = 0;
public:
    

    LRUCache(int capacity) {
        cache.resize(capacity);
        count.resize(capacity);
        cap = capacity;
    }
    
    int get(int key) {
        time++;
        for (int i = 0; i < cap; i++){
            if (count[i] != 0 && cache[i].first == key){
                count[i] = time;
                return cache[i].second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        time++;
        int index = 0;
        int tmp = time;
        for (int i = 0; i < cap; i++){
            if (count[i] != 0 && cache[i].first == key){
                cache[i] = {key, value};
                count[i] = time;
                return;
            }
            else if (count[i] == 0){
                cache[i] = {key, value};
                count[i] = time;
                return;
            }
            else {
                if (count[i] < tmp){
                    tmp = count[i];
                    index = i;
                }
            }
        }
        cache[index] = {key, value};
        count[index] = time;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
