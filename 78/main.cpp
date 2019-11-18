/**
*Author: weiqiang
*Time: 2019/11/11 11:27
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> vs;
private:
    void subsets(vector<int> &nums, int k, int index, vector<int> v) {
      int  n=nums.size();
        if (k == v.size()) {
            vs.push_back(v);
            return;
        }
        for (int i = index; i <= n - (k - v.size()); ++i) {
            v.push_back(nums[i]);
            subsets(nums, k, i + 1, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> a;
        for (int i = 0; i < nums.size(); ++i) {
            subsets(nums,i,0,a);
        }
        return vs;
    }
};
