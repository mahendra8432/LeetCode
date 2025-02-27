class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i = 0, flag = 1;
        long long ans = 0;
        
        while (i < n && s[i] == ' ') i++; // Skip leading spaces
        if (s[i] == '-') { flag = -1; i++; }
        else if (s[i] == '+') i++;

        for (; i < n; i++) {
            if (s[i] < '0' || s[i] > '9') break; // Stop at non-digit
            
            ans = ans * 10 + (s[i] - '0'); // Convert to integer
            
            // Overflow handling
            if (flag == 1 && ans > INT_MAX) return INT_MAX;
            if (flag == -1 && -ans < INT_MIN) return INT_MIN;
        }

        return flag * ans;
    }
};
