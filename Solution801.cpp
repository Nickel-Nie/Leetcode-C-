////
//// Created by 聂伟豪 on 2022/10/10.
////
//
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    int minSwap(vector<int>& nums1, vector<int>& nums2) {
//
//    }
//};
//
////class Solution {
////public:
////    int minSwap(vector<int>& nums1, vector<int>& nums2) {
////        this->n = nums1.size();
////
////        //下标0的时候，不换
////        dfs(nums1, nums2, 1, 0);
////        //换
////        swap(nums1[0], nums2[0]);
////        dfs(nums1, nums2, 1, 1);
////        swap(nums1[0], nums2[0]);
////
////        return this->ans;
////    }
////private:
////    int ans = INT_MAX;
////    int n;
////
////    void dfs(vector<int>& nums1, vector<int>& nums2, int curIdx, int curTimes){
////        if (curIdx == n){
////            ans = min(curTimes, ans);
////            return;
////        }
////
////        if(nums1[curIdx] <= nums2[curIdx-1] || nums2[curIdx] <= nums1[curIdx-1]) {
////            //不能换
////            dfs(nums1, nums2, curIdx+1, curTimes);
////            return;
////        }
////        if (nums1[curIdx] <= nums1[curIdx-1] || nums2[curIdx] <= nums2[curIdx-1]){
////            //必须换
////            swap(nums1[curIdx], nums2[curIdx]);
////            dfs(nums1, nums2, curIdx+1, curTimes+1);
////            swap(nums1[curIdx], nums2[curIdx]);
////            return;
////        }
////        //其他情况，既可以换，也可以不换
////        dfs(nums1, nums2, curIdx+1, curTimes);
////        swap(nums1[curIdx], nums2[curIdx]);
////        dfs(nums1, nums2, curIdx+1, curTimes+1);
////        swap(nums1[curIdx], nums2[curIdx]);
////    }
////};