class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        vector<int> v(26,0);
        for (char &c: s) v[c-'a']++;
        int ct = 0;
        for (int i = 0; i < 26; i++){
            if (v[i]&1) ct++;
        }
        if (ct > k) return false;
        return true;
    }
};