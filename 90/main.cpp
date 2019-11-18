/**
*Author: weiqiang
*Time: 2019/11/11 14:15
*/
/**
*Author: weiqiang
*Time: 2019/11/11 11:27
*/
#include <iostream>
#include <vector>
#include <algorithm>

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
        for (int i = index; i <= n - (k - v.size()); i++) {
            if (i > index && nums[i]==nums[i-1])
                continue;
            v.push_back(nums[i]);
            subsets(nums, k, i + 1, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(),nums.end());
        vector<int> a;
        for (int i = 0; i <= nums.size(); ++i) {
            a.clear();
            subsets(nums,i,0,a);
        }
        return vs;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(4);
    a.push_back(1);
    a.push_back(4);
    a.push_back(4);

    s.subsetsWithDup(a);
}