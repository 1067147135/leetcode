class StockSpanner {
public:
    stack<pair<int, int>> monotone;
    int t = 0; // time slot
    StockSpanner() {
        monotone.push(make_pair(INT_MAX, t++));
    }
    
    int next(int price) {
        while (monotone.top().first <= price){
            monotone.pop();
        }
        int result = t - monotone.top().second;
        monotone.push(make_pair(price, t++));
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
