#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct subItem {
    int id;
    int price;
    int importance;
};

struct mainItem {
    int id;
    int price;
    int importance;
    vector<subItem> sub;
};

int dp(int i, int j, int n, vector<int>& tra,
       unordered_map<int, mainItem>& items) {
    // printf("%d %d %d\n", i, j , n);
    if (i >= tra.size()) return 0;
    struct mainItem& item = items[tra[i]];
    if (j == -1) { // consider this main item
        if (n < item.price) return dp(i + 1, -1, n, tra, items);
        if (!item.sub.empty()) return max(dp(i, 0, n - item.price, tra, items) + item.price * item.importance, 
                                          dp(i + 1, -1, n, tra, items));                                             
        else return max(dp(i + 1, -1, n - item.price, tra, items) + item.price * item.importance,
                        dp(i + 1, -1, n, tra, items));                       
    }
    
    if (item.sub.size() < j) { // consider sub item
        if (n < item.sub[j].price) return dp(i + 1, -1, n, tra, items);
        return max(dp(i + 1, -1, n - item.sub[j].price, tra, items) + item.sub[j].price * item.sub[j].importance, 
                   dp(i + 1, -1, n, tra, items)); 
    }
    if (n < item.sub[j].price) return dp(i, j + 1, n, tra, items);
    return max(dp(i, j + 1, n - item.sub[j].price, tra, items) + item.sub[j].price * item.sub[j].importance, 
               dp(i, j + 1, n, tra, items)); 
}

int main() {
    int N, m, v, p, q;
    unordered_map<int, mainItem> items;
    vector<int> tra;

    scanf("%d %d", &N, &m);
    for (int j = 0; j < m; j++) {
        scanf("%d %d %d", &v, &p, &q);
        if (q == 0) {
            if (items.find(j) != items.end()) {
                items[j].id = j;
                items[j].price = v;
                items[j].importance = p;
            }else{
                struct mainItem item;
                item.id = j;
                item.price = v;
                item.importance = p;
                items[j] = item;
                tra.push_back(j);
            }
            
        } else {
            struct subItem item;
            item.id = j;
            item.price = v;
            item.importance = p;
            if (items.find(q-1) == items.end()) {
                struct mainItem tmp;
                items[q-1] = tmp;
                tra.push_back(q-1);
            }
            items[q-1].sub.push_back(item);
        }
    }
    int res = dp(0, -1, N, tra, items);
    printf("%d\n", res);

}
// 64 位输出请用 printf("%lld")
