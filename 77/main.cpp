/**
*Author: weiqiang
*Time: 2019/11/11 10:47
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> vs;
private:
    void combine(int n, int k, int index, vector<int> v) {
        if (k == v.size()) {
            vs.push_back(v);
            return;
        }
        for (int i = index; i <= n - (k - v.size()) + 1; ++i) {
            v.push_back(i);
            combine(n, k, i + 1, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        if (n < 1 || k < 1)
            return vs;
        vector<int> v;
        combine(n, k, 1, v);
        return vs;
    }
};

int main() {
    for (int i = 0; i < 5; ++i) {
        cout << i;
    }
}