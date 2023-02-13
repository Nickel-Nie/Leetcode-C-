//
// Created by 聂伟豪 on 2022/11/18.
//
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;

    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        vector<ll> table(n, 0);
        table[0] = 1;
        for (int i = 1; i < n; ++i) {
            table[i] = table[i-1] * 2 % MOD;
        }

        ll ans = 0;
        sort(nums.begin(), nums.end());

        for(int i=n-1; i>=0; i--){
            ans =  (ans + nums[i] * (table[i] - table[n-i-1]) % MOD) % MOD;
        }

        return int(ans);
    }
};