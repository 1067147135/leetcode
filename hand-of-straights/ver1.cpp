class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        int size = hand.size();
        sort(hand.begin(), hand.end());
        for (int i = 0; i < size/groupSize; i++){
            int start = hand[0];
            hand.erase(hand.begin());
            for (int j = 1; j < groupSize; j++){
                auto it = find(hand.begin(), hand.end(), start+j);
                if (it == hand.end()) return false;
                else hand.erase(it);
            }
        }
        return true;
    }
};
