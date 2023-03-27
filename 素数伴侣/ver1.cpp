#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool check (int a, int b){
    int c = a + b;
    int d = sqrt(c);
    // cout << a << " " << b << endl;
    for (int i = 2; i <= d; i++){
        if (c % i == 0) return false; 
    }
    // cout << a << " " << b << endl;
    return true;
}

int helper (vector<int> &odd, vector<int> &even, int i, vector<bool> &avoid){
    if (i >= odd.size()) return 0;
    vector<bool> new_avoid(avoid);
    int res = helper(odd, even, i+1, new_avoid);
    for (int j = 0; j < even.size(); j++){
        vector<bool> new_avoid(avoid);
        if (!new_avoid[j] && check(odd[i], even[j])) {
            // cout << odd[i] << " " << even[j] << endl;
            new_avoid[j] = true;
            res = max(res, helper(odd, even, i+1, new_avoid) + 1);
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        if (num % 2) odd.push_back(num);
        else even.push_back(num);
    }
    vector<bool> avoid(even.size(), false);
    int res = helper(odd, even, 0, avoid);
    printf("%d\n", res);
}
// 64 位输出请用 printf("%lld")
