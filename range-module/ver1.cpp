class RangeModule {
public:
    std::map<int, bool> M;

    RangeModule() {
    }
    
    void addRange(int left, int right) {
        for (int i = left; i < right; i++){
            M[i] = true;
        }
    }
    
    bool queryRange(int left, int right) {
        for (int i = left; i < right; i++){
            if (M.find(i) == M.end() || M[i] == false) return false;
        }
        return true;
    }
    
    void removeRange(int left, int right) {
        for (int i = left; i < right; i++){
            M[i] = false;
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
