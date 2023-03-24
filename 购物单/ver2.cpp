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
            } else {
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
            if (items.find(q - 1) == items.end()) {
                struct mainItem tmp;
                items[q - 1] = tmp;
                tra.push_back(q - 1);
            }
            items[q - 1].sub.push_back(item);
        }
    }

    // cout << "finished read in" << endl;

    vector<vector<int>> dp(tra.size() + 1, vector<int>(N + 1, 0));
    vector<vector<int>> price(tra.size(), vector<int>());
    vector<vector<int>> value(tra.size(), vector<int>());
    for (int i = 0; i < tra.size(); i++) {
        struct mainItem& item = items[tra[i]];
        price[i].push_back(item.price);
        value[i].push_back(item.price * item.importance);
        if (!item.sub.empty()) {
            price[i].push_back(item.price + item.sub[0].price);
            value[i].push_back(item.price * item.importance + item.sub[0].price * item.sub[0].importance);
            if (item.sub.size() == 2) {
                price[i].push_back(item.price + item.sub[1].price);
                value[i].push_back(item.price * item.importance + item.sub[1].price * item.sub[1].importance);
                price[i].push_back(item.price + item.sub[0].price + item.sub[1].price);
                value[i].push_back(item.price * item.importance + item.sub[0].price * item.sub[0].importance +
                                   item.sub[1].price*
                                   item.sub[1].importance);
            }
        }
    }

    // cout << " finished calculate midiate" << endl;

    for (int i = 1; i < tra.size() + 1; i++) {
        for (int j = 10; j < N + 1; j += 10) {
            // cout << "i = " << i << ", j = " << j << endl;
            int max_i = dp[i - 1][j];
            for (int k = 0; k < price[i - 1].size(); k++) {
                if (j - price[i - 1][k] >= 0) {
                    max_i = max(max_i, dp[i - 1][j - price[i - 1][k]] + value[i - 1][k]);
                }
            }
            dp[i][j] = max_i;
            // cout << "i = " << i << ", j = " << j << ", dp[i][j] = " << max_i << endl;
        }
    }

    printf("%d\n", dp[tra.size()][N]);

}
// 64 位输出请用 printf("%lld")
