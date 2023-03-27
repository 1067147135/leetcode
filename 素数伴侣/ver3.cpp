#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// isPrime
bool check (int a, int b) {
    int c = a + b;
    int d = sqrt(c);
    // cout << a << " " << b << endl;
    for (int i = 2; i <= d; i++) {
        if (c % i == 0) return false;
    }
    // cout << a << " " << b << endl;
    return true;
}

bool match (vector<vector<bool>>& cache, int i, vector<bool>& vis,
            vector<int> &pos) {
    for (int j = 0; j < cache[i].size(); j++) {
        // cout << i << " " << j << " " << pos[j] << endl;
        if (cache[i][j] && !vis[j]) {
            vis[j] = true;
            if (pos[j] == -1 || match(cache, pos[j], vis, pos)) {
                pos[j] = i;
                
                return true;
            }
        }
    }
    return false;
}



int main() {
    int n;
    scanf("%d", &n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num % 2) odd.push_back(num);
        else even.push_back(num);
    }
    vector<vector<bool>> cache(odd.size(), vector<bool>(even.size(), false));
    for (int i = 0; i < odd.size(); i++) {
        for (int j = 0; j < even.size(); j++) {
            cache[i][j] = check(odd[i], even[j]);
            // cout << cache[i][j] << " ";
        }
        // cout << endl;
    }
    int res = 0;
    vector<int> pos(even.size(), -1);
    for (int i = 0; i < odd.size(); i++) {
        vector<bool> vis(even.size(), false);
        if (match(cache, i, vis, pos)) res++;
    }


    printf("%d\n", res);
}
// 64 位输出请用 printf("%lld")
