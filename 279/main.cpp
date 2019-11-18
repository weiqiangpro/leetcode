/**
*Author: weiqiang
*Time: 2019/11/10 16:38
*/
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int a[n+1];
        for (int i = 0; i <=n ; i++) {
            a[i]=i;
        }
        for (int i = 1; i*i <=n ; ++i) {
            a[i*i]=1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j*j < i; j++) {
                a[i]= min(a[i],a[i-j*j]+1);
            }
        }
        return a[n];
    }
};
int main(){
    Solution s;
    cout<<s.numSquares(12);
    return 0;
}