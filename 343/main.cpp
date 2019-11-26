#include <iostream>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        int a[n+1],ok;
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for (int i = 3; i <= n; ++i) {
            ok = 0;
            for (int j = 1; j <= i/2; ++j) {
                ok = max(ok,max(a[j],j)*max(i-j,a[i-j]));
            }
            a[i]=ok;
        }
        return a[n];
    }
};

int main(){
    Solution s;
    cout<<s.integerBreak(10);
}