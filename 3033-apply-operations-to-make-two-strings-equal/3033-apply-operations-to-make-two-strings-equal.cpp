int dp[2][2][501];

class Solution {
    
    string s1, s2;
    int n, far_cost;
    
    int MinOperations (int ind , int nxt_flip, int far_flip) {
        if (ind == n) {
            if (nxt_flip == 0 && (far_flip % 2) == 0) return 0;
            return 1e9;
        }
        
        int &ans = dp[nxt_flip][far_flip][ind];
        if (ans != -1) return ans;
        
        ans = 1e9;
        bool flip_required;
        
        if (nxt_flip)
            flip_required = (s1[ind] == s2[ind]);
        else 
            flip_required = (s1[ind] != s2[ind]);
        
        if (!flip_required) {
            ans = min (ans, MinOperations(ind+1, 0, far_flip));
            // ans = min (ans, 1 + (far_flip? far_cost:0) + MinOperations(ind+1, 1, far_flip^1));
        }
        else {
            ans = min (ans, (far_flip? far_cost:0) + MinOperations(ind+1, 0, far_flip^1));
            ans = min (ans, 1 + MinOperations(ind+1, 1, far_flip));
        }
        return ans;
    }
    
public:
    int minOperations(string s_1, string s_2, int x) {
        s1 = s_1, s2 = s_2, far_cost = x;
        n = s1.length();
        memset(dp, -1, sizeof(dp));
        
        int ans = MinOperations(0, 0, 0);
        if (ans == 1e9) ans = -1;
        return ans;
    }
};