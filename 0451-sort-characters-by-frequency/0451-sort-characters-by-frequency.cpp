class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        string ans="";
        vector<pair<int,char>>vec;
        int count=1,i;
        sort(s.begin(),s.end());
        for( i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                vec.push_back({count,s[i]});
                count=1;
            }
            else count++; 
        }
        vec.push_back({count,s[i]});
     sort(vec.begin(), vec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        return a.first > b.first; // Compare based on the integer value
    });
        for(auto &p:vec){
            for(int i=0;i<p.first;i++) ans+=p.second;
        }
        return ans;
    }
};