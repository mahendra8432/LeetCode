class Solution {
public:
    void solve(vector<int> &freq,int &ans){
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                freq[i]--;
                ans++;
                solve(freq,ans);
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++)freq[tiles[i]-'A']++;
        int ans =0;
        solve(freq,ans);
        return ans;
    }
};