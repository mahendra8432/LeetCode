class Solution {
public:
    bool startsAndEndsWithVowel(const string& str) {
        if (str.empty()) {
            return false;
        }

        char first = tolower(str.front());
        char last = tolower(str.back());

        return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
               (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + startsAndEndsWithVowel(words[i]);
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return ans;
    }
};
