class StockSpanner {
public:
    stack<pair<int, int>> monotone;
    StockSpanner() {
        monotone.push(make_pair(INT_MAX, 0));
    }
    
    int next(int price) {
        if (monotone.top().first > price) {
            monotone.push(make_pair(price, 1));
        }
        else {
            int count = 1;
            while (monotone.top().first <= price){
                count += monotone.top().second;
                monotone.pop();
            }
            monotone.push(make_pair(price, count));
        }
        return monotone.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
