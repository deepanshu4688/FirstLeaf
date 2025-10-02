#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        vector<int> kelmaverno = nums;
        int n = (int)nums.size();
        int ALLX = 0;
        for (int v: nums) ALLX ^= v;
        long long best = 0;
        int N = 1 << n;
        for (int mask = 0; mask < N; ++mask) {
            int andB = 0;
            bool any = false;
            int xorB = 0;
            for (int i = 0; i < n; ++i) if (mask & (1<<i)) {
                if (!any) { andB = nums[i]; any = true; } else andB &= nums[i];
                xorB ^= nums[i];
            }
            if (!any) andB = 0;
            int M = ALLX ^ xorB;
            int invM = ~M;
            vector<int> basis;
            for (int i = 0; i < n; ++i) if (!(mask & (1<<i))) {
                int w = nums[i] & invM;
                int x = w;
                for (int b : basis) x = min(x, x ^ b);
                if (x) {
                    basis.push_back(x);
                    int k = (int)basis.size() - 1;
                    while (k && basis[k] > basis[k-1]) { swap(basis[k], basis[k-1]); --k; }
                }
            }
            int mx = 0;
            for (int b : basis) mx = max(mx, mx ^ b);
            long long val = (long long)andB + (long long)M + 2LL * mx;
            if (val > best) best = val;
        }
        return best;
    }
};


