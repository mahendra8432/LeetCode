class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size(),m=pref.length(),count=0;
        for(int i=0;i<n;i++){
            if(pref==words[i].substr(0,m)) count++;
        }
        return count;
    }
};