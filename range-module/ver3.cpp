class RangeModule {
public:
    std::set<std::pair<int, int>> s;    // (high, low)

    RangeModule() {
    }
    
    void addRange(int left, int right) {
        // find the first element that high >= left
        auto iter = s.lower_bound({left, 0}); 
        // find all intervals that overlap with [left, right]
        while (iter != s.end()) {   
            pair<int, int> curr = *iter;
            if (right < curr.second){
                break;
            }
            left = min(left, curr.second);
            right = max(right, curr.first);
            iter = s.erase(iter);
        }
        s.emplace(right, left);
    }
    
    bool queryRange(int left, int right) {
        // find the first element that high > left
        auto iter = s.upper_bound({left, 0});
        return iter != s.end() && iter->second <= left && iter->first >= right;
    }
    
    void removeRange(int left, int right) {
        // find the first element that high >= left
        auto iter = s.lower_bound({left, 0});
        vector<pair<int, int>> adds;
        while (iter != s.end()){
            if (iter->second > right){  // low > right: no overlapping
                break;
            }
            if (iter->second < left){   // low < left: remove [low, high], add [low, left]
                adds.push_back({left, iter->second});
            }
            if (iter->first > right){   // high > right: remove [low, high], add [right, high]
                adds.push_back({iter->first, right});
            }
            iter = s.erase(iter);
        }
        for (pair<int, int> add : adds){
            s.emplace(std::move(add));
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
