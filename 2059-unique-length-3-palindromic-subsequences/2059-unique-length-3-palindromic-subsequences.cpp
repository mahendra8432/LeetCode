class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<string, int> map1;
        int first[26], last[26];
        int n = s.length();

        // initialize first and last occurrence arrays
        for (int i = 0; i < 26; i++) {
            first[i] = -1;
            last[i] = -1;
        }

        // record the first and last positions of each character
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i; // first occurrence f
            }
            last[s[i] - 'a'] = i; // last occurrence
        }

        // iterate over all characters in the alphabet
        for (int ch = 0; ch < 26; ch++) {
            if (first[ch] != -1 && last[ch] > first[ch] + 1) {
                bool middle[26] = {false}; // track unique middle characters
                for (int i = first[ch] + 1; i < last[ch]; i++) {
                    middle[s[i] - 'a'] = true;
                }
                for (int i = 0; i < 26; i++) {
                    if (middle[i]) {
                        string p = "";
                        p += (char)(ch + 'a'); 
                        p += (char)(i + 'a'); 
                        p += (char)(ch + 'a'); 
                        map1[p]++;
                    }
                }
            }
        }

        return map1.size();
    }
};
