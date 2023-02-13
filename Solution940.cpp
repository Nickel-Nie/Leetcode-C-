////
//// Created by 聂伟豪 on 2022/10/14.
////
//#include<string>
//
//using namespace std;
//
//class Solution {
//public:
//    int distinctSubseqII(string s) {
//        int n = s.size();
//        int dp[n];
//        bool visit[26];
//        memset(dp, 0, n * sizeof(int));
//        memset(visit, false, 26 * sizeof(bool));
//
//        //对dp数组进行初始化
//        for (int i = 0; i < n; ++i) {
//            if (visit[s[i]-'a']){
//                dp[i] = 0;
//            } else {
//                visit[s[i]-'a'] = true;
//                dp[i] = 1;
//            }
//        }
//
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                dp[i] += dp[j];
//            }
//        }
//
//        //计算答案
//        int ans = 0;
//        memset(visit, false, 26 * sizeof(bool));
//        for (int i = n-1; i > 0; --i) {
//            if (!visit[s[i] - 'a']){
//                visit[s[i]-'a'] = true;
//                ans += dp[i];
//            }
//        }
//        return ans;
//    }
//};