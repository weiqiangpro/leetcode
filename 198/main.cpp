/**
*Author: weiqiang
*Time: 2019/11/26 23:43
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) {
            return 0;
        }
        vector<int> v(nums.size(),-1);
        v[n-1]=nums[n-1];
        for (int i = n-2; i>=0; i--) {
            for (int j = i; j <n; j++) {
                v[i] = max(v[i],nums[j]+(j+2<n?v[j+2]:0));
            }
        }
        return v[0];
    }
};