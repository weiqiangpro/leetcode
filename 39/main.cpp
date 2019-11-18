/**
*Author: weiqiang
*Time: 2019/11/11 14:50
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    vector<vector<int>> vs;
private:
    void combinationSum(vector<int>& candidates, int target,int index,vector<int> v){
        if (target==0){
            vs.push_back(v);
            return;
        }
        int n = candidates.size();
        for (int i = index; i < n && candidates[i]<=target; i++) {
            target-=candidates[i];
            v.push_back(candidates[i]);
            combinationSum(candidates,target,i,v);
            target+=candidates[i];
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,target,0,a);
        return vs;
    }
};
int main(){
    vector<int> a;
    a.push_back(8);
    a.push_back(7);
    a.push_back(4);
    Solution s;
    s.combinationSum(a,11);
}