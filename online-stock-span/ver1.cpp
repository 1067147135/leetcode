class StockSpanner {
public:
    vector<int>stack;
    StockSpanner() {

    }
    
    int next(int price) {
        stack.push_back(price);
        int count = 0;
        for (int i = stack.size() - 1; i >= 0; i--){
            if (stack[i] <= price) count++;
            else break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
